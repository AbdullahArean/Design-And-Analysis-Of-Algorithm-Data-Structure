#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

class Graph
{
    vector<pair<int, int>> adjlist[MAX];
    int nver;
    int dis[MAX];
    int prev[MAX];
    int pare[MAX][MAX];
    int dist[MAX][MAX];

public:
    Graph(int n)
    {
        this->nver = n;
    }
    void addedge(int x, int y, int w)
    {
        adjlist[x].push_back({y, w});
        // adjlist[y].push_back({x, w});
    }
    void dijkastra(int source)
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
    void floydwarshall()
    {
        int i, j, k;
        for (i = 0; i < nver; i++)
        {
            for (j = 0; j < nver; j++)
            {
                dist[i][j] = INT_MAX;
                pare[i][j] = -1;
                if(i==j) {dist[i][j]=0; pare[i][j]=-2;}
            }
        }
        for (i = 0; i < nver; i++)
            for (auto j : adjlist[i])
            {
                dist[i][j.first] = j.second;
                pare[i][j.first]=i;
            }

        for (k = 0; k < nver; k++)
        {
            for (i = 0; i < nver; i++)
            {
                for (j = 0; j < nver; j++)
                {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        pare[i][j] = k;
                    }
                }
            }
        }
        for (i = 0; i < nver; i++)
            {
                for (j = 0; j < nver; j++)
                {
                    cout<<pare[i][j]+1<<" ";
                }
                cout<<"\n";
            }

    }
    void floydwarshall2()
    {
        

    }
    void printpath(int source, int destination)
    {
        if (pare[source][destination] == -1)
        {
            cout << "No Path Exists\n";
            return;
        }
        if (pare[source][destination] == destination)
        {
            cout << destination << endl;
            return;
        }
       printpath(source, pare[source][destination]);
       printpath(pare[source][destination], destination);
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
    g1.dijkastra(0);
    cout<<g1.bellmanford(0)<<endl;
    g1.floydwarshall();
    g1.printpath(0, 3);
}