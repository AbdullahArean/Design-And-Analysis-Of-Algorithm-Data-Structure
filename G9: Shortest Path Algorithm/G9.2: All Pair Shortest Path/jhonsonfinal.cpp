#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
const long long INF = (1LL << 60) - 666;
//This Code Is working
class edge
{
public:
    int to;
    int wei;
    edge()
    {
        this->to = -1;
        this->wei = -1;
    }
    edge(int a, int b)
    {
        this->to = a;
        this->wei = b;
    }
};
class Heap
{
    edge *arr;
    int capacity;  // Capacity
    int heap_size; // Current Number of Node
    int get_parent(int i)
    {
        return (i - 1) / 2;
    }
    int left_child(int i)
    {
        return 2 * i + 1;
    }
    int right_child(int i)
    {
        return 2 * i + 2;
    }
    void swap(edge *x, edge *y)
    {
        edge temp = *x;
        *x = *y;
        *y = temp;
    }

public:
    Heap(int cap)
    {
        this->capacity = cap;
        heap_size = 0;
        arr = new edge[cap];
    }
    edge top_heap()
    {
        return arr[0];
    }
    edge pop_heap()
    {
        if (heap_size <= 0)
            return {-1, -1};
        if (heap_size == 1)
        {
            heap_size--;
            return arr[0];
        }
        edge root = arr[0];
        arr[0] = arr[heap_size - 1];
        heap_size--;
        Minheeapify(0);
        return root;
    }
    void Minheeapify(int i)
    {
        int l = left_child(i);
        int r = right_child(i);

        int smallest = i;
        if (l < heap_size && arr[l].wei < arr[i].wei)
        {
            smallest = l;
        }
        if (r < heap_size && arr[r].wei < arr[smallest].wei)
        {
            smallest = r;
        }
        if (smallest != i)
        {
            swap(&arr[i], &arr[smallest]);
            Minheeapify(smallest);
        }
    }
    void push_heap(edge given)
    {
        if (heap_size == capacity)
        {
            cout << "\nOverflow: Could not insertKey\n";
            return;
        }
        heap_size++;
        int i = heap_size - 1;
        arr[i] = given;
        while (i != 0 && arr[get_parent(i)].wei > arr[i].wei)
        {
            swap(&arr[i], &arr[get_parent(i)]);
            i = get_parent(i);
        }
    }
    void printheap()
    {
        for (int i = 0; i < heap_size; i++)
        {
            cout << arr[i].wei << endl;
        }
        cout << endl;
    }
    bool isempty()
    {
        if (heap_size <= 0)
            return true;
        else
            return false;
    }
};
class Edge
{
public:
    int u, v;
    long long w;
    Edge(int u, int v, long long w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
class Graph
{
public:
    vector<Edge> E;

    int n;
    long long int ar[MAX][MAX];
     vector<long long> dis;
    Graph(int n)
    {
        this->n = n;
    }
    void addedge(int x, int y, int w)
    {
        Edge temp = Edge(x, y, w);
        E.push_back(temp);
    }
    void relaxation(long long &a, long long &b, long long &c ){
        

    }
    bool bellmanford( int src)
    {
        dis.assign(n + 1, INF);
        dis[src] = 0;
        for (int i = 0; i <= n; i++)
        {
            int flag = 0;
            for (auto e : E)
            {
                if ((dis[e.u] + e.w) < dis[e.v])
                {
                    flag = 1; //Negative Cycle exists and More Relaxation Possible 
                    dis[e.v] = dis[e.u] + e.w;
                }
            }
            cout<<"Value of h"<<endl;
            for(int i=0; i<=n; i++){
                cout<<i<<"=>"<<dis[i]<<endl;;
            }
            if (flag == 0)
                return true;
        }
        return false;
    }
    void dijkastra_bin_heap(int source)
    {
        for (int i = 1; i <= n; i++)
        {
            dis[i] = INF;
        }
        vector<pair<int, long long>> adjlist[n + 1];
        for (auto e : E)
        {
            adjlist[e.u].push_back(make_pair(e.v, e.w));
        }
        dis[source] = 0;
        Heap pq =  Heap(MAX);
        pq.push_heap(edge(source,0));
        while (!pq.isempty())
        {
            int u = pq.pop_heap().to;
            for (auto x : adjlist[u])
            {

                int v = x.first;
                int weight = x.second;
                if (dis[v] > dis[u] + weight)
                {
                    dis[v] = dis[u] + weight;
                    pq.push_heap(edge(v,dis[v]));
                }
            }
        }
    }
   
    void johnson()
    {
        //Created a Second Graph With More vertex than This One. In this case that is 0
        vector<long long> g2_edgelist(n + 1, INF);
        //Added Edges weight of zero from that particular vertex (0)
        for (int i = 1; i <= n; i++)
            E.push_back(Edge(0, i, 0));

        if(bellmanford(0)==false){
            cout<<"Negative Cycle\n";

        }
        else{
            for (int i = 1; i <= n; i++)
            E.pop_back();

        for (int i = 1; i <= n; i++)
        {
            dijkastra_bin_heap(i);
            vector<long long> dis2= this->dis;
            for (int j = 1; j <= n; j++)
            {
                ar[i][j] = dis2[j];
            }
        }

        }
    }
};

int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int v, e, a, b, c;
    cin >> v >> e;
    Graph g1 = Graph(v);
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> c;
        g1.addedge(a+1, b+1, c);
    }
    g1.johnson();
    cout << "Number of Vertices: " << v << "\nNumber of Edges: " << e << endl;
    for (int i = 1; i <= g1.n; i++)
    {
        for (int j = 1; j <= g1.n; j++)
        {
            printf("%d %d = %lld\n", i-1, j-1, g1.ar[i][j]);
        }
    }
}
