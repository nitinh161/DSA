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
void zigzagTransversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<Node *> currLevel;
    stack<Node *> nextLevel;
    bool LeftToRight = true;
    currLevel.push(root);

    while (!currLevel.empty())
    {
        Node *temp = currLevel.top();
        currLevel.pop();
        if (temp)
        {
            cout << temp->data << " ";

            if (LeftToRight)
            {
                if (temp->left)
                {
                    nextLevel.push(temp->left);
                }
                if (temp->right)
                {
                    nextLevel.push(temp->right);
                }
            }
            else
            {
                if (temp->right)
                {
                    nextLevel.push(temp->right);
                }
                if (temp->left)
                {
                    nextLevel.push(temp->left);
                }
            }
        }
        if (currLevel.empty())
        {
            LeftToRight = !LeftToRight;
            swap(currLevel, nextLevel);
        }
    }
}

int main()
{
    struct Node *root = NULL;
    root = insertBst(root, 50);
    insertBst(root, 30);
    insertBst(root, 20);
    insertBst(root, 40);
    insertBst(root, 70);
    insertBst(root, 60);
    insertBst(root, 80);

    zigzagTransversal(root);
    return 0;
}