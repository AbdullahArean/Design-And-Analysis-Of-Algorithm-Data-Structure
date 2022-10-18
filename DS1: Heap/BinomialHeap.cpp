// Implementation of a binomial heaps using C++
// author: Algorithm Tutor
// Tutorial URL: https://algorithmtutor.com/Data-Structures/Tree/Binomial-Heaps/
// Limitation: Many extreme cases are not checked. Not suitable for production use.

#include <iostream>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;

// node data structure
struct Node {
	int data; // contains the key
	int degree; // number of children 
	Node *parent; // pointer to parent
	Node *child; // pointer to the leftmost child
	Node *sibling; // pointer to the right sibling
};

typedef Node *NodePtr;


// Class that represents Binomial heap data structure
class BinomialHeap {
private:
	// head points to the root of the leftmost binomial tree
	NodePtr head;

	// initializes  the node with default values
	// all pointers are initialized to nullptr
	void initializeNode(NodePtr node, int data, int degree) {
		node->data = data;
		node->degree = degree;
		node->parent = nullptr;
		node->child = nullptr;
		node->sibling = nullptr;
	}

	// merge two binomial trees of same degree
	static void linkBinomialTrees(NodePtr x, NodePtr y) {
		// x must be parent of y
		y->parent = x;
		y->sibling = x->child;
		x->child = y;

		// increase the degree of x
		x->degree += 1;
	}

public:
	BinomialHeap() {
		head = nullptr;
	}

	// find the node with mininum data
	NodePtr findMinimum() {
		// traverse all the roots and find compare
		int min = 999999;
		NodePtr currPtr = head;
		NodePtr minPtr = nullptr;

		while (currPtr != nullptr) {
			if (currPtr->data < min) {
				min = currPtr->data;
				minPtr = currPtr;
			}
			currPtr = currPtr->sibling;
		}

		return minPtr;

	}
	// insert a node to the heap
	void insert(int data) {
		BinomialHeap h;
		NodePtr node = new Node;
		initializeNode(node, data, 0);
		h.setHead(node);
		merge(h);
	}

	// print the binomial heap with all the trees
	void printHeap() {
		NodePtr currPtr = head;
		while (currPtr != nullptr) {
			cout<<"B"<<currPtr->degree<<endl;
			cout<<"There are "<<pow(2, currPtr->degree)<<" nodes in this tree"<<endl;
			cout<<"The level order traversal is"<<endl;
			queue<NodePtr> q;
			q.push(currPtr);
			while (!q.empty()) {
				NodePtr parent = q.front();
				q.pop();
				cout<<parent->data<<" ";

				if (parent->child != nullptr) {
					NodePtr tempPtr = parent->child;
					while (tempPtr != nullptr) {
						q.push(tempPtr);
						tempPtr = tempPtr->sibling;
					}
				} 
			}
			currPtr = currPtr->sibling;
			cout<<endl<<endl;
		}
	}

	// returns the head pointer
	NodePtr getHead() {
		return head;
	}

	// setter for head
	void setHead(NodePtr head) {
		this->head = head;
	}

	// merge two binomial heaps H and H'
	// resulting heap will be H
	void merge(BinomialHeap h1) {
		NodePtr curr1 = getHead();
		NodePtr curr2 = h1.getHead();
		NodePtr curr3 = nullptr;
		NodePtr temp = nullptr;

		if (curr1->degree <= curr2->degree) {
			curr3 = curr1;
			curr1 = curr1->sibling;
		} else {
			curr3 = curr2;
			curr2 = curr2->sibling;
		}

		temp = curr3;

		// merge two heaps without taking care of trees with same degree
		// the roots of the tree must be in accending order of degree from
		// left to right
		while(curr1 != nullptr && curr2 != nullptr) {
			if (curr1->degree <= curr2->degree) {
				curr3->sibling = curr1;
				curr1 = curr1->sibling;
			} else {
				curr3->sibling = curr2;
				curr2 = curr2->sibling;
			}

			curr3 = curr3->sibling;
		}

		if (curr1 != nullptr) {
			// copy all the remaining trees of heap1
			while(curr1 != nullptr) {
				curr3->sibling = curr1;
				curr1 = curr1->sibling;
				curr3 = curr3->sibling;
			}
		}

		if (curr2 != nullptr) {
			// copy all the remaining trees of heap2
			while(curr2 != nullptr) {
				curr3->sibling = curr2;
				curr2 = curr2->sibling;
				curr3 = curr3->sibling;
			}
		}


		// scan the merged list and repeatidly merge binomial trees with same degree
		curr3 = temp;
		NodePtr prev = nullptr;
		NodePtr next = curr3->sibling;

		while (next != nullptr) {
			// if two adjacent tree roots have different degree or 3 consecutive roots have same degree
			// move to the next tree
			if ((curr3->degree != next->degree )|| (next->sibling != nullptr && curr3->degree == next->sibling->degree)) {
				prev = curr3;
				curr3 = next;
			} else {
				// otherwise repeatdly merge binomial trees with same degree
				if (curr3->data <= next->data) {
					curr3->sibling = next->sibling;
					BinomialHeap::linkBinomialTrees(curr3, next);
				} else {
					if (prev == nullptr) {
						temp = next;
					} else {
						prev->sibling = next;
					}

					BinomialHeap::linkBinomialTrees(next, curr3);
					curr3 = next;
				}
			}

			next = curr3->sibling;
		}

		setHead(temp);
	}

	// deletes the smallest node from the heap
	NodePtr deleteMin() {
		NodePtr curr = head;
		NodePtr prevMin = nullptr;
		// find the root with minimum key
		NodePtr minPtr = nullptr;
		NodePtr prevPtr = nullptr;
		int min = 999999;

		while (curr != nullptr) {
			if (curr->data <= min) {
				min = curr->data;
				prevMin = prevPtr;
				minPtr = curr;
			}
			prevPtr = curr;
			curr = curr->sibling;
		}

		// delete the node pointed by minPtr
		if (prevMin != nullptr && minPtr->sibling != nullptr) {
			prevMin->sibling = minPtr->sibling;
		} else if (prevMin != nullptr && minPtr->sibling == nullptr) {
			prevMin->sibling = nullptr;
		}else if(prevMin == nullptr and minPtr->sibling != nullptr) {
		        head = minPtr->sibling;
		}else if(prevMin == nullptr and minPtr->sibling == nullptr) {
		        head = nullptr;
		}

		// remove parent reference from all its child
		NodePtr childPtr = minPtr->child;
		while (childPtr != nullptr) {
			childPtr->parent = nullptr;
			childPtr = childPtr->sibling;
		}

		// reverse the order 
		stack<NodePtr> s;
		childPtr = minPtr->child;
		while (childPtr != nullptr) {
			s.push(childPtr);
			childPtr = childPtr->sibling;
		}

		curr = s.top();
		NodePtr temp = curr;
		s.pop();

		while (!s.empty()) {
			curr->sibling = s.top();
			s.pop();
			curr = curr->sibling;
		}

		curr->sibling = nullptr;

		BinomialHeap h;
		h.setHead(temp);

		// merge 
		merge(h);

		// return the min root
		return minPtr;
	}
};

int main() {
	
	return 0;
}
