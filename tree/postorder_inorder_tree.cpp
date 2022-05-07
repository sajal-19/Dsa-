#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node*left;
    struct node*right;
     
     node( int val)
     {
         data=val;
         left=NULL;
         right=NULL;
    }
};
int search(int inorder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if(inorder[i]==curr)
         return i;
    }
    return -1;
}
void Inorder(struct node*root)
{
    if(root==NULL)
     return;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}
struct node*bulidtree(int postorder[], int inorder[], int start, int end)
{
      static int idx=end;
      if(start>end)
      {  return NULL;}
      int curr=postorder[idx];
        idx--;
      struct node*newnode=new node(curr);
    
      if(start==end)
      {
          return newnode;
      }
           int pos=search(inorder,start, end, curr);
           newnode->right=bulidtree(postorder, inorder,pos+1,end);
           newnode->left=bulidtree(postorder, inorder,start,pos-1);
           return newnode;
}
int main()
{
    int postorder[]={4,2,5,3,1};
    int inorder[]={4,2,1,5,3};
    //building the tree from postorder and inorder 
    struct node*root=bulidtree(postorder, inorder,0,4);
    Inorder(root);
    cout<<endl;
    return 0;
}