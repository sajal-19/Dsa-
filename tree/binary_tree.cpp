//simple binary tree code
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
int main()
{

     /* THis is complier time intialization
     struct node*root=NULL;
      root=new node(10);
       root->left=new node(5);
       root->right=new node(13);
       root->left->left=new node(2);
       root->right->right=new node(15);
       inorder(root);

       10
      / \
     5   13
    /     \
   2       15
   */
  // This is run time intilization
 struct node *root;
 root=NULL;
 root=create();
 inorder(root);
  return 0;
}