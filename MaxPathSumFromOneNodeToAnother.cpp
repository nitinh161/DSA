#include <bits/stdc++.h>
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
int maxPathSumUtil(Node *root, int &ans)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = maxPathSumUtil(root->left, ans);
    int right = maxPathSumUtil(root->right, ans);

    int nodemax = max(max(root->data, root->data + left + right),
                          max(root->data + left, root->data + right));
    ans = max(ans, nodemax);
    int singlePathSum = max(root->data, max(root->data + left, root->data + right));
    return singlePathSum;
}
int maxPathSum(Node *root)
{
    int ans = INT_MIN;
    maxPathSumUtil(root, ans);

    return ans;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    // root->left->right = new Node(5);

    // root->right->left = new Node(6);
    root->right->right = new Node(5);

    Preorder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    PostOrder(root);
    cout << endl;
    cout << maxPathSum(root);
    return 0;
}