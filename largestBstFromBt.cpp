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
        int data = val;
        left = NULL;
        right = NULL;
    }
};
struct info
{
    int size;
    int min;
    int max;
    int ans;
    bool isBst;
};
info largestBstinBt(Node *root)
{
    if (root == NULL)
    {
        return {0, INT_MIN, INT_MAX, 0, true};
    }
    if (root->left == NULL && root->right == NULL)
    {
        return {1, root, root, 1, true};
    }

    info leftInfo = largestBstinBt(root->left);
    info rightInfo = largestBstinBt(root->right);

    info curr;

    curr.size = (1 + leftInfo.size + rightInfo.size);
    if (leftInfo.isBst && rightInfo.isBst && leftInfo.max < root->data && rightInfo.min > root->data)
    {
        curr.min=min(leftInfo.min,min(rightInfo.min,root->data));
        curr.max=max(rightInfo.max,max(leftInfo.max,root->data));

        curr.ans=curr.size;
        curr.isBst=true;
        return curr;
    }
    curr.ans=max(leftInfo.ans ,rightInfo.ans);
    curr.isBst=false;
    return curr;
}
int main()
{

    return 0;
}