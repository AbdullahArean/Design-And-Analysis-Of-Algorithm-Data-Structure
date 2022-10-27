#include <bits/stdc++.h>

using namespace std;
// int max_flow = 0;
int bfs(int source, int sink, int n, vector<int> &parent, vector<vector<int>> &graph)
{
    parent.assign(n, -1);
    parent[source] = -2;
    queue<pair<int, int>> q;
    q.push({source, INT_MAX});

    while (!q.empty())
    {
        int u = q.front().first;
        int cap = q.front().second;
        q.pop();

        for (int v = 0; v < n; v++)
        {
            if (u != v && graph[u][v] != 0 && parent[v] == -1)
            {
                parent[v] = u;
                int min_cap = min(cap, graph[u][v]);
                if (v == sink)
                    return min_cap;
                q.push({v, min_cap});
            }
        }
    }
    return 0;
}

// void dfs_visit(int min_cap, int u, int source, int sink, int n, vector<int> &parent, vector<int> &visited, vector<vector<int>> &graph)
// {
//     visited[u] = 1;
//     for (int v = 0; v < n; v++)
//     {
//         if (u != v && graph[u][v] != 0 && parent[v] == -1)
//         {
//             parent[v] = u;
//             min_cap = min(min_cap, graph[u][v]);
//             if (v == sink)
//             {
//                 max_flow += min_cap;
//                 int v = sink;

//                 while (v != source)
//                 {
//                     visited[v]=0;
//                     int u = parent[v];
//                     graph[u][v] -= min_cap; // forward edge
//                     graph[v][u] += min_cap; // back edge
//                     v = u;
//                 }
//             }
//             else
//                 dfs_visit(min_cap,v, source, sink, n, parent, visited, graph);
//         }
//     }
// }
// void dfs(int source, int sink, int n, vector<vector<int>> &graph)
// {
//     vector<int> parent(n, -1);
//     parent[source] = -2;
//     int min_cap = 0;
//     vector<int> visited(n, 0);
//     for (int i = 0; i < n; i++)
//     {
//         if (visited[i] == 0)
//         {
//             dfs_visit(min_cap, i, source, sink, n, parent, visited, graph);
//         }
//     }
// }
int Ford_Fulkerson(int source, int sink, int n, vector<vector<int>> &graph)
{
    vector<int> parent(n, -1);
    int max_flow = 0;
    int min_cap = 0;
    while (min_cap = bfs(source, sink, n, parent, graph))
    {
        max_flow += min_cap;
        int v = sink;

        while (v != source)
        {
            int u = parent[v];
            graph[u][v] -= min_cap; // forward edge
            graph[v][u] += min_cap; // back edge
            v = u;
        }
    }
    return max_flow;
}
int main()
{
    freopen("inp.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int V, e, a, b, c;
    cin >> V >> e;
    vector<vector<int>> graph(V, vector<int>(V, 0));
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> c;
        graph[a][b] = c;
    }
    cout << "Maximum Flow Using Ford Fulkerson Algo: " << Ford_Fulkerson(0, 5, V, graph) << endl;
    // dfs(0, 5, V, graph);
    // cout<<max_flow<<endl;
    return 0;
}