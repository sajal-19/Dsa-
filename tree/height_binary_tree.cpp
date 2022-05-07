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
int height(struct node*root)
{
    if(root==NULL)
       return 0;
    return max(height(root->left) , height(root->right))+1;
}
int calcDiameter( struct node*root)
{
    if(root==NULL)
       return 0;
      int lh=height(root->left);
      int rh=height(root->right);
      int curr=lh+rh+1; 

      int ld=calcDiameter(root->left);
      int rd=calcDiameter(root->right);
      return max(curr,max(ld,rd));
}
/*alterantive approch to reduce time complexity of diameter
  here no any other function is required to calcluate the height
  
int calcDiameter( struct node*root ,int *height)
{
    if(root==NULL)
    { *height=0;
       return 0;
    }
      int lh=0;
      int rh=0;
      int ld=calcDiameter(root->left,&lh);
      int rd=calcDiameter(root->right,&rh);
       int curr=lh+rh+1; 
       *height=max(lh,rh)+1;
      return max(curr,max(ld,rd));
}
*/
struct node*buildTree()
{      
       int val;
       cout<<"Enter the value ";
       cin>>val;
       if(val==-1)
        return NULL;
       struct node*newnode=new node(val);
       cout<<"Enter the left child of "<<val<<" ";
       newnode->left=buildTree();
        cout<<"Enter the right child of "<<val<<" ";
       newnode->right=buildTree();
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
     struct node*root;
     root=NULL;
     root=buildTree();
     cout<<" The inorder travesal"<<endl;
     inorder(root);
     cout<<endl;
     cout<<" the height is:"<<height(root)<<endl;
     cout<<" the diameter is:"<<calcDiameter(root);
    return 0;
}
