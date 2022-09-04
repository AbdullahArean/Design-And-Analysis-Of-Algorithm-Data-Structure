#include <bits/stdc++.h>
using namespace std;
vector<int> alpha;
class Graph
{
private:
    vector<pair<int, int>> *al;
    int nv;

    int *vis;
    int *prev;
    int *dis;

    int *dtime;
    int *ftime;
    int time;

public:
    Graph(int n)
    {
        this->nv = n;
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
    void printadjlist()
    {
        for (int i = 0; i < nv; i++)
        {
            cout << i << " : ";
            for (auto j : al[i])
            {
                cout << j.first << "  " << j.second;
            }
            cout << endl;
        }
    }
    void bfs(int source)
    {
        // Initialization of necessary Arrays
        dis = new int[nv + 1];
        prev = new int[nv + 1];
        vis = new int[nv + 1];

        // Insert Value
        for (int i = 0; i < nv; i++)
        {
            vis[i] = 0;        // 0 Not Visited // 1 Visited// 2 Finish visiting
            dis[i] = INT_MAX;  // Infinity
            prev[i] = INT_MIN; // minus infinity
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
                    prev[v.first] = u.second;
                    container.push({dis[v.first], v.first});
                }
            }
            vis[u.second] = 2;
        }
    }
    void shortest_distance_path_bfs(int source, int destination)
    {
        bfs(source);
        if (dis[source] == INT_MAX)
        {
            cout << "Not Reachable\n";
        }
        else
            cout << dis[destination] << ": ";

        // Path Print
        int p = destination;
        while (1)
        {
            if (p == prev[p])
            {
                cout << p << "\n";
                break;
            }
            cout << p << " ";
            p = prev[p];
        }
        // cout << endl;
    }
    void dfs()
    {
        // Initialization of necessary Arrays
        vis = new int[nv + 1];
        dtime = new int[nv + 1];
        ftime = new int[nv + 1];

        // Insert Value
        for (int i = 0; i < nv; i++)
        {
            vis[i] = 0; // 0 Not Visited // 1 Visited// 2 Finish visiting
            dtime[i] = INT_MAX;
            ftime[i] = INT_MAX;
        }
        int time = 0;
        for (int i = 0; i < nv; i++)
        {
            if (vis[i] == 0)
            {
                dfs_visit(i);
            }
        }
    }
    void dfs_visit(int u)
    {
        vis[u] = 1;
        dtime[u] = ++time;
        for (auto v : al[u])
        {
            if (vis[v.first] == 0)
            {
                dfs_visit(v.first);
            }
        }
        ftime[u] = ++time;
        vis[u] = 2;
    }
};

void solve()
{
    int i, j, n, m, a, b, temp;
    cin >> n;
    Graph g1 = Graph(n);
    for (int i = 0; i < n; i++)
    {
        cin>>temp;
        alpha.push_back(temp);
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        g1.addedge(a + 1, b + 1, 1);
    }
    g1.bfs(0);
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
