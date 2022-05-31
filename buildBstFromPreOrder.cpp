#include <iostream>
#include <limits.h>
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
    preOrder(root->left);
    cout << root->data << " ";
    preOrder(root->right);
}
void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    preOrder(root->left);
    preOrder(root->right);
    cout << root->data << " ";
}
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
Node *searchInBst(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }

    if (root->data > key)
    {
        return searchInBst(root->left, key);
    }
    else
    {
        return searchInBst(root->right, key);
    }
}
Node *inOrderSuccessor(Node *root)
{
    Node *curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}
// Node *deleteInBst(Node *root, int key)
// {
//     if (root == NULL)
//     {
//         return root;
//     }
//     if (key < root->data)
//     {
//         return deleteInBst(root->left, key);
//     }
//     else if (key > root->data)
//     {
//         return deleteInBst(root->right, key);
//     }
//     else
//     {
//         if (root->left == NULL && root->right == NULL)
//         {
//             return NULL;
//         }
//         else if (root->left == NULL)
//         {
//             Node *temp = root->right;
//             free(root);
//             return temp;
//         }
//         else if (root->right == NULL)
//         {
//             Node *temp = root->left;
//             free(root);
//             return temp;
//         }
//     }
//     Node *temp = inOrderSucessor(root->right);
//     root->data = temp->data;
//     root->right = deleteInBst(root->left, temp->data);
//     return root;
// }
Node *constructBstFromPreOrder(int preorder[], int *preOrderIdx, int key, int min, int max, int n)
{
    if (*preOrderIdx >= n)
    {
        return NULL;
    }
    Node *root = NULL;
    if (key > min && key < max)
    {
        root = new Node(key);
        *preOrderIdx = *preOrderIdx + 1;

        if (*preOrderIdx < n)
        {
            root->left = constructBstFromPreOrder(preorder, preOrderIdx, preorder[*preOrderIdx], min, key, n);
        }
        if (*preOrderIdx < n)
        {
            root->right = constructBstFromPreOrder(preorder, preOrderIdx, preorder[*preOrderIdx], key, max, n);
        }
    }
    return root;
}

int main()
{
    // struct Node *root = NULL;
    // root = insertBst(root, 2);
    // insertBst(root, 1);
    // insertBst(root, 3);

    // inOrder(root);
    int pre[] = {10, 5, 1, 7, 40, 50};
    int preIndex = 0;
    int size = sizeof(pre) / sizeof(pre[0]);
    Node *root = constructBstFromPreOrder(pre, &preIndex, pre[0], INT_MIN, INT_MAX, size);
    preOrder(root);
    return 0;
}