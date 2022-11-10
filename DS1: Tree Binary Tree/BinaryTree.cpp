#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
class Node
{
public:
    int data;
    Node *left_child;
    Node *right_child;
    Node()
    {
        this->data = data;
        this->left_child = NULL;
        this->right_child = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->left_child = NULL;
        this->right_child = NULL;
    }
};
class BinaryTree
{
private:
    Node *binary_tree;
public:
            BinaryTree          ()
    {
        this->binary_tree = NULL;
    }
            BinaryTree          (Node *bbinary_tree)
    {
        this->binary_tree = bbinary_tree;
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
        this->binary_tree = BuildTreePreIn(in,pre, inStrt, inEnd);

    }
    Node*   Returntreehead      ()
    {
        return binary_tree;
    }
};
int main()
{
    int n, in[MAXN],pre[MAXN];
    cin>>n;
    for(int i=0; i<n; i++) scanf("%d",&pre[i]);
    for(int j=0; j<n; j++) scanf("%d",&in[j]);
	int len = n;

    BinaryTree t1 = BinaryTree();
	t1.BuildTree(in, pre, 0, len - 1);
    t1.print_postorder(t1.Returntreehead());
    printf("\n");
    t1.print_levelorder(t1.Returntreehead());
    printf("\n");
}
