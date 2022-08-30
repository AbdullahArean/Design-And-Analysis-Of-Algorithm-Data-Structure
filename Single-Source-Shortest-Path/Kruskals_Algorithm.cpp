#include<bits/stdc++.h>
using namespace std;

struct node {
	int parent;
	int rank;
};
struct Edge {
	int src;
	int dst;
	int wt;
};

vector<node> dsuf;
vector<Edge> mst;
//FIND operation
int find(int v){
	if(dsuf[v].parent==-1)
		return v;
	return dsuf[v].parent=find(dsuf[v].parent);	//Path Compression
}

void union_op(int fromP,int toP){
	//fromP = find(fromP);
	//toP = find(toP);

	//UNION by RANK
	if(dsuf[fromP].rank > dsuf[toP].rank)	//fromP has higher rank
		dsuf[toP].parent = fromP;
	else if(dsuf[fromP].rank < dsuf[toP].rank)	//toP has higher rank
		dsuf[fromP].parent = toP;
	else
	{
		//Both have same rank and so anyone can be made as parent
		dsuf[fromP].parent = toP;
		dsuf[toP].rank +=1;		//Increase rank of parent
	}
}

bool comparator(Edge a,Edge b){
	return a.wt < b.wt;
}

void printEdgeList(vector<Edge>& edge_List){
	for(auto p: edge_List)
		cout<<"src: "<<p.src<<"  dst: "<<p.dst<<"  wt: "<<p.wt<<"\n";
	cout<<"============================================================\n";
}



void Kruskals(vector<Edge>& edge_List,int V,int E){
	cout<<"edge_List before sort\n";
	printEdgeList(edge_List);
	sort(edge_List.begin(),edge_List.end(),comparator);
	cout<<"edge_List after sort\n";
	printEdgeList(edge_List);

	int i=0,j=0;
	while(i<V-1 && j<E){

		int fromP = find(edge_List[j].src);	//FIND absolute parent of subset
		int toP = find(edge_List[j].dst);
		
		if(fromP == toP)
		{	++j;	continue;	}

		//UNION operation
		union_op(fromP,toP);	//UNION of 2 sets
		mst.push_back(edge_List[j]);
		++i;
	}
}
//Display the formed MST
void printMST(vector<Edge>& mst){
	cout<<"MST formed is\n";
	int cost = 0;
	for(auto p: mst){
		cout<<"src: "<<p.src<<"  dst: "<<p.dst<<"  wt: "<<p.wt<<"\n";
		cost+=p.wt;
	}
	cout<<"Total Cost is = "<<cost<<endl;
		
}

int main(){
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);	
	int E;	//No of edges
	int V;	//No of vertices (0 to V-1)
	cin>>V>>E;

	dsuf.resize(V);	//Mark all vertices as separate subsets with only 1 element
	for(int i=0;i<V;++i){	//Mark all nodes as independent set
		dsuf[i].parent=-1;
		dsuf[i].rank=0;
	}

	vector<Edge> edge_List;	//Adjacency list
	Edge temp;
	for(int i=0;i<E;++i){
		int from,to,wt;
		cin>>from>>to>>wt;
		temp.src = from;
		temp.dst = to;
		temp.wt = wt;
		edge_List.push_back(temp);
	}

	Kruskals(edge_List,V,E);
	printMST(mst);
	
	return 0;
}

//TIME COMPLEXITY: O(ElogE + ElogV)
//ElogE for sorting E edges in edge_list
//ElogV for applying FIND & UNION operations on E edges having V vertices
























































































/*#include <bits/stdc++.h>
using namespace std;
// DSU data structure
// path compression + rank by union

class DSU {
	int* parent;
	int* rank;

public:
	DSU(int n)
	{
		parent = new int[n];
		rank = new int[n];

		for (int i = 0; i < n; i++) {
			parent[i] = -1;
			rank[i] = 1;
		}
	}

	// Find function
	int find(int i)
	{
		if (parent[i] == -1)
			return i;

		return parent[i] = find(parent[i]);
	}
	// union function
	void unite(int x, int y)
	{
		int s1 = find(x);
		int s2 = find(y);

		if (s1 != s2) {
			if (rank[s1] < rank[s2]) {
				parent[s1] = s2;
				rank[s2] += rank[s1];
			}
			else {
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}
		}
	}
};

class Graph {
	vector<vector<int> > edgelist;
	int V;

public:
	Graph(int V) { this->V = V; }

	void addEdge(int x, int y, int w)
	{
		edgelist.push_back({ w, x, y });
	}

	void kruskals_mst(){
		// 1. Sort all edges
		sort(edgelist.begin(), edgelist.end());

		// Initialize the DSU
		DSU s(V);
		int ans = 0;
		cout << "Following are the edges in the "
				"constructed MST"
			<< endl;
		for (auto edge : edgelist) {
			int w = edge[0];
			int x = edge[1];
			int y = edge[2];

			// take that edge in MST if it does form a cycle
			if (s.find(x) != s.find(y)) {
				s.unite(x, y);
				ans += w;
				cout << x << " -- " << y << " == " << w
					<< endl;
			}
		}
		cout << "Minimum Cost Spanning Tree: " << ans;
	}
};*/


/*int main(){
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);	
	
	int v,e,a,b,c; cin>>v>>e;
	Graph g(4);
	for (int i = 0; i < e; i++){
        cin >> a >> b >> c;
        g.addEdge(a, b, c);
    }

	// int n, m;
	// cin >> n >> m;

	// Graph g(n);
	// for (int i = 0; i < m; i++)
	// {
	//	 int x, y, w;
	//	 cin >> x >> y >> w;
	//	 g.addEdge(x, y, w);
	// }

	g.kruskals_mst();
	return 0;
}*/










