#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std::chrono;
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

	freopen("input2.txt", "r", stdin);
	freopen("output_kruskal.txt", "w", stdout);
	int v, e, a, b, c;
	cin >> v >> e;
	Graph g1 = Graph(v);
	for (int i = 0; i < e; i++)
	{
		cin >> a >> b >> c;
		g1.addEdge(a, b, c);
	}
	int choice = 0;
	while(choice!=-1){
		printf("Which Implementation You Want For Kruskal's to run?\n");
    printf("1.DSU_PC_UR_STL\n2.DSU_UR_STL\n3.DSU_PC_STL\n4.DSU_STL\n5.DSU_PC_UR_LinkedList\n6.DSU_UR_LinkedList\n7.DSU_PC_LinkedList\n8.DSU_LinkedList\n9.DSU_PC_UR_Array\n10.DSU_UR_Array\n11.DSU_PC_Array\n12.DSU_SArray\n13.Exit (Give -1 as input)\n");
    
    cin >> choice;
	if(choice==-1) break;

    auto start1 = high_resolution_clock::now();
    switch (choice)
    {
    case 1:
		cout<<"DSU_PC_UR_STL: MST Kruskal Implementation "<<g1.kruskal_mst_DSU_PC_UR_STL();
		break;
	case 2:
		cout<<"DSU_UR_STL: MST Kruskal Implementation "<<g1.kruskal_mst_DSU_UR_STL();
		break;
	case 3:
		cout<<"DSU_PC_STL: MST  Kruskal Implementation "<<g1.kruskal_mst_DSU_PC_STL();
		break;
	case 4:
		cout<<"DSU_STL: MST Kruskal Implementation "<<g1.kruskal_mst_DSU_STL();
		break;
	case 5:
		cout<<"DSU_PC_UR_LinkedList: MST Kruskal Implementation "<<g1.kruskal_mst_DSU_PC_UR_LinkedList();
		break;
	case 6:
		cout<<"DSU_UR_LinkedList: MST Kruskal Implementation "<<g1.kruskal_mst_DSU_UR_LinkedList();
		break;
	case 7:
		cout<<"DSU_PC_LinkedList: MST  Kruskal Implementation "<<g1.kruskal_mst_DSU_PC_LinkedList();
		break;
	case 8:
		cout<<"DSU_LinkedList: MST Kruskal Implementation "<<g1.kruskal_mst_DSU_LinkedList();
		break;
	case 9:
		cout<<"DSU_PC_UR_Array: MST Kruskal Implementation "<<g1.kruskal_mst_DSU_PC_UR_Array();
		break;
	case 10:
		cout<<"DSU_UR_Array: MST Kruskal Implementation "<<g1.kruskal_mst_DSU_UR_Array();
		break;
	case 11:
		cout<<"DSU_PC_Array: MST  Kruskal Implementation "<<g1.kruskal_mst_DSU_PC_Array();
		break;
	case 12:
		cout<<"DSU_Array: MST Kruskal Implementation "<<g1.kruskal_mst_DSU_Array();
		break;
	
	default:
		break;
	}
	auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    cout << " Time Required: " << duration1.count() << " microseconds" << endl;
    ;

	}
	
	//Test
	// cout<<v<<" "<<e<<" ";
	// auto start1 = high_resolution_clock::now();
    // g1.kruskal_mst_DSU_PC_UR_STL();
    // auto stop1 = high_resolution_clock::now();
    // auto duration1 = duration_cast<microseconds>(stop1 - start1);
    // cout<<" "<< duration1.count();

	// auto start2 = high_resolution_clock::now();
    // g1.kruskal_mst_DSU_PC_STL();
    // auto stop2 = high_resolution_clock::now();
    // auto duration2 = duration_cast<microseconds>(stop2 - start2);
    // cout<<" "<< duration2.count();

	// auto start3 = high_resolution_clock::now();
    // g1.kruskal_mst_DSU_UR_STL();
    // auto stop3 = high_resolution_clock::now();
    // auto duration3 = duration_cast<microseconds>(stop3 - start3);
    // cout<<" "<< duration3.count();

	// auto start4 = high_resolution_clock::now();
    // g1.kruskal_mst_DSU_STL();
    // auto stop4 = high_resolution_clock::now();
    // auto duration4 = duration_cast<microseconds>(stop4 - start4);
    // cout<<" "<< duration4.count();


	// auto start5 = high_resolution_clock::now();
    // g1.kruskal_mst_DSU_PC_UR_LinkedList();
    // auto stop5 = high_resolution_clock::now();
    // auto duration5 = duration_cast<microseconds>(stop5 - start5);
    // cout<<" "<< duration5.count();

	// auto start6 = high_resolution_clock::now();
    // g1.kruskal_mst_DSU_PC_LinkedList();
    // auto stop6 = high_resolution_clock::now();
    // auto duration6 = duration_cast<microseconds>(stop6 - start6);
    // cout<<" "<< duration6.count();

	// auto start7 = high_resolution_clock::now();
    // g1.kruskal_mst_DSU_UR_LinkedList();
    // auto stop7 = high_resolution_clock::now();
    // auto duration7 = duration_cast<microseconds>(stop7 - start7);
    // cout<<" "<< duration7.count();

	// auto start8 = high_resolution_clock::now();
    // g1.kruskal_mst_DSU_LinkedList();
    // auto stop8 = high_resolution_clock::now();
    // auto duration8 = duration_cast<microseconds>(stop8 - start8);
    // cout<<" "<< duration8.count();

	// auto start9 = high_resolution_clock::now();
    // g1.kruskal_mst_DSU_PC_UR_Array();
    // auto stop9 = high_resolution_clock::now();
    // auto duration9 = duration_cast<microseconds>(stop9 - start9);
    // cout<<" "<< duration9.count();

	// auto start10 = high_resolution_clock::now();
    // g1.kruskal_mst_DSU_PC_Array();
    // auto stop10 = high_resolution_clock::now();
    // auto duration10 = duration_cast<microseconds>(stop10 - start10);
    // cout<<" "<< duration10.count();

	// auto start11 = high_resolution_clock::now();
    // g1.kruskal_mst_DSU_UR_Array();
    // auto stop11 = high_resolution_clock::now();
    // auto duration11 = duration_cast<microseconds>(stop11 - start11);
    // cout<<" "<< duration11.count();

	// auto start12 = high_resolution_clock::now();
    // g1.kruskal_mst_DSU_Array();
    // auto stop12 = high_resolution_clock::now();
    // auto duration12 = duration_cast<microseconds>(stop12 - start12);
    // cout<<" "<< duration12.count()<<endl;


	return 0;
}
