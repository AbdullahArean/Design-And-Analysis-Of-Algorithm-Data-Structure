#include <bits/stdc++.h>
using namespace std;
#define MAX 100000

class Graph
{
    vector<pair<int, int>> adjlist[MAX];
    int nver;
    int dis[MAX];
    int prev[MAX];

public:
    Graph(int n)
    {
        this->nver = n;
    }
    void addedge(int x, int y, int w)
    {
        adjlist[x].push_back({y, w});
        adjlist[y].push_back({x, w});
    }
    void djkastra(int source)
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
        for (int i = 0; i < nver; i++)
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
};

int main()
{
    freopen("inputdj.txt", "r", stdin);
    freopen("output_prim.txt", "w", stdout);
    int v, e, a, b, c;
    cin >> v >> e;
    Graph g1 = Graph(v);
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> c;
        g1.addedge(a, b, c);
    }
    cout<<"Number of Vertices: "<<v<<"\nNumber of Edges: "<<e<<endl;
    g1.djkastra(0);
}