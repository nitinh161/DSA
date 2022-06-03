#include <iostream>
#include <vector>
#include <stack>
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
Node *insertBst(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }
    if (val < root->data)
    {
        root->left = insertBst(root->left, val);
    }
    else
    {
        root->right = insertBst(root->right, val);
    }
    return root;
}
void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
bool isIdentical(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1 == NULL || root2 == NULL)
    {
        return false;
    }

    bool cond1 = root1->data == root2->data;
    bool cond2 = isIdentical(root1->left, root2->left);
    bool cond3 = isIdentical(root1->right, root2->right);
    if (cond1 && cond2 && cond3)
    {
        return true;
    }
    else
        return false;
}

int main()
{
    struct Node *root = NULL;
    root = insertBst(root, 2);
    insertBst(root, 1);
    insertBst(root, 3);

    if(isIdentical(root,root))
    {
        cout<<"Identical"<<endl;
    }
    else
    {
        cout<<"Not Identical"<<endl;
    }
    return 0;
}