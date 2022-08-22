#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
#define HEAP_SIZE 100000

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
            *front = head;      // &a
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
            return edge(-1, -1);
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
        if(heap_size<= 0) return {-1,-1};
        if (heap_size==1){
            heap_size--;
            return arr[0];
        }
        edge root = arr[0];
        arr[0]=arr[heap_size-1];
        heap_size--;
        Minheeapify(0);
        return root;

    }
    void Minheeapify(int i){
        int  l = left_child(i);
        int  r= right_child(i);

        int smallest= i;
        if(l<heap_size && arr[l].wei<arr[i].wei ){
            smallest=l;
        }
        if(r<heap_size && arr[r].wei<arr[smallest].wei){
            smallest=r;
        }
        if(smallest!=i){
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
        while(i != 0 && arr[get_parent(i)].wei > arr[i].wei)
        {
            swap(&arr[i], &arr[get_parent(i)]);
            i = get_parent(i);
        }
    }
    void printheap(){
        for(int i=0; i<heap_size; i++){
            cout<<arr[i].wei<<endl;
        }
        cout<<endl;
    }
    bool isempty(){
        if(heap_size<=0) return true;
        else return false;
    }
};

class Graph
{
    // adjlist
    vector<edge> *adjl;
    // Number Of Vertex
    int nver;

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
    Graph(int n)
    {
        this->nver = n;
        adjl = new vector<edge>[n];
    }
    void addedge(int x, int y, int w)
    {
        adjl[x].push_back(edge(y, w));
        adjl[y].push_back(edge(x, w));
    }
    int prim_mst_linkedlist()
    {
        // Container To Keep The Active Edges
        LinkedList container = LinkedList();
        // Visited Array that denotes whether a node has been in MST or not
        bool *visited = new bool[nver]{0};
        int ans = 0;
        container.push_back(edge(0, 0));
        while (!container.is_empty())
        {
            container.linkedlist_sort();
            edge temp = container.delete_front();
            int to = temp.to;
            int wei = temp.wei;
            if (visited[to])
            {
                continue;
            }
            // otherwise take the current edge
            ans += wei;
            visited[to] = 1;
            for (auto x : adjl[to])
            {
                if (visited[x.to] == 0)
                {
                    container.push_back(x);
                }
            }
        }
        return ans;
    }
    int prim_mst_array()
    {
        // Container To Keep The Active Edges
        edge *container = new edge[HEAP_SIZE];
        int containerlen = 0;
        // Visited Array that denotes whether a node has been in MST or not
        bool *visited = new bool[nver]{0};
        int ans = 0;
        container[containerlen] = edge(0, 0);
        containerlen++;
        while (containerlen > 0)
        {
            quickSort(container, 0, containerlen - 1);
            edge temp = container[containerlen - 1];
            containerlen--;

            int to = temp.to;
            int wei = temp.wei;
            if (visited[to])
            {
                continue;
            }
            // otherwise take the current edge
            ans += wei;
            visited[to] = 1;
            for (auto x : adjl[to])
            {
                if (visited[x.to] == 0)
                {
                    container[containerlen] = x;
                    containerlen++;
                }
            }
        }
        delete [] container;
        return ans;
    }
    int prim_mst_bin_min_heap(){
        // Container To Keep The Active Edges
        Heap container= Heap(HEAP_SIZE);
        // Visited Array that denotes whether a node has been in MST or not
        bool *visited = new bool[nver]{0};
        int ans = 0;
        container.push_heap(edge(0, 0));
        while (!container.isempty())
        {
            edge temp = container.pop_heap();
            int to = temp.to;
            int wei = temp.wei;
            if (visited[to])
            {
                continue;
            }
            // otherwise take the current edge
            ans += wei;
            visited[to] = 1;
            for (auto x : adjl[to])
            {
                if (visited[x.to] == 0)
                {
                    container.push_heap(x);
                }
            }
        }
        return ans;

    }
    int prim_mst_fib_min_heap(){
        
    return 0;
    } 
    int prim_mst_stl_priority_Queue(){
        //most important stuff
		//Init a Min Heap
		priority_queue<pair<int,int>, vector<pair<int,int> > , greater<pair<int,int> > > Q; 

		//another array
		//visited array that denotes whether a node has been included in MST or Not
		bool * vis = new bool[nver]{0};
		int ans = 0;

		//begin 
		Q.push({0,0}); // weight, node

		while(!Q.empty()){
			//pick out the edge with min weight
			auto best = Q.top();
			Q.pop();

			int to = best.second;
			int weight = best.first;

			if(vis[to]){
				//discard the edge, and continue
				continue;
			}

			//otherwise take the current edge
			ans += weight;
			vis[to] = 1;

			//add the new edges in the queue
			for(auto x:adjl[to]){
				if(vis[x.to]==0){
					Q.push({x.wei,x.to});
				}
			}
		}
		return ans;

    }
};

int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("output.txt", "a", stdout);
    int v, e, a, b, c;
    cin >> v >> e;
    Graph g1 = Graph(v);
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> c;
        g1.addedge(a, b, c);
    }
    //Run Prim Algo Test after removing comment of below code, it will generate results
    // cout<<v<<" "<<e<<" ";
    // auto start1 = high_resolution_clock::now();
    // g1.prim_mst_stl_priority_Queue();
    // auto stop1 = high_resolution_clock::now();
    // auto duration1 = duration_cast<microseconds>(stop1 - start1);
    // cout<<" "<< duration1.count();

    // auto start2 = high_resolution_clock::now();
    // g1.prim_mst_bin_min_heap();
    // auto stop2 = high_resolution_clock::now();
    // auto duration2 = duration_cast<microseconds>(stop2 - start2);
    // cout<<" "<<duration2.count();

    // auto start3 = high_resolution_clock::now();
    // g1.prim_mst_linkedlist();
    // auto stop3 = high_resolution_clock::now();
    // auto duration3 = duration_cast<microseconds>(stop3 - start3);
    // cout<<" "<< duration3.count();

    // auto start4 = high_resolution_clock::now();
    // g1.prim_mst_array();
    // auto stop4 = high_resolution_clock::now();
    // auto duration4 = duration_cast<microseconds>(stop4 - start4);
    // cout<<" "<<duration4.count()<<endl;
}