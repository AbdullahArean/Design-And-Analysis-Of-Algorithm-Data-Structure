#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MaxEdge 100000
class edge
{
public:
	int from;
	int to;
	int wei;
	edge()
	{
		this->from;
		this->to = -1;
		this->wei = -1;
	}
	edge(int a, int b, int c)
	{
		this->from = a;
		this->to = b;
		this->wei = c;
	}
};
class Node
{
public:
	edge data;
	Node *next;
	Node(edge data)
	{
		this->data = data;
		this->next = NULL;
	}
};
class LinkedList
{
private:
	Node *LinkedListHead;
	int LengthOfLinkedList;
	void partition(Node *head, Node **front, Node **back)
	{
		Node *fast, *slow;
		if (head == NULL || head->next == NULL)
		{
			*front = head; // &a
			*back = NULL;  //&b
		}
		else
		{
			slow = head;
			fast = head->next;

			while (fast != NULL)
			{
				fast = fast->next;
				if (fast != NULL)
				{
					slow = slow->next;
					fast = fast->next;
				}
			}
			*front = head;		// &a
			*back = slow->next; //&b
			slow->next = NULL;
		}
	}
	Node *mergeLists(Node *a, Node *b)
	{
		Node *mergedList = NULL;
		if (a == NULL)
		{
			return b;
		}
		else if (b == NULL)
		{
			return a;
		}

		if (a->data.wei <= b->data.wei)
		{
			mergedList = a;
			mergedList->next = mergeLists(a->next, b);
		}
		else
		{
			mergedList = b;
			mergedList->next = mergeLists(a, b->next);
		}
		return mergedList;
	}
	void mergeSort(Node **source)
	{
		Node *head = *source;
		Node *a = NULL, *b = NULL;
		if (head == NULL || head->next == NULL)
			return;

		partition(head, &a, &b);
		mergeSort(&a);
		mergeSort(&b);

		*source = mergeLists(a, b);
	}

public:
	LinkedList()
	{
		LinkedListHead = NULL;
		LengthOfLinkedList = 0;
	}
	int length()
	{
		return this->LengthOfLinkedList;
	}
	void push_back(edge data)
	{
		int position = length();
		Node *newNode = new Node(data);
		Node *temp = LinkedListHead;
		if (LinkedListHead == NULL)
		{
			LinkedListHead = newNode;
			newNode->next = NULL;
		}
		else
		{
			for (int i = 0; i < position - 1; i++)
			{
				temp = temp->next;
				if (temp == NULL)
				{
					printf("Invalid Position!\n");
					return;
				}
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}

		LengthOfLinkedList++;
	}
	void printlist()
	{
		Node *temp = LinkedListHead;
		if (LinkedListHead == NULL)
		{
			cout << "List is empty!" << endl;
			return;
		}
		while (temp != NULL)
		{
			cout << temp->data.wei;
			temp = temp->next;
		}
		cout << "\n";
	}
	void linkedlist_sort()
	{
		mergeSort(&this->LinkedListHead);
	}
	edge delete_front()
	{
		if (LinkedListHead == NULL)
		{
			return edge(-1, -1, -1);
		}
		Node *temp = LinkedListHead;
		LinkedListHead = temp->next;
		LengthOfLinkedList--;
		return temp->data;
	}
	bool is_empty()
	{
		if (LengthOfLinkedList == 0 && LinkedListHead == NULL)
			return true;
		else
			return false;
	}
	Node* returnhead(){
		return LinkedListHead;
	}
};
class DSU_PC_UR
{

	int *parent;
	int *rank;

public:
	DSU_PC_UR(int n)
	{
		parent = new int[n];
		rank = new int[n];

		// parent -1, rank = 1
		for (int i = 0; i < n; i++)
		{
			parent[i] = -1;
			rank[i] = 1;
		}
	}

	// Find Function
	int find(int i)
	{
		// base case
		if (parent[i] == -1)
		{
			return i;
		}
		// otherwise
		return parent[i] = find(parent[i]);
	}

	// Unite (union)
	void unite(int x, int y)
	{
		int s1 = find(x);
		int s2 = find(y);

		if (s1 != s2)
		{
			// union by rank
			if (rank[s1] < rank[s2])
			{
				parent[s1] = s2;
				rank[s2] += rank[s1];
			}
			else
			{
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}
		}
	}
};
class DSU_UR
{

	int *parent;
	int *rank;

public:
	DSU_UR(int n)
	{
		parent = new int[n];
		rank = new int[n];

		// parent -1, rank = 1
		for (int i = 0; i < n; i++)
		{
			parent[i] = -1;
			rank[i] = 1;
		}
	}

	// Find Function
	int find(int i)
	{
		// base case
		if (parent[i] == -1)
		{
			return i;
		}
		// otherwise
		return find(parent[i]);
	}

	// Unite (union)
	void unite(int x, int y)
	{
		int s1 = find(x);
		int s2 = find(y);

		if (s1 != s2)
		{
			// union by rank
			if (rank[s1] < rank[s2])
			{
				parent[s1] = s2;
				rank[s2] += rank[s1];
			}
			else
			{
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}
		}
	}
};
class DSU_PC
{
	int *parent;

public:
	DSU_PC(int n)
	{
		parent = new int[n];

		// parent -1, rank = 1
		for (int i = 0; i < n; i++)
		{
			parent[i] = -1;
		}
	}

	// Find Function
	int find(int i)
	{
		// base case
		if (parent[i] == -1)
		{
			return i;
		}
		// otherwise
		// Path Compression
		return parent[i] = find(parent[i]);
	}

	// Unite (union)
	void unite(int x, int y)
	{
		int s1 = find(x);
		int s2 = find(y);

		if (s1 != s2)
		{
			parent[s1] = s2;
		}
	}
};
class DSU
{
	int *parent;

public:
	DSU(int n)
	{
		parent = new int[n];

		// parent -1, rank = 1
		for (int i = 0; i < n; i++)
		{
			parent[i] = -1;
		}
	}

	// Find Function
	int find(int i)
	{
		// base case
		if (parent[i] == -1)
		{
			return i;
		}
		// otherwise
		return find(parent[i]);
	}

	// Unite (union)
	void unite(int x, int y)
	{
		int s1 = find(x);
		int s2 = find(y);

		if (s1 != s2)
		{
			parent[s1] = s2;
		}
	}
};
class Graph
{
	LinkedList list;
	vector<vector<int>> edgelist;
	edge arr[MaxEdge];
	int len;
	int V;
	void quickSort(edge arr[], int start, int end)
    {
        if (start < end)
        {
            int pIndex = partition(arr, start, end);
            quickSort(arr, start, pIndex - 1);
            quickSort(arr, pIndex + 1, end);
        }
    }
    int partition(edge arr[], int start, int end)
    {
        int pIndex = start;
        edge pivot = arr[end];
        int i;
        for (i = start; i < end; i++)
        {
            if (arr[i].wei >= pivot.wei)
            {
                swap(&arr[i], &arr[pIndex]);
                pIndex++;
            }
        }
        swap(&arr[end], &arr[pIndex]);
        return pIndex;
    }
    void swap(edge *x, edge *y)
    {
        edge t = *x;
        *x = *y;
        *y = t;
    }
public:
	Graph(int V)
	{
		this->V = V;
		len=0;
	}

	void addEdge(int x, int y, int w)
	{
		edgelist.push_back({w, x, y});
		list.push_back(edge(x, y, w));
		arr[len++]= edge(x, y, w);
	}
	int kruskal_mst_DSU_PC_UR_STL()
	{
		// Main Logic = Easy!!!
		// 1. Sort all the edges based upon weight
		sort(edgelist.begin(), edgelist.end());

		// Init a DSU_PC_UR
		DSU s(V);

		int ans = 0;
		for (auto edge : edgelist)
		{

			int w = edge[0];
			int x = edge[1];
			int y = edge[2];

			// take that edge in MST if it doesnt form a cycle
			if (s.find(x) != s.find(y))
			{
				s.unite(x, y);
				ans += w;
			}
		}
		return ans;
	}
	int kruskal_mst_DSU_PC_STL()
	{
		// Main Logic = Easy!!!
		// 1. Sort all the edges based upon weight
		sort(edgelist.begin(), edgelist.end());

		// Init a DSU_PC_UR
		DSU_PC s(V);

		int ans = 0;
		for (auto edge : edgelist)
		{

			int w = edge[0];
			int x = edge[1];
			int y = edge[2];

			// take that edge in MST if it doesnt form a cycle
			if (s.find(x) != s.find(y))
			{
				s.unite(x, y);
				ans += w;
			}
		}
		return ans;
	}
	int kruskal_mst_DSU_UR_STL()
	{
		// Main Logic = Easy!!!
		// 1. Sort all the edges based upon weight
		sort(edgelist.begin(), edgelist.end());

		// Init a DSU_PC_UR
		DSU_UR s(V);

		int ans = 0;
		for (auto edge : edgelist)
		{

			int w = edge[0];
			int x = edge[1];
			int y = edge[2];

			// take that edge in MST if it doesnt form a cycle
			if (s.find(x) != s.find(y))
			{
				s.unite(x, y);
				ans += w;
			}
		}
		return ans;
	}
	int kruskal_mst_DSU_STL()
	{
		// Main Logic = Easy!!!
		// 1. Sort all the edges based upon weight
		sort(edgelist.begin(), edgelist.end());

		// Init a DSU_PC_UR
		DSU s(V);

		int ans = 0;
		for (auto edge : edgelist)
		{

			int w = edge[0];
			int x = edge[1];
			int y = edge[2];

			// take that edge in MST if it doesnt form a cycle
			if (s.find(x) != s.find(y))
			{
				s.unite(x, y);
				ans += w;
			}
		}
		return ans;
	}
	int kruskal_mst_DSU_PC_UR_LinkedList()
	{
		// Main Logic = Easy!!!
		// 1. Sort all the edges based upon weight
		list.linkedlist_sort();

		// Init a DSU_PC_UR
		DSU_PC_UR s(V);

		int ans = 0;
		Node*  temp = list.returnhead();
		while(temp!=NULL){
			edge e = temp->data;
			temp= temp->next;
			int w = e.wei;
			int x = e.from;
			int y = e.to;

			// take that edge in MST if it doesnt form a cycle
			if (s.find(x) != s.find(y))
			{
				s.unite(x, y);
				ans += w;
			}
		}
		return ans;
	}
	int kruskal_mst_DSU_UR_LinkedList()
	{
		// Main Logic = Easy!!!
		// 1. Sort all the edges based upon weight
		list.linkedlist_sort();

		// Init a DSU_PC_UR
		DSU_UR s(V);

		int ans = 0;
		Node*  temp = list.returnhead();
		while(temp!=NULL){
			edge e = temp->data;
			temp= temp->next;

			int w = e.wei;
			int x = e.from;
			int y = e.to;

			// take that edge in MST if it doesnt form a cycle
			if (s.find(x) != s.find(y))
			{
				s.unite(x, y);
				ans += w;
			}
		}
		return ans;
	}
	int kruskal_mst_DSU_PC_LinkedList()
	{
		// Main Logic = Easy!!!
		// 1. Sort all the edges based upon weight
		list.linkedlist_sort();

		// Init a DSU_PC_UR
		DSU_PC s(V);

		int ans = 0;
		Node*  temp = list.returnhead();
		while(temp!=NULL){
			edge e = temp->data;
			temp= temp->next;

			int w = e.wei;
			int x = e.from;
			int y = e.to;

			// take that edge in MST if it doesnt form a cycle
			if (s.find(x) != s.find(y))
			{
				s.unite(x, y);
				ans += w;
			}
		}
		return ans;
	}
	int kruskal_mst_DSU_LinkedList()
	{
		// Main Logic = Easy!!!
		// 1. Sort all the edges based upon weight
		list.linkedlist_sort();

		// Init a DSU_PC_UR
		DSU s(V);

		int ans = 0;
		Node*  temp = list.returnhead();
		while(temp!=NULL){
			edge e = temp->data;
			temp= temp->next;

			int w = e.wei;
			int x = e.from;
			int y = e.to;

			// take that edge in MST if it doesnt form a cycle
			if (s.find(x) != s.find(y))
			{
				s.unite(x, y);
				ans += w;
			}
		}
		return ans;
	}
	int kruskal_mst_DSU_PC_UR_Array()
	{
		// Main Logic = Easy!!!
		// 1. Sort all the edges based upon weight
		quickSort(arr,0,len-1);

		// Init a DSU_PC_UR
		DSU_PC_UR s(V);

		int ans = 0;
		for(int i=len-1; i>=0; i--){

			
			edge e = arr[i];
			int w = e.wei;
			int x = e.from;
			int y = e.to;

			// take that edge in MST if it doesnt form a cycle
			if (s.find(x) != s.find(y))
			{
				s.unite(x, y);
				ans += w;
			}
		}
		return ans;
	}
	int kruskal_mst_DSU_UR_Array()
	{
		// Main Logic = Easy!!!
		// 1. Sort all the edges based upon weight
		quickSort(arr,0,len-1);

		// Init a DSU_PC_UR
		DSU_UR s(V);

		int ans = 0;
		for(int i=len-1; i>=0; i--){

			
			edge e = arr[i];
			int w = e.wei;
			int x = e.from;
			int y = e.to;

			// take that edge in MST if it doesnt form a cycle
			if (s.find(x) != s.find(y))
			{
				s.unite(x, y);
				ans += w;
			}
		}
		return ans;
	}
	int kruskal_mst_DSU_PC_Array()
	{
		// Main Logic = Easy!!!
		// 1. Sort all the edges based upon weight
		quickSort(arr,0,len-1);

		// Init a DSU_PC_UR
		DSU_PC s(V);

		int ans = 0;
		for(int i=len-1; i>=0; i--){

			
			edge e = arr[i];
			int w = e.wei;
			int x = e.from;
			int y = e.to;

			// take that edge in MST if it doesnt form a cycle
			if (s.find(x) != s.find(y))
			{
				s.unite(x, y);
				ans += w;
			}
		}
		return ans;
	}
	int kruskal_mst_DSU_Array()
	{
		// Main Logic = Easy!!!
		// 1. Sort all the edges based upon weight
		quickSort(arr,0,len-1);

		// Init a DSU_PC_UR
		DSU s(V);

		int ans = 0;
		for(int i=len-1; i>=0; i--){

			
			edge e = arr[i];
			int w = e.wei;
			int x = e.from;
			int y = e.to;

			// take that edge in MST if it doesnt form a cycle
			if (s.find(x) != s.find(y))
			{
				s.unite(x, y);
				ans += w;
			}
		}
		return ans;
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
		g1.addEdge(a, b, c);
	}

	cout << g1.kruskal_mst_DSU_PC_UR_STL() << endl;
	cout << g1.kruskal_mst_DSU_PC_STL() << endl;
	cout << g1.kruskal_mst_DSU_UR_STL() << endl;
	cout << g1.kruskal_mst_DSU_STL() << endl;
	cout << g1.kruskal_mst_DSU_PC_UR_LinkedList()<<endl;
	cout << g1.kruskal_mst_DSU_PC_LinkedList()<<endl;
	cout << g1.kruskal_mst_DSU_UR_LinkedList()<<endl;
	cout << g1.kruskal_mst_DSU_LinkedList()<<endl;
	cout << g1.kruskal_mst_DSU_PC_UR_Array()<<endl;
	cout << g1.kruskal_mst_DSU_PC_Array()<<endl;
	cout << g1.kruskal_mst_DSU_UR_Array()<<endl;
	cout << g1.kruskal_mst_DSU_Array()<<endl;


	return 0;
}
