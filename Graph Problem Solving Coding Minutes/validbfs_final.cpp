#include <bits/stdc++.h>
using namespace std;
#define LL long long
map<int,int> mp[200005];
int n, ind = 1, p[200005], x, y;
 
int valid_bfs2() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n-1; i++) {
        cin >> x >> y;
        mp[x][y]++, ++mp[y][x]; 
    }  
 
    for(int i = 0; i < n; i++) cin >> p[i];
 
    for(int i = 0; i < n; i++) while(mp[p[i]][p[ind]]) ind++;
 
    cout << (ind == n && p[0] == 1 ? "Yes" : "No");
}
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
        if (pos == nv && given[0]==1)
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
   cout<<g1.bfs(list)<<endl;
}