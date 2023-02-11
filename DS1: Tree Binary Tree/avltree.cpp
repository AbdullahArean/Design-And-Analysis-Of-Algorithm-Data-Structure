#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

class Node
{
public:
    Node *left_child, *right_child;
    int data_in, height_of_node;
};

class AVLTree
{

public:
    class Node *root;
    AVLTree()
    {
        this->root = NULL;
    }
    int calheight(Node *temp)
    {

        if (temp->left_child && temp->right_child)
        {
            if (temp->left_child->height_of_node < temp->right_child->height_of_node)
                return temp->right_child->height_of_node + 1;
            else
                return temp->left_child->height_of_node + 1;
        }
        else if (temp->left_child && temp->right_child == NULL)
        {
            return temp->left_child->height_of_node + 1;
        }
        else if (temp->left_child == NULL && temp->right_child)
        {
            return temp->right_child->height_of_node + 1;
        }
        return 0;
    }
    int Balance_Factor(Node *given_node)
    {
        if (given_node->left_child && given_node->right_child)
        {
            return given_node->left_child->height_of_node - given_node->right_child->height_of_node;
        }
        else if (given_node->left_child && given_node->right_child == NULL)
        {
            return given_node->left_child->height_of_node;
        }
        else if (given_node->left_child == NULL && given_node->right_child)
        {
            return -given_node->right_child->height_of_node;
        }
        return 0;
    }
    Node *LL(class Node *given_node)
    {
        Node *temp;
        Node *temp1;
        temp = given_node;
        temp1 = temp->left_child;

        temp->left_child = temp1->right_child;
        temp1->right_child = temp;

        return temp1;
    }
    Node *RR(class Node *given_node)
    {
        Node *temp;
        Node *temp1;
        temp = given_node;
        temp1 = temp->right_child;

        temp->right_child = temp1->left_child;
        temp1->left_child = temp;

        return temp1;
    }
    Node *RLR(class Node *given_node)
    {
        Node *temp, *temp1, *temp2;
        temp = given_node;
        temp1 = temp->right_child;
        temp2 = temp->right_child->left_child;
        temp->right_child = temp2->left_child;
        temp1->left_child = temp2->right_child;
        temp2->left_child = temp;
        temp2->right_child = temp1;

        return temp2;
    }
    Node *LRR(class Node *given_node)
    {
        Node *temp, *temp1, *temp2;
        temp = given_node;
        temp1 = temp->left_child;
        temp2 = temp->left_child->right_child;
        temp->left_child = temp2->right_child;
        temp1->right_child = temp2->left_child;
        temp2->right_child = temp;
        temp2->left_child = temp1;
        return temp2;
    }

    Node *insert(class Node *node_insert, int data_in)
    {

        if (node_insert == NULL)
        {
            class Node *given_node;
            given_node = new class Node;
            given_node->data_in = data_in;
            node_insert = given_node;
            node_insert->left_child = node_insert->right_child = NULL;
            node_insert->height_of_node = 1;
            return node_insert;
        }
        else
        {
            if (data_in < node_insert->data_in)
                node_insert->left_child = insert(node_insert->left_child, data_in);
            else
                node_insert->right_child = insert(node_insert->right_child, data_in);
        }

        node_insert->height_of_node = calheight(node_insert);

        if (Balance_Factor(node_insert) == 2 && Balance_Factor(node_insert->left_child) == 1)
        {
            node_insert = LL(node_insert);
        }
        else if (Balance_Factor(node_insert) == -2 && Balance_Factor(node_insert->right_child) == -1)
        {
            node_insert = RR(node_insert);
        }
        else if (Balance_Factor(node_insert) == -2 && Balance_Factor(node_insert->right_child) == 1)
        {
            node_insert = RLR(node_insert);
        }
        else if (Balance_Factor(node_insert) == 2 && Balance_Factor(node_insert->left_child) == -1)
        {
            node_insert = LRR(node_insert);
        }

        return node_insert;
    }
    void levelorder_newline()
    {
        if (this->root == NULL)
        {
            cout << "Empty Tree\n";
            return;
        }
        levelorder_newline(this->root);
    }
    void levelorder_newline(class Node *v)
    {
        queue<class Node *> q;
        Node *cur;
        q.push(v);
        q.push(NULL);

        while (!q.empty())
        {
            cur = q.front();
            q.pop();
            if (cur == NULL && q.size() != 0)
            {
                cout << "\n";

                q.push(NULL);
                continue;
            }
            if (cur != NULL)
            {
                cout << " " << cur->data_in;

                if (cur->left_child != NULL)
                {
                    q.push(cur->left_child);
                }
                if (cur->right_child != NULL)
                {
                    q.push(cur->right_child);
                }
            }
        }
    }
    Node *deleteNode(class Node *temp, int data_in)
    {

        if (temp->left_child == NULL && temp->right_child == NULL)
        {
            if (temp == this->root)
                this->root = NULL;
            delete temp;
            return NULL;
        }

        Node *t;
        Node *q;
        if (temp->data_in < data_in)
        {
            temp->right_child = deleteNode(temp->right_child, data_in);
        }
        else if (temp->data_in > data_in)
        {
            temp->left_child = deleteNode(temp->left_child, data_in);
        }
        else
        {
            if (temp->left_child != NULL)
            {
                q = intempre(temp->left_child);
                temp->data_in = q->data_in;
                temp->left_child = deleteNode(temp->left_child, q->data_in);
            }
            else
            {
                q = insuc(temp->right_child);
                temp->data_in = q->data_in;
                temp->right_child = deleteNode(temp->right_child, q->data_in);
            }
        }

        if (Balance_Factor(temp) == 2 && Balance_Factor(temp->left_child) == 1)
        {
            temp = LL(temp);
        }
        else if (Balance_Factor(temp) == 2 && Balance_Factor(temp->left_child) == -1)
        {
            temp = LRR(temp);
        }
        else if (Balance_Factor(temp) == 2 && Balance_Factor(temp->left_child) == 0)
        {
            temp = LL(temp);
        }
        else if (Balance_Factor(temp) == -2 && Balance_Factor(temp->right_child) == -1)
        {
            temp = RR(temp);
        }
        else if (Balance_Factor(temp) == -2 && Balance_Factor(temp->right_child) == 1)
        {
            temp = RLR(temp);
        }
        else if (Balance_Factor(temp) == -2 && Balance_Factor(temp->right_child) == 0)
        {
            temp = LL(temp);
        }

        return temp;
    }

    class Node *intempre(class Node *temp)
    {
        while (temp->right_child != NULL)
            temp = temp->right_child;
        return temp;
    }

    class Node *insuc(class Node *temp)
    {
        while (temp->left_child != NULL)
            temp = temp->left_child;

        return temp;
    }

    ~AVLTree()
    {
    }
};

int main()
{

    AVLTree b;
    int c, x;

    do
    {
        cout << "\n1.Distemplay levelorder on newline";
        cout << "\n2.Insert";
        cout << "\n3.Delete node";
        cout << "\n0.Exit node";
        cout << "\nChoice: ";

        cin >> c;

        switch (c)
        {
        case 1:
            b.levelorder_newline();
            // to temprint the tree in level order
            break;

        case 2:
            cout << "\nEnter no. ";
            cin >> x;
            b.root = b.insert(b.root, x);
            break;

        case 3:
            cout << "\nWhat to delete? ";
            cin >> x;
            b.root = b.deleteNode(b.root, x);
            break;

        case 0:
            break;
        }

    } while (c != 0);
}