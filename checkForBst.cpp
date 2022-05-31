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
Node *deleteInBst(Node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    if (key < root->data)
    {
        return deleteInBst(root->left, key);
    }
    else if (key > root->data)
    {
        return deleteInBst(root->right, key);
    }
    else
    {
        if (root && root->left == NULL && root->right == NULL)
        {
            return NULL;
        }
        else if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
    }
    Node *temp = inOrderSuccessor(root->right);
    root->data = temp->data;
    root->right = deleteInBst(root->left, temp->data);
    return root;
}
bool isBst(Node *root, Node *min, Node *max)
{
    if (root == NULL)
    {
        return true;
    }
    if (min != NULL && root->data <= min->data)
    {
        return false;
    }
    if (max != NULL && root->data >= max->data)
    {
        return false;
    }
    bool leftValid = isBst(root->left, min, root);
    bool rightValid = isBst(root->right, root, max);
    return leftValid && rightValid;
}
int main()
{
    struct Node *root = NULL;
    root = insertBst(root, 2);
    insertBst(root, 1);
    insertBst(root, 3);
    if (isBst(root, NULL, NULL))
    {
        cout << "valid Bst" << endl;
    }
    else
        cout << "invalid bst" << endl;

    return 0;
}