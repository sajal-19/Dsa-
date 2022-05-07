// time complexity is o(n).
#include<iostream>
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
void sum_replacement(struct node*root)
{
    if(root==NULL)
       return;
    sum_replacement(root->left);
    sum_replacement(root->right);
    if(root->left !=NULL)
    {
        root->data+=root->left->data;
    }
    if(root->right !=NULL)
    {
        root->data+=root->right->data;
    }
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
    sum_replacement(root);
    cout<<endl;
    preorder(root);
    return 0;
}