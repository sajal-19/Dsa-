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
int search(int inorder[], int start, int end, int curr)
{
    for(int i=start;i<=end;i++)
    {
        if(inorder[i]==curr)
          return i;
    }
}
 struct node*buildtree( int preorder[],int inorder[],int start,int end)
 {
     static int idx=0;
     if(start>end)
     { 

        return NULL;
     }
     else
     {
     
     int curr=preorder[idx];
     struct node*newnode = new node(curr);
     idx++;
     int pos=search(inorder, start,end,curr);
     newnode->left=buildtree(preorder,inorder,start,pos-1);
     newnode->right=buildtree(preorder,inorder,pos+1,end);
    
     return newnode;
     }
 }
 void Inorder(struct node*root)
 {
     if(root== NULL)
       return;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
    
}
int main()
{
    int preorder[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};
    //build a tree
    struct node *root=buildtree(preorder,inorder,0,4);
    Inorder(root);
    return 0;
}