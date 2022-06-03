#include <iostream>
#include <vector>
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
vector<Node *> constructTrees(int start, int end)
{
    vector<Node *> trees;
    if (start > end)
    {
        trees.push_back(NULL);
        return trees;
    }
    for (int i = start; i <= end; i++)
    {
        vector<Node *> leftSubTree = constructTrees(start, i - 1);
        vector<Node *> rightSubTree = constructTrees(i + 1, end);

        for (int j = 0; j < leftSubTree.size(); j++)
        {
            Node *left = leftSubTree[j];
            for (int k = 0; k < rightSubTree.size(); k++)
            {
                Node *right = rightSubTree[k];
                Node *node = new Node(i);
                node->left = left;
                node->right = right;
                trees.push_back(node);
            }
        }
    }
    return trees;
}

int main()
{
    vector<Node *> totalTrees = constructTrees(1, 3);
    for (int i = 0; i < totalTrees.size(); i++)
    {
        cout << (i+1)<< " : ";
        preOrder(totalTrees[i]);
        cout << endl;
    }
    return 0;
}