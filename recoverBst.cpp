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
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void calPointers(Node *root, Node **first, Node **mid, Node **last, Node **prev)
{
    if (root == NULL)
    {
        return;
    }
    calPointers(root->left, first, mid, last, prev);

    if (*prev && root->data < ((*prev)->data))
    {
        if (!*first)
        {
            *first = *prev;
            *mid = root;
        }
        else
        {
            *last = root;
        }
    }
    *prev = root;
    calPointers(root->right, first, mid, last, prev);
}
void restoreBst(Node *root)
{
    Node *first, *mid, *last, *prev;
    first = NULL;
    mid = NULL;
    last = NULL;
    prev = NULL;
    calPointers(root, &first, &mid, &last, &prev);

    if (first && last)
    {
        swap(&(first->data), &(last->data));
    }
    else if (first && mid)
    {
        swap(&(first->data), &(mid->data));
    }
}
int main()
{
    Node *root = new Node(6);
    root->left = new Node(9);
    root->right = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->right = new Node(16);

    inOrder(root);
    cout<<endl;
    restoreBst(root);
    inOrder(root);

    return 0;
}