#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int MAXN = 1e3;
class Graph
{
    int V;
    vector<int> adj[MAXN];
    vector<pair<int, int>> br;
    int dis[MAXN], fin[MAXN], pre[MAXN], vis[MAXN], low[MAXN], ap[MAXN];
    ll time;

private:
    int DFS_visit(int vertex, int parent)
    {
        int children = 0;

        vis[vertex] = 1;
        time = time + 1;
        dis[vertex] = time;

        low[vertex] = dis[vertex];

        for (auto it : adj[vertex])
        {
            int child = it;
            if (vertex == child)
                continue;
            if (vis[child] == 0)
            {
                children++;
                DFS_visit(child, vertex);
                // Articulation Point Get
                if (dis[vertex] <= low[child])
                    ap[vertex] = 1;
                if (dis[vertex] < low[child])
                    br.push_back({vertex, child});

                // Tree Edge Means Min(lv, lchild)
                low[vertex] =
                    min(low[vertex], low[child]);
            }
            else
            {
                // Back Edge Means Min(lv, dischild)
                low[vertex] =
                    min(low[vertex], dis[child]);
            }
        }
        vis[vertex] = 2;
        time = time + 1;
        fin[vertex] = time;
        return children;
    }
    void Articulation_Point()
    {
        for (int i = 0; i < V; i++)
        {
            vis[i] = 0;
            dis[i] = INT_MIN;
            fin[i] = INT_MIN;
            low[i] = INT_MAX;
            pre[i] = -1;
        }
        time = 0;
        for (int i = 0; i < V; i++)
        {
            if (vis[i] == 0)
            {
                ap[i] = DFS_visit(i, i) > 1;
            }
        }
        for (int i = 0; i < V; i++)
        {
            if(ap[i]==1)
            cout << i <<endl;
        }
        for (auto i : br)
        {
            cout << "bridge: " << i.first << " " << i.second << endl;
        }
    }

public:
    Graph(int V)
    {
        this->V = V;
    };
    void add_new_edge(int v, int w)
    {
        adj[v].push_back(w);
    }
    void PrintLows()
    {
        //cout << "Low Values: " << endl;
        Articulation_Point();
        for (int i = 0; i < V; i++)
        {
            cout << i << " Low : " << low[i]<<  endl;
        }
        // for (auto i : br)
        // {
        //     cout << "bridge: " << i.first << " " << i.second << endl;
        // }
    }
};

int main()
{
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
    int n_nodes, n_edges, u, v;
    scanf("%d", &n_nodes);
    scanf("%d", &n_edges);
    Graph graph1(n_nodes);
    while (n_edges--)
    {
        scanf("%d %d", &u, &v);
        graph1.add_new_edge(u, v);
    }
    graph1.PrintLows();
}