#include<iostream>
#include<vector>
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
void inorder(struct Node *root)
{
    if(root==NULL)
     return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}
bool getpath(struct Node*root, int key, vector<int>&path)
{
        if(root==NULL)
         return false;
         path.push_back(root->data);
         if(root->data==key)
          return true;
        if(getpath(root->left, key, path) || getpath(root->right , key, path))
              return true;
        path.pop_back();
         return false;
}
int LCA(struct Node*root, int n1, int n2)
{
    vector<int> path1, path2;
    if(!getpath(root,n1,path1) || !getpath(root, n2, path2))
    {
        return -1;
    }
    int pc;
    for(pc=0;pc<path1.size() && path2.size();pc++)
    {
        if(path1[pc] !=path2[pc])
          break;
    }
    return path1[pc-1];
}
// second approch of lowest common ancestor
Node* lCA2( struct Node*root, int n2, int n1)
{
    if(root==NULL)
       return NULL;
    if(root->data ==n1 || root->data==n2)
      return root;
      Node *leftlca=lCA2(root->left, n2, n1);
      Node *rightlca=lCA2(root->right, n2, n1);
    if(leftlca && rightlca)
    {
      return root;
    }
    if(leftlca !=NULL)
    {
      return leftlca;
    }
       return rightlca;
}
int main()
{
    int n1, n2;
 struct Node *root;
 root=NULL;
 root=create();
 inorder(root);
 cout<<endl;
 cout<<"Enter the value of n1 &n2 : ";
 cin>>n1>>n2;
 cout<<" LCA: "<<LCA(root, n1,n2);
 Node *lca= lCA2(root, n2,n1);
 cout<<" lCA2 :"<<lca->data;
  return 0;
}