#include<iostream>
#include<queue>
using namespace std;
struct node
{
    int data;
    struct node*left;
    struct node *right;

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
    cout<<" Enter the value : ";
    cin>>val;
    if(val==-1)
    {
        return NULL;
    } 
    struct node*newnode= new node(val);
    cout<<" Enter the data of the left child of : "<<val;
    newnode->left=buildTree();
    cout<<"Enter the data of the right child of: "<<val;
    newnode->right=buildTree();
     
    return newnode;
}
void inorder(struct node*root)
{
    if(root==NULL)
     return ;
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}
void leftview(struct node*root)
{
    if(root==NULL)
     return;
    
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            struct node*curr=q.front();
            q.pop();
            if(i==0)
            {
               cout<<curr->data<<" ";
            }
            if(curr->left !=NULL)
             q.push(curr->left);
            if(curr->right !=NULL)
              q.push(curr->right);
        }
    }
}
int main()
{
    struct node*root;
    root=NULL;
    root=buildTree();
    inorder(root);
    cout<<endl;
    cout<<" THe left view of the tree:";
    leftview(root);
    return 0;
}