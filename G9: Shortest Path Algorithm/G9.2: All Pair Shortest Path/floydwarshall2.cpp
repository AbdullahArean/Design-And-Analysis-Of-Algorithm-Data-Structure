#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
#define INF 100000

class Graph
{
    vector<pair<int, int>> adjlist[MAX];
    int nver;
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
    void floydwarshall()
    {
        int i, j, k;
        for (i = 0; i < nver; i++)
        {
            for (j = 0; j < nver; j++)
            {
                dist[i][j] = INF;
                pare[i][j] = -1;
            }
        }
        for (i = 0; i < nver; i++)
            for (auto j : adjlist[i])
            {
                dist[i][j.first] = j.second;
                pare[i][j.first] = i;
            }

        for (k = 0; k < nver; k++)
        {
            for (i = 0; i < nver; i++)
            {
                for (j = 0; j < nver; j++)
                {
                    if (dist[i][j] > dist[i][k] + dist[k][j])
                        pare[i][j] = k;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        for (i = 0; i < nver; i++)
        {
            for (j = 0; j < nver; j++)
            {
                cout << i << " "
                     << " " << j << " " << dist[i][j] << "," << pare[i][j] << "\n";
            }
        }
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
        // printpath(source, pare[source][destination]);
        // printpath(pare[source][destination], destination);
        return;
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
    g1.floydwarshall();
    // g1.printpath(0, 3);
}