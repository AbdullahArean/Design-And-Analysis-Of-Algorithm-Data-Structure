#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
#define INF 100000

class Graph
{
public:
    vector<pair<int, int>> adjlist[MAX];
    int nver;
    int dis[MAX];
    int prev[MAX];
    int pare[MAX][MAX];
    int dist[MAX][MAX];
    Graph(int n)
    {
        this->nver = n;
    }
    void addedge(int x, int y, int w)
    {
        adjlist[x].push_back({y, w});
        // adjlist[y].push_back({x, w});
    }
    void dijkastra_STL(int source)
    {
        for (int i = 0; i < nver; i++)
        {
            dis[i] = INT_MAX;
            prev[i] = INT_MIN;
        }
        dis[source] = 0;
        prev[source] = source;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, source});
        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            for (auto x : adjlist[u])
            {

                int v = x.first;
                int weight = x.second;
                if (dis[v] > dis[u] + weight)
                {
                    dis[v] = dis[u] + weight;
                    prev[v] = u;
                    pq.push({dis[v], v});
                }
            }
        }
        // Print The shortest Distance Stored in dist[]
        printf("Vertex Distance From Source\n");
        for (int i = 0; i < nver && dis[i] != INT_MAX; i++)
        {
            printf("%d \t \t %d\nPath(Weigth of Edge): ", i, dis[i]);
            int p = i;
            int diff;
            while (1)
            {
                if (p == prev[p])
                {
                    cout << p << endl;
                    break;
                }
                diff = dis[p] - dis[prev[p]];
                cout << p << "<-(" << diff << ")<-";
                p = prev[p];
            }
            cout << endl;
        }
    }
    bool bellmanford(int source)
    {
        for (int i = 0; i < nver; i++)
        {
            dis[i] = INT_MAX;
        }
        dis[source] = 0;
        for (int i = 0; i < nver; i++)
        {
            for (auto j : adjlist[i])
            {
                if (dis[i] != INT_MAX and dis[i] + j.second < dis[j.first])
                {
                    dis[j.first] = dis[i] + j.second;
                }
            }
        }
        for (int i = 0; i < nver; i++)
        {
            for (auto j : adjlist[i])
            {
                if (dis[i] != INT_MAX and dis[i] + j.second < dis[j.first])
                {
                    return false;
                }
            }
        }
        return true;
    }
    void jhonsons()
    {
        Graph g2 = Graph(nver + 1);
        vector<int> h;
        for (int i = 0; i < nver; i++)
        {
            for (auto j : adjlist[i])
            {
                g2.addedge(i, j.first, j.second);
            }
            g2.addedge(i, nver, 0);
            if (g2.bellmanford(nver) == false)
            {
                cout << "Graph Contain Negative Cycle" << endl;
                return;
            }
            else
            {
                h.assign(nver + 1, 0);
                for (int i = 0; i < nver + 1; i++)
                {
                    h[i] = g2.dis[i];
                    for (int i = 0; i < nver+1; i++)
                    {
                        for (auto j : g2.adjlist[i])
                        {
                            j.second = j.second +h[i]-h[j.first];
                        }
                    }
                }
            }
        }
    }
    };

    int main()
    {
        freopen("inputdj.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        int v, e, a, b, c;
        cin >> v >> e;
        Graph g1 = Graph(v);
        for (int i = 0; i < e; i++)
        {
            cin >> a >> b >> c;
            g1.addedge(a, b, c);
        }
        cout << "Number of Vertices: " << v << "\nNumber of Edges: " << e << endl;
    }