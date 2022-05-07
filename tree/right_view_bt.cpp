// Implementation of binary tree by two methods
#include<iostream>
#include<queue>
using namespace std;
struct Node
{
    int data;
    struct Node *left,*right;

    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};
struct Node *create()
{
    int val;
     struct Node *newnode;
     cout<<" Enter the value:";
     cin>>val;
     if(val==-1)
       return 0;
     newnode=new Node(val);
     cout<<" Enter the left child of "<<val<<" ";
      newnode->left=create();
     cout<<" Enter the right child of "<<val<<" ";
      newnode->right=create();
     return newnode;
}
void rightview(struct Node*root)
{
    if(root==NULL)
    {
         return ;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
          struct  Node*curr=q.front();
            q.pop();
            if(i==n-1)
              cout<<curr->data<<" ";
            if(curr->left !=NULL)
              q.push(curr->left);
            if(curr->right !=NULL)
              q.push(curr->right);
        }
    }
} 
void inorder(struct Node *root)
{
    if(root==NULL)
     return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}
int main()
{

 struct Node *root;
 root=NULL;
 root=create();
 inorder(root);
 cout<<endl;
 cout<<" THe right view is :";
 rightview(root);
  return 0;
}