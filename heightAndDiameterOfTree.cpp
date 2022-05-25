#include<iostream>
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
int calHeight(Node * root)
{
    if(root==NULL)
    {
        return 0;

    }
    int lHeight=calHeight(root->left);
    int rHeight=calHeight(root->right);

    return max(lHeight,rHeight)+1;
}
int calDiameter(Node * root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lHeight=calHeight(root->left);
    int rHeight=calHeight(root->right);

    int currDiameter=lHeight+rHeight+1;

    int lDiameter=calDiameter(root->left);
    int rDiameter=calDiameter(root->right);

    return max(currDiameter,max(lDiameter,rDiameter));
}
int caldiameter(Node * root,int * height)
{
    if(root==NULL)
    {
        *height=0;
        return 0;
    }
    int lh=0,rh=0;
    int lDiameter=caldiameter(root->left,&lh);
    int rDiameter=caldiameter(root->right,&rh);

    int currDiameter=lh+rh+1;
    *height=max(lh,rh)+1;
    

    return max(currDiameter,max(lDiameter,rDiameter));
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
    cout<<calHeight(root);
    cout<<endl;
    cout<<calDiameter(root);
    cout<<endl;
    int height=0;
    cout<<caldiameter(root,&height);
    return 0;

}