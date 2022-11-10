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

int main()
{

	

	return 0;
}
