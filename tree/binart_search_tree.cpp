// insertion n seraching and deletion
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

struct node*insertBST(struct node*root, int val)
{
    if(root==NULL)
     return new node(val);
    if(val<root->data)
     root->left=insertBST(root->left,val);
    if(val>root->data)
      root->right=insertBST(root->right, val);
    return root;
}
void inorder(struct node*root)
{
    if(root==NULL)
       return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
node*searchINBST(struct node*root,int key)
{
    if(root==NULL)
     return NULL;
    if(root->data==key)
     return root;
    if(key<root->data)
     return searchINBST(root->left, key);

    return searchINBST(root->right, key);
}
node*inorderSucc(node*root)
{
        node*curr=root;
        while(curr && curr->left !=NULL)
        {
            curr= curr->left;
        }  
        return curr;
}
node* deleteBST(struct node*root,int key)
{
    if(key < root->data)
     root->left=deleteBST(root->left, key);
    else if(key > root->data)
      root->right= deleteBST(root->right, key);
    else
    {
        // case 1: no child or one child
             if(root->left==NULL)
               {
                   node*temp=root->right;
                   free(root);
                   return temp;
               }
               else if(root->right==NULL)
               {
                   node*temp=root->left;
                   free(root);
                   return temp;
               }
        // case 3: two child 
              node*temp=inorderSucc(root->right);
              root->data=temp->data;
              root->right=deleteBST(root->right, temp->data);

    }
    return root;  
}
int main()
{
    struct node*root;
    root=NULL;
    int n;
    cout<<" Enter the no of elements you wanna enter :";
    cin>>n;
    int arr[n];
    cout<<endl<<"ENter the elements";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            root=insertBST(root,arr[i]);
        }
        else
        {
                insertBST(root,arr[i]);
        }
    }
    inorder(root);
    cout<<endl;
    int key;
    cout<<" Enter the key you wanna search:";
    cin>>key;
    if(searchINBST(root,key) == NULL)
    {
        cout<<" NO exist";
    }
    else
    {
        cout<<" IT exist";
    }
    root=deleteBST(root,key);
    cout<<" The new inorder sequence after the key:";
    inorder(root);
    return 0;
}