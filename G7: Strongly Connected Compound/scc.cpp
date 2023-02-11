#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int MAXN = 1e3;
vector<pair<int, int>> Tree_edge;
vector<pair<int, int>> Back_edge;
class Graph
{
    int V;
    vector<int> adj[MAXN];
    int dis[MAXN], fin[MAXN], pre[MAXN], vis[MAXN], low[MAXN];
    ll time;

private:
    void DFS_visit(int vertex, int parent = -1)
    {
        vis[vertex] = 1;
        time = time + 1;
        dis[vertex] = time;
        low[vertex] = dis[vertex];
        for (auto it = adj[vertex].begin(); it != adj[vertex].end(); it++)
        {
            int child = *it;
            //cout << vertex << " " << child << endl;
            if (vis[child] == 0)
            {
                // cout << "Tree Edge: " << vertex << " " << child << endl;
                Tree_edge.push_back(make_pair(vertex, child));
                DFS_visit(child, vertex);
                low[vertex] = min(low[vertex], low[child]);
            }
            // u->w
            else if (dis[vertex] > dis[child])
            {
                // cout << "Back Edge: " << vertex << " " << child << endl;
                Back_edge.push_back(make_pair(vertex, child));
                low[vertex] = min(low[vertex], dis[child]);
            }
        }
        vis[vertex] = 2;
        time = time + 1;
        fin[vertex] = time;
    }
    void DFS()
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
                DFS_visit(i);
            }
        }
    }
    void dfs2_print_sccs(int v, bool visited[])
    {
        visited[v] = true;
        cout << v << " ";
        for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
            if (!visited[*i])
                dfs2_print_sccs(*i, visited);
    }
    Graph getTranspose()
    {
        Graph g(V);
        for (int v = 0; v < V; v++)
        {
            for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
            {
                g.adj[*i].push_back(v);
            }
        }
        return g;
    }
    void dfs1_topo_order(int v, bool visited[], stack<int> &topocontainer)
    {
        visited[v] = true;
        for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
            if (!visited[*i])
                dfs1_topo_order(*i, visited, topocontainer);

        topocontainer.push(v);
    }

public:
    Graph(int V)
    {
        this->V = V;
    };
    void add_new_edge(int v, int w)
    {
        adj[v].push_back(w);
        // adj[w].push_back(v);
    }
    void PrintSCCs()
    {
        stack<int> topocontainer;
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;
        for (int i = 0; i < V; i++)
            if (visited[i] == false)
                dfs1_topo_order(i, visited, topocontainer);

        Graph gr = getTranspose();
        for (int i = 0; i < V; i++)
            visited[i] = false;

        cout << "Strongly Connceted Components:\n";
        while (topocontainer.empty() == false)
        {
            int v = topocontainer.top();
            topocontainer.pop();
            if (visited[v] == false)
            {
                gr.dfs2_print_sccs(v, visited);
                cout << endl;
            }
        }
    }
    void PrintTreeEdges()
    {

        Tree_edge.clear();
        cout << "Tree Edges:" << endl;
        DFS();

        for (auto i : Tree_edge)
        {
            cout << i.first << " " << i.second << endl;
        }
    }
    void PrintBackEdges()
    {

        Back_edge.clear();
        DFS();
        cout << "Back Edges:" << endl;
        for (auto i : Back_edge)
        {
            cout << i.first << " " << i.second << endl;
        }
    }
    void PrintLows()
    {
        cout<<"Low Values: "<<endl;
        DFS();
        for (int i = 0; i < V; i++)
        {
            cout << i << " Low :" << low[i] << endl;
        }
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
    graph1.PrintTreeEdges();
    graph1.PrintBackEdges();
    graph1.PrintLows();
    graph1.PrintSCCs();
}