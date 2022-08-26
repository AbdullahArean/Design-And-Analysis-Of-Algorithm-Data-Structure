#include <bits/stdc++.h>
using namespace std;
class Graph
{
private:
    vector<int> *al;
    int nv;
    int *vis;
    int *prev;
    int *dis;

public:
    Graph(int n)
    {
        this->nv = n;
        al = new vector<int>[nv];
    }
    void addedge(int u, int v, bool directed = 0)
    {
        al[u].push_back(v);
        if (!directed)
        {
            al[v].push_back(u);
        }
    }
    void printadjlist(){
        for(int i=0;i<nv; i++){
            cout<<i<<" : ";
            for(auto j: al[i]){
                cout<<j<<"  ";
            }
            cout<<endl;
        }

    }
    void bfs(int source)
    {
        //Initialization of necessary Arrays
        dis  = new int[nv];
        prev = new int[nv];
        vis  = new int[nv];

        //Insert Value
        for (int i = 0; i < nv; i++)
        {
            vis[i]  =  0;        // 0 Not Visited // 1 Visited// 2 Finish visiting
            dis[i]  =  INT_MAX;  //Infinity
            prev[i] =  INT_MIN;  //minus infinity
        }
        queue<int> container;

        vis[source] = 1;
        dis[source] = 0;
        prev[source] = source;

        container.push(source);

        while (!container.empty())
        {
            int u = container.front();
            container.pop();

            //cout<<u<<endl;
            for (auto v : al[u])
            {
                if (vis[v] == 0)
                {
                    vis[v] = 1;
                    dis[v] = dis[u] + 1;
                    prev[v] = u;
                    container.push(v);
                }
            }
            vis[u]=2;
        }
    }
    void shortest_distance_path_bfs(int source, int destination){
        bfs(source);
        if(dis[source]==INT_MAX){
            cout<<"Not Reachable\n";
        }
        else cout<<dis[destination]<<"\n";

        //Path Print
        int p=destination;
        while (1)
            {
                if (p == prev[p])
                {
                    cout << p << endl;
                    break;
                }
                cout << p << " ";
                p = prev[p];
                
            }
        cout << endl;
        
    }
};

int main()
{
    freopen("inp.txt","r", stdin);
    freopen("out.txt","w", stdout);
    int ve,ed, v,u;
    cin>>ve>>ed;
    Graph g1= Graph(ve);
    while(ed--){
        cin>>u>>v;
        g1.addedge(u,v);
    }
    vector<int> list[ve];
    for(int i=0; i<ve; i++){
        scanf("%d",&list[i]);
    }
   g1.shortest_distance_path_bfs(0,1);
    
}
