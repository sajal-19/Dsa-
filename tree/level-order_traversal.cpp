// The code for level order traversal with algo and countnodes and sumnodes also
/* Algo
1.build a tree
2.call the function levelorder and check if root is null then return
3.if not then  create a queue using stl(to basically avoid the code of queue)
4.then push root element and null
5.then use while till the queue gets empty
    5.1 initilaze the pointer to the front of queue;
    5.2 pop the root
            5.2.1 if elemnent is not null then print data and check the left and right child
            5.2.2 if element is null then just push null for the next level
6. call the function from main 

*/#include<iostream>
#include<queue>
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
void printLevelorder( struct node*root)
{
       if(root==NULL)
        return;
     queue<node*>q;
     q.push(root);
     q.push(NULL);
     while(!q.empty())
     {
         node*newnode=q.front();
         q.pop();
         if(newnode !=NULL)
         {
             cout<<newnode->data<<" ";
             if(newnode->left)
             q.push(newnode->left);
             if(newnode->right)
              q.push(newnode->right);
         }
         else if(!q.empty())
         {
             q.push(NULL);
         }
     }
}
// sum of the data at that particular level...
int ksum(struct node*root,int k)
{
       if(root==NULL)
        return -1;
     queue<node*>q;
     q.push(root);
     q.push(NULL);
     int level=0;
     int sum=0;
     int count=0;
     while(!q.empty())
     {
         node*newnode=q.front();
         q.pop();
         if(newnode !=NULL)
         {
             if(level==k)
             {
                 sum+=newnode->data;
             }
            
             if(newnode->left)
             q.push(newnode->left);
             if(newnode->right)
              q.push(newnode->right);
         }
         else if(!q.empty())
         {
             q.push(NULL);
             level++;
         }
     }
     return sum;
}
int countnodes(struct node*root)
{
    if(root==NULL)
       return 0;
    return countnodes(root->left) + countnodes(root->right)+1;
}
int sumnodes(struct node*root)
{
    if(root==NULL)
       return 0;
    return sumnodes(root->left)+sumnodes(root->right)+root->data;
}
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
     cout<<"The level order traversal"<<endl;
     printLevelorder(root);
     cout<<endl;
     cout<<" The sum at this level"<<ksum(root,2)<<endl;
     cout<<" The total no of nodes in this tree is:"<<countnodes(root)<<endl;
     cout<<" The sum of all the nodes in the tree is:"<<sumnodes(root)<<endl;
     return 0;
}
