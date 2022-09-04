#include <bits/stdc++.h>
using namespace std;
vector<int> alpha;
long long int ans = 0;
class Graph
{
private:
    vector<pair<int, int>> *al;
    int nver;

    int *vis;
    int *prev;
    int *dis;

    int *dtime;
    int *ftime;
    int time;

public:
    Graph(int n)
    {
        this->nver = n;
        al = new vector<pair<int, int>>[n + 1];
    }
    void addedge(int u, int v, int w = 1, bool directed = 0)
    {
        al[u].push_back({v, w});
        if (!directed)
        {
            al[v].push_back({u, w});
        }
    }

    void bfs(int source)
    {
        // Initialization of necessary Arrays
        dis = new int[nver + 1];
        vis = new int[nver + 1];

        // Insert Value
        for (int i = 0; i < nver; i++)
        {
            vis[i] = 0;        // 0 Not Visited // 1 Visited// 2 Finish visiting
            dis[i] = INT_MAX;  // Infinity
        }
        queue<pair<int, int>> container;

        vis[source] = 1;
        dis[source] = 0;
        prev[source] = source;

        container.push({0, source});

        while (!container.empty())
        {
            auto u = container.front();
            container.pop();

            // cout<<u<<endl;
            for (auto v : al[u.first])
            {
                if (vis[v.first] == 0)
                {
                    vis[v.first] = 1;
                    dis[v.first] = dis[u.second] + 1;
                    container.push({dis[v.first], v.first});
                }
            }
            vis[u.second] = 2;
        }
    }
};

void solve()
{
    int i, j, n, m, a, b, temp;
    cin >> n;
    Graph g1 = Graph(n);
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        alpha.push_back(temp);
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        g1.addedge(a, b, 1);
    }
    g1.bfs(0);
    int ans;
    for (int i = 1; i <= n i++)
    {
        bfs(i);
        ans += ()
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    freopen("inp.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
