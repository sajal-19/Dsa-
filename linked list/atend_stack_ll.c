// linked list program normal creation
#include<stdio.h>
#include<malloc.h>
 struct node
{
    int data;
   struct node *next;

};
typedef struct node node;
node*head=NULL;
void push()
{
   node *temp,*newnode;
   int d;
   //temp=(node*)malloc(sizeof(node));
   newnode=(node*)malloc(sizeof(node));
   printf("enter the value");
   scanf("%d",&d);
   newnode->data=d;
   newnode->next=NULL;
   if(head==NULL)
   {
       head=newnode;
        
   } 
   else
   { 
       temp=head;
    while(temp->next!=NULL)
    {
      
     temp=temp->next;
     }
   temp->next=newnode;
   }

}
void pop()
{
    node*temp=head;
    head=temp->next;
    int a=temp->data;
    printf("the popped value:%d\n",a);
    free(temp);

}
void display()
{
    node*temp=head;
    while(temp !=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    int choice;
    printf("\n1. PUSH\n2. POP\n3. DISPLay\n4. EXIT\n");
    do
    {
        printf("enter choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
             pop();
             break;
        case 3:
             display();
             break;

        default:
            break;
        }
    } while (choice!=4);
    return 0;
    
}