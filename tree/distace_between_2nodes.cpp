// Implementation of binary tree by two methods
#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *left,*right;

    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};
struct node *create()
{
    int val;
     struct node *newnode;
     cout<<" Enter the value:";
     cin>>val;
     if(val==-1)
       return 0;
     newnode=new node(val);
     cout<<" Enter the left child of "<<val<<" ";
      newnode->left=create();
     cout<<" Enter the right child of "<<val<<" ";
      newnode->right=create();
     return newnode;
}
void inorder(struct node *root)
{
    if(root==NULL)
     return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}
struct node*LCA(struct node*root, int n1, int n2)
{
    if(root==NULL)
     return NULL;
    if(root->data==n1 || root->data==n2)
      return root;
    node*leftlca=LCA(root->left,n1,n2);
    node*rightlca=LCA(root->right, n1,n2);
    if(leftlca && rightlca)
     return root;
    if( leftlca != NULL)
     return leftlca;
    return rightlca;
}
int findDist(struct node*root, int k, int dist)
{
    if(root==NULL)
      return -1;
    if(root->data ==k)
     return dist;
    int l=findDist(root->left, k, dist+1);
    if( l!=-1)
     return l;
    int r=findDist(root->right, k, dist+1);
     
}
int disBtwNodes(node*root, int n1 , int n2)
{
    node*lca=LCA(root, n1, n2);
    int d1=findDist(lca,n1,0);
    int d2=findDist(lca, n2,0);
    return d1+d2;
}
int main()
{
   int n1, n2;
 struct node *root;
 root=NULL;
 root=create();
 inorder(root);
 cout<<endl;
 cout<<" Enter the value of n1 & n2 :";
 cin>>n1>>n2;
 cout<<"The distance:"<<disBtwNodes(root,n1,n2);
  return 0;
}