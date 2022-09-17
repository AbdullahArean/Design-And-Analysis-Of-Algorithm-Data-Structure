#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int MAXN = 1e3;
class Graph
{
    int V;
    vector<int> l[MAXN];
    vector<pair<int, int>> br;
    int dis[MAXN], fin[MAXN], pre[MAXN], vis[MAXN], low[MAXN], ap[MAXN];
    ll time;

public:
    Graph(int V)
    {
        this->V = V;
    };
    void add_new_edge(int v, int w)
    {
        l[v].push_back(w);
        l[w].push_back(v);
    }
    int dfsAP(int u, int p)
    {
        int children = 0;
        low[u] = dis[u] = ++time;
        for (int &v : l[u])
        {
            if (v == p)
                continue; // we don't want to go back through the same path.
                          // if we go back is because we found another way back
            if (!dis[v])
            { // if V has not been discovered before
                children++;
                dfsAP(v, u);          // recursive DFS call
                if (dis[u] <= low[v]) // condition #1
                    ap[u] = 1;
                if (dis[u] < low[v]) // condition #1
                   br.push_back({u,v});
                low[u] = min(low[u], low[v]); // low[v] might be an ancestor of u
            }
            else                              // if v was already discovered means that we found an ancestor
                low[u] = min(low[u], dis[v]); // finds the ancestor with the least discovery time
        }
        return children;
    }

    void AP()
    {
        for (int i = 0; i < V; i++)
        {
            dis[i] = INT_MAX;
            low[i] = INT_MAX;
        }
        time = 0;
        for (int u = 0; u < V; u++)
            if (!dis[u])
                ap[u] = dfsAP(u, u) > 1; // condition #2
        for (int u = 0; u < V; u++){
            if(ap[u]) cout<<u<<endl;
        }
        for (auto i : br)
        {
            cout << "bridge: " << i.first << " " << i.second << endl;
        }
    }
};

int main()
{
    freopen("input1.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n_nodes, n_edges, u, v;
    scanf("%d", &n_nodes);
    scanf("%d", &n_edges);
    Graph graph1(n_nodes);
    while (n_edges--)
    {
        scanf("%d %d", &u, &v);
        graph1.add_new_edge(u, v);
    }
    graph1.AP();
}