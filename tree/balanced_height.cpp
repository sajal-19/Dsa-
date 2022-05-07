// time complexity is .
#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
    int data;
    struct node*left;
    struct node*right;

    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};
 struct node*buildTree()
 {
     int val;
     cout<<" Enter the value: ";
     cin>>val;
     if(val==-1)
      return NULL;
     struct node*newnode= new node(val);
     cout<<"Enter the left child of "<<val;
     newnode->left=buildTree();
     cout<<"Enter the right child of "<<val;
     newnode->right=buildTree();
      
    return newnode;
 }
 int height(struct node*root)
 {
     if(root==NULL)
      return 0;
    return max(height(root->left),height(root->right))+1;
 }
 bool isBalanced(struct node*root)
 {
     if(root==NULL) 
      return true;
    if(isBalanced(root->left)==false )
      return false;
    if(isBalanced(root->right)==false)
     return false;

     int lh=height(root->left);
     int rh=height(root->right);
    if(abs(lh-rh)<=1)
      return true;
    else
       return false;

 }
 /* here we reduce the time complexity of o(n^2) ---> o(n) */
 bool isBalanced(struct node*root ,int *height)
 {
      if(root==NULL) 
      {
          *height=0;
        return true;
       }
      int lh=0,rh=0;
      if(isBalanced(root->left,&lh)==false )
      return false;
    if(isBalanced(root->right,&rh)==false)
     return false;

     *height=max(lh,rh)+1;
      if(abs(lh-rh)<=1)
         return true;
    else
       return false;

 }

 
void preorder(struct node*root)
{
    if(root==NULL)
     return;
     cout<<root->data<<" ";
     preorder(root->left);
     preorder(root->right);
}
int main()
{
    struct node*root;
    root=NULL;
    root=buildTree();
    preorder(root);
    cout<<endl;
    /*
    if(isBalanced(root)==true)
     cout<<"balanced tree";
    else
      cout<<"Unbalanced tree";
    */
      int height=0;
       if(isBalanced(root, &height)==true)
     cout<<"balanced tree";
    else
      cout<<"Unbalanced tree";
    
    return 0;
}