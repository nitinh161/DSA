#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node * left;
    struct Node * right;

    Node (int val)
    {
        data =val;
        left=NULL;
        right=NULL;
    }
};
void Preorder(struct Node * root)
{
    if(root==NULL) return;
    cout<< root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}
void inOrder(struct Node * root)
{
    if(root==NULL) return;
    inOrder(root->left);
    cout<< root->data<<" ";
    inOrder(root->right);
}
void PostOrder(struct Node * root)
{
    if(root==NULL) return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout<< root->data<<" ";
}
int kthLevlSum(Node * root,int k)
{
    if(root==NULL)
    {
        return -1;
    }
    int level=0,sum=0;
    queue<Node *>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node * node=q.front();
        q.pop();
        if(node !=NULL)
        {
            if(level==k)
            {
                sum+=node->data;
            }
            if(node->left)
            {
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }
        }
        else if(!q.empty())
        {
            q.push(NULL);
            level++;
        }
    }
    return sum;
}

int main(){
    struct Node * root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);

    root->left->left=new Node(4);
    root->left->right=new Node(5);

    root->right->left=new Node(6);
    root->right->right=new Node(7);

    Preorder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    PostOrder(root);
    cout<<endl;
    cout<<kthLevlSum(root,1);
    return 0;
}