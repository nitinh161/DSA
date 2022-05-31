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
void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
Node *constructBstFromSortedArray(int arr[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end) / 2;

    Node *root = new Node(arr[mid]);

    root->left = constructBstFromSortedArray(arr, start, mid - 1);
    root->right = constructBstFromSortedArray(arr, mid + 1, end);
    return root;
}
int main()
{
    int arr[]={1, 2, 3, 4, 5, 6, 7, 8};
    int n = 7;
    Node *root = constructBstFromSortedArray(arr, 0, 7);
    preOrder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;

    return 0;
}