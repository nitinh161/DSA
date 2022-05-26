#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
void Preorder(struct Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}
void inOrder(struct Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void PostOrder(struct Node *root)
{
    if (root == NULL)
        return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}
void printSubTreeNodes(Node *root, int k)
{
    if (root == NULL || k < 0)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    printSubTreeNodes(root->left, k - 1);
    printSubTreeNodes(root->right, k - 1);
}
int printNodeAtKth(Node *root, Node *target, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root == target)
    {
        printSubTreeNodes(root, k);
        return 0;
    }
    int dl = printNodeAtKth(root->left, target, k);
    if (dl != -1)
    {
        if (dl + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printSubTreeNodes(root->right, k - dl - 2);
        }
        return 1 + dl;
    }
    int dr = printNodeAtKth(root->right, target, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printSubTreeNodes(root->left, k - dr - 2);
        }
        return 1 + dr;
    }
    return -1;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Preorder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    PostOrder(root);
    cout << endl;

    printNodeAtKth(root, root->left, 3);
    return 0;
}