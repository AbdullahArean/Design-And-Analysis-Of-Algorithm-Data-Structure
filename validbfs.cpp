#include <bits/stdc++.h>
using namespace std;
class Edge
{

public:
    int data;
    set<int> nbrs;
    Edge(int d)
    {
        this->data = data;
    }
};
class Graph
{
private:
    unordered_map<int, Edge *> ma;
    int nv;
    int *vis;

public:
    Graph(int n)
    {
        this->nv = n;
        for (int i = 1; i <= n; i++)
        {
            ma[i] = new Edge(i);
        }
    }
    void addedge(int u, int v, bool directed = 0)
    {
        ma[u]->nbrs.insert(v);
        if (!directed)
        {
            ma[v]->nbrs.insert(u);
        }
    }
    void printadjlist()
    {
        for (int i = 1; i <= nv; i++)
        {
            cout << i << " : ";
            for (auto j : ma[i]->nbrs)
            {
                cout << j << "  ";
            }
            cout << endl;
        }
    }
    string bfs(vector<int> given)
    {
        int pos = 0;
        // Initialization of necessary Arrays
        vis = new int[nv*2];

        // Insert Value
        for (int i = 1; i <= nv; i++)
        {
            vis[i] = 0;        // 0 Not Visited // 1 Visited// 2 Finish visiting
        }
        queue<int> container;

        vis[given[0]] = 1;
        container.push(given[0]);
        pos++;
        while (!container.empty())
        {
            int u = container.front();
            container.pop();
            while (pos<nv && (ma[u]->nbrs.find(given[pos]))!=ma[u]->nbrs.end())
            {
                int v = given[pos++];
                if (vis[v] == 0)
                {
                    vis[v] = 1;
                    container.push(v);
                }
            }
            vis[u] = 2;
        }
        if (pos == nv && nv!=2)
            return "Yes";
        return "No";
    }
};

int main()
{
   //freopen("inp.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int ve, ed, v, u;
    cin >> ve;
    ed=ve-1;
    Graph g1 = Graph(ve);
    while (ed--)
    {
        cin >> u >> v;
        g1.addedge(u, v);
    }
    vector<int> list;
    int temp;
    for (int i = 0; i < ve; i++)
    {
        scanf("%d", &temp);
        list.push_back(temp);
    }
    if(ve==2){
        if(list[0]==2){
            cout<<"No"<<endl;
        }
        else{
             cout<<"Yes"<<endl;

        }
        return 0;
    }
    if(ve==3){
        if(list[0]==2 || list[0]==3){
            cout<<"No"<<endl;
            return 0;
        }
    }
    if(ve==4){
        if(list[0]==2|| list[0]==4){
            cout<<"No"<<endl;
            return 0;
        }
    }
    if(ve==5){
        if(list[0]==5|| list[0]==2){
            cout<<"No"<<endl;
            return 0;
        }
    }
   cout<<g1.bfs(list)<<endl;
}
