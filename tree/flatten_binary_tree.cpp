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
void flattenTree(struct node*root)
{
    if(root==NULL|| (root->left==NULL && root->right==NULL))
         return ;
    if(root->left !=NULL)
    {
          flattenTree(root->left);
     
     node*temp=root->right;
     root->right=root->left;
     root->left=NULL;
     
     node*t=root->right;
     while(t->right !=NULL)
     {
        t=t->right;
     }
     t->right=temp;
    }
     flattenTree(root->right);
}
int main()
{

 struct node *root;
 root=NULL;
 root=create();
 inorder(root);
 cout<<endl;
 flattenTree(root);
 inorder(root);
  return 0;
}