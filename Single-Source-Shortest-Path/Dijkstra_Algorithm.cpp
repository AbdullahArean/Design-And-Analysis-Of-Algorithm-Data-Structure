#include <bits/stdc++.h>
using namespace std;
#define MAX 100000


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





class Heap{
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
        for (int i = 0; i < nver && dis[i]!= INT_MAX; i++)
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
    void dijkastra_bin_heap(int source)
    {
        for (int i = 0; i < nver; i++)
        {
            dis[i] = INT_MAX;
            prev[i] = INT_MIN;
        }
        dis[source] = 0;
        prev[source] = source;
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
                    prev[v] = u;
                    pq.push_heap(edge(v,dis[v]));
                }
            }
        }
        // Print The shortest Distance Stored in dist[]
        printf("Vertex Distance From Source\n");
        for (int i = 0; i < nver && dis[i]!= INT_MAX; i++)
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
    void shortestpathdestination(int destination){
        Graph g2= Graph(nver);
        for(int i=0; i<nver ;i++){
            for(auto j: adjlist[i] ){
                g2.addedge(j.first, i, j.second);
            }
        }
        g2.dijkastra_bin_heap(destination);

    }
};

int main(){
	
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int v, e, a, b, c;
    cin >> v >> e;
    Graph g1 = Graph(v);
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> c;
        g1.addedge(a, b, c);
    }
    cout<<"Number of Vertices: "<<v<<"\nNumber of Edges: "<<e<<endl;
    g1.dijkastra_STL(3);
    g1.dijkastra_bin_heap(0);
    g1.shortestpathdestination(4);
}











































/*#include<bits/stdc++.h>
using namespace std;

#define V 6		//No of vertices

int selectMinVertex(vector<int>& value,vector<bool>& processed){
	int minimum = INT_MAX;
	int vertex;
	for(int i=0;i<V;++i){
		if(processed[i]==false && value[i]<minimum)
		{
			vertex = i;
			minimum = value[i];
		}
	}
	return vertex;
}

void dijkstra(int graph[V][V]){
	int parent[V];		//Stores Shortest Path Structure
	vector<int> value(V,INT_MAX);	//Keeps shortest path values to each vertex from source
	vector<bool> processed(V,false);	//TRUE->Vertex is processed

	//Assuming start point as Node-0
	parent[0] = -1;	//Start node has no parent
	value[0] = 0;	//start node has value=0 to get picked 1st

	//Include (V-1) edges to cover all V-vertices
	for(int i=0;i<V-1;++i)
	{
		//Select best Vertex by applying greedy method
		int U = selectMinVertex(value,processed);
		processed[U] = true;	//Include new Vertex in shortest Path Graph

		//Relax adjacent vertices (not yet included in shortest path graph)
		for(int j=0;j<V;++j)
		{
			/* 3 conditions to relax:-
			      1.Edge is present from U to j.
			      2.Vertex j is not included in shortest path graph
			      3.Edge weight is smaller than current edge weight
			*/
			/*
			if(graph[U][j]!=0 && processed[j]==false && value[U]!=INT_MAX && (value[U]+graph[U][j] < value[j])){
				value[j] = value[U]+graph[U][j];
				parent[j] = U;
			}
		}
	}
	//Print Shortest Path Graph
	for(int i=1;i<V;++i)
		cout<<"U->V: "<<parent[i]<<"->"<<i<<"  wt = "<<graph[parent[i]][i]<<"\n";
}

int main(){
	int graph[V][V] = { {0, 1, 4, 0, 0, 0},
						{1, 0, 4, 2, 7, 0},
						{4, 4, 0, 3, 5, 0},
						{0, 2, 3, 0, 4, 6},
						{0, 7, 5, 4, 0, 7},
						{0, 0, 0, 6, 7, 0} 
					};

	dijkstra(graph);	
	return 0;
}

//TIME COMPLEXITY: O(V^2)
//TIME COMPLEXITY: (using Min-Heap + Adjacency_List): O(ElogV)*/