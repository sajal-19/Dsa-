#include<iostream>
#include<algorithm>
#include<limits.h>
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
void preorder(struct node*root)
{
    if(root==NULL)
    {
     return ;
    }
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
}
node*constructBST( int preorder[], int*preorderidx, int key, int min,int max,int n)
{
    if(*preorderidx >=n)
     return NULL;
    node*root=NULL;
    if( key >min && key<max)
    {
           root= new node(key);
           *preorderidx= *preorderidx +1;

        if(*preorderidx <n)
        {
            root->left=constructBST(preorder, preorderidx,preorder[*preorderidx],min,key,n);
        }
               if(*preorderidx <n)
        {
            root->right=constructBST(preorder, preorderidx,preorder[*preorderidx],key,max,n);
        }
    }
  return root;
}
int main()
{
    struct node*root;
   int n;
   cout<<"Enter the number of elements in bst :";
   cin>>n;
   int arr[n];
   cout<<" Enter the elements :";
   for(int i=0;i<n;i++)
   {
       cin>>arr[i];
   }
   int idx=0;
   int key=arr[0];
   root=constructBST(arr,&idx,key,INT_MIN,INT_MAX,n);
   preorder(root);
   return 0;
}