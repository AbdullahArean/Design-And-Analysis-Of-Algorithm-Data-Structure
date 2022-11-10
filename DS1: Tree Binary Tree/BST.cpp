#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left_child;
    Node *right_child;
    Node(int data)
    {
        this->data = data;
        this->left_child = NULL;
        this->right_child = NULL;
    }
};
class BST {
    private:
    Node* Binary_Tree_Root;
    Node*   makeBSTEmpty        (Node* Current_Tree_Node) {
        if(Current_Tree_Node == NULL)
            return NULL;
        {
            makeBSTEmpty(Current_Tree_Node->left_child);
            makeBSTEmpty(Current_Tree_Node->right_child);
            delete Current_Tree_Node;
        }
        return NULL;
    }
    Node*   insert              (int x, Node* Current_Tree_Node)
    {
        if(Current_Tree_Node == NULL) 
            Current_Tree_Node = new Node(x);
        else if(x < Current_Tree_Node->data)
            Current_Tree_Node->left_child = insert(x, Current_Tree_Node->left_child);
        else if(x > Current_Tree_Node->data)
            Current_Tree_Node->right_child = insert(x, Current_Tree_Node->right_child);
        return Current_Tree_Node;
    }
    Node*   findMin             (Node* Current_Tree_Node)
    {
        if(Current_Tree_Node == NULL)
            return NULL;
        else if(Current_Tree_Node->left_child == NULL)
            return Current_Tree_Node;
        else
            return findMin(Current_Tree_Node->left_child);
    }
    Node*   findMax             (Node* Current_Tree_Node) {
        if(Current_Tree_Node == NULL)
            return NULL;
        else if(Current_Tree_Node->right_child == NULL)
            return Current_Tree_Node;
        else
            return findMax(Current_Tree_Node->right_child);
    }
    Node*   remove              (int x, Node* Current_Tree_Node) {
        Node* temp;
        if(Current_Tree_Node == NULL)
            return NULL;
        else if(x < Current_Tree_Node->data)
            Current_Tree_Node->left_child = remove(x, Current_Tree_Node->left_child);
        else if(x > Current_Tree_Node->data)
            Current_Tree_Node->right_child = remove(x, Current_Tree_Node->right_child);
        else if(Current_Tree_Node->left_child && Current_Tree_Node->right_child)
        {
            temp = findMin(Current_Tree_Node->right_child);
            Current_Tree_Node->data = temp->data;
            Current_Tree_Node->right_child = remove(Current_Tree_Node->data, Current_Tree_Node->right_child);
        }
        else
        {
            temp = Current_Tree_Node;
            if(Current_Tree_Node->left_child == NULL)
                Current_Tree_Node = Current_Tree_Node->right_child;
            else if(Current_Tree_Node->right_child == NULL)
                Current_Tree_Node = Current_Tree_Node->left_child;
            delete temp;
        }

        return Current_Tree_Node;
    }
    void    inorder             (Node* Current_Tree_Node) {
        if(Current_Tree_Node == NULL)
            return;
        inorder(Current_Tree_Node->left_child);
        cout << Current_Tree_Node->data << " ";
        inorder(Current_Tree_Node->right_child);
    }
    Node*   find                (Node* Current_Tree_Node, int x) {
        if(Current_Tree_Node == NULL)
            return NULL;
        else if(x < Current_Tree_Node->data)
            return find(Current_Tree_Node->left_child, x);
        else if(x > Current_Tree_Node->data)
            return find(Current_Tree_Node->right_child, x);
        else
            return Current_Tree_Node;
    }
    void    print_preorder      (Node *bbinary_tree)
    {
        if (bbinary_tree)
        {
            printf("%d ", bbinary_tree->data);
            print_preorder(bbinary_tree->left_child);
            print_preorder(bbinary_tree->right_child);
        }
    }
    void    print_inorder       (Node *bbinary_tree)
    {
        if (bbinary_tree)
        {
            print_inorder(bbinary_tree->left_child);
            printf("%d ", bbinary_tree->data);
            print_inorder(bbinary_tree->right_child);
        }
    }
    void    print_postorder     (Node *bbinary_tree)
    {
        if (bbinary_tree)
        {
            print_postorder(bbinary_tree->left_child);
            print_postorder(bbinary_tree->right_child);
            printf("%d ", bbinary_tree->data);
        }
    }
    int     height              (Node *bbinary_tree)
    {
        int depth = 0;

        queue<Node *> q;
        q.push(bbinary_tree);
        q.push(NULL);
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                depth++;
            }
            if (temp != NULL)
            {
                if (temp->left_child)
                {
                    q.push(temp->left_child);
                }
                if (temp->right_child)
                {
                    q.push(temp->right_child);
                }
            }
            else if (!q.empty())
            {
                q.push(NULL);
            }
        }
        return depth;
    }
    void    print_levelorder    (Node *bbinary_tree)
    {
        /* Function to line by line print level order traversal a tree*/
        int h = height(bbinary_tree);
        int i;
        for (i = 1; i <= h; i++)
        {
            printGivenLevel(bbinary_tree, i);
            //printf("\n");
        }
    }
    void    printGivenLevel     (Node *bbinary_tree, int level)
    {
        /* Print Nodes at a given level */
        if (bbinary_tree == NULL)
            return;
        if (level == 1)
            printf("%d ", bbinary_tree->data);
        else if (level > 1)
        {
            printGivenLevel(bbinary_tree->left_child, level - 1);
            printGivenLevel(bbinary_tree->right_child, level - 1);
        }
    }
    int     numberofNodes       (Node *bbinary_tree){
        if (!bbinary_tree) return 0;
        return numberofNodes(bbinary_tree->left_child)+numberofNodes(bbinary_tree->right_child)+1;

    }
    int     numberofleafs       (Node *bbinary_tree){
        if(!bbinary_tree) return 0;
        if (!bbinary_tree->left_child && !bbinary_tree->right_child) return 1;
        return numberofleafs (bbinary_tree->left_child)+numberofleafs (bbinary_tree->right_child);

    }
    int     numberofnonleafs    (Node *bbinary_tree){
        if((!bbinary_tree) || (!bbinary_tree->left_child && !bbinary_tree->right_child) )return 0;
            return numberofnonleafs (bbinary_tree->left_child)+numberofnonleafs (bbinary_tree->right_child)+1;

    }
    int     numberoffullNode    (Node *bbinary_tree){
        if(!bbinary_tree) return 0;
        if(!bbinary_tree->left_child && !bbinary_tree->right_child ) return 0;
        return numberoffullNode(bbinary_tree->left_child)+numberoffullNode(bbinary_tree->right_child)+ (bbinary_tree->left_child && bbinary_tree->right_child)?1:0;
       
    }
    int     heightfordiameter   (Node *bbinary_tree)
{
    if (bbinary_tree == NULL)
        return 0;
    return 1 + max(heightfordiameter (bbinary_tree->left_child), heightfordiameter (bbinary_tree->right_child));
}
    int     diameterofnode      (Node *bbinary_tree)
{
    if (bbinary_tree == NULL)
        return 0;
    int lheight = heightfordiameter (bbinary_tree->left_child);
    int rheight = heightfordiameter (bbinary_tree->right_child);
    int ldiameter = diameterofnode(bbinary_tree->left_child);
    int rdiameter = diameterofnode(bbinary_tree->right_child);
    return max(lheight + rheight + 1,
            max(ldiameter, rdiameter));
}
public:
    BST() {
        Binary_Tree_Root = NULL;
    }
    ~BST() {
        Binary_Tree_Root = makeBSTEmpty(Binary_Tree_Root);
    }
    void    insert              (int x) {
        Binary_Tree_Root = insert(x, Binary_Tree_Root);
    }
    void    remove              (int x) {
        Binary_Tree_Root = remove(x, Binary_Tree_Root);
    }
    void    display             () {
        print_levelorder(Binary_Tree_Root);
        cout << endl;
    }
    void    search              (int x) {
        Binary_Tree_Root = find(Binary_Tree_Root, x);
    }
    Node*   BuildTreePreIn      (int in[], int pre[], int inStrt, int inEnd)
    {
        static int preIndex = 0;
        if (inStrt > inEnd) return NULL;
        Node *tNode = new Node(pre[preIndex++]);
        if (inStrt == inEnd) return tNode;
        int inIndex = -1;
        for (int i = inStrt; i <= inEnd; i++) if (in[i] == tNode->data) inIndex = i;
        tNode->left_child = BuildTreePreIn(in, pre, inStrt, inIndex - 1);
        tNode->right_child = BuildTreePreIn(in, pre, inIndex + 1, inEnd);
        return tNode;
    }
    void    BuildTree           (int in[], int pre[], int inStrt, int inEnd)
    {
        this->Binary_Tree_Root = BuildTreePreIn(in,pre, inStrt, inEnd);

    }
    Node*   Returntreehead      ()
    {
        return Binary_Tree_Root;
    }
    Node * FindMaximumElement   () {
        return findMax(this->Binary_Tree_Root);

    }
    Node * FindMinimumElement   () {
        return findMin(this->Binary_Tree_Root);

    }
    int     heightoftree              (Node *bbinary_tree)
    {
        int depth = 0;

        queue<Node *> q;
        q.push(bbinary_tree);
        q.push(NULL);
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                depth++;
            }
            if (temp != NULL)
            {
                if (temp->left_child)
                {
                    q.push(temp->left_child);
                }
                if (temp->right_child)
                {
                    q.push(temp->right_child);
                }
            }
            else if (!q.empty())
            {
                q.push(NULL);
            }
        }
        return depth;
    }
    int diameter(){
        return diameterofnode(this->Binary_Tree_Root);
    }
};

int main() {
    BST Current_Tree_Node;
    Current_Tree_Node.insert(29);
    Current_Tree_Node.insert(28);
    Current_Tree_Node.insert(25);
    Current_Tree_Node.insert(10);
    Current_Tree_Node.insert(30);
    Current_Tree_Node.display();
    Current_Tree_Node.remove(20);
    Current_Tree_Node.display();
    Current_Tree_Node.remove(25);
    Current_Tree_Node.display();
    Current_Tree_Node.remove(30);
    Current_Tree_Node.display();
    cout<<Current_Tree_Node.diameter()<<endl;
    return 0; 
}