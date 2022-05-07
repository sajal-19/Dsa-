#include<stdio.h>
#include<malloc.h>
typedef struct node
{
    int data;
    struct node*next;
}node;
node *front=NULL;
node *rear=NULL;
void enqueue()
{  int x;
     node*newnode;
     newnode=(node*)malloc(sizeof(node));
      printf("Enter the value:");
        scanf("%d",&x);
         newnode->data=x;
         newnode->next=NULL;
         
     if(front==NULL && rear==NULL)
     {
         front=newnode;
         rear=newnode;
     }
     else
     {
       rear->next=newnode;
         rear=newnode;
         rear->next=front;

     }
}
void dequeue()
{
    node*temp;
    if(front==NULL)
      printf("queue is empty");
    else
    {
        temp=front;
        front=front->next;
        rear->next=front;
        free(temp);
    }

}
void display()
{
    node*temp=front;
    while(temp->next!=front)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
     printf("%d\t",temp->data);
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
            enqueue();
            break;
        case 2:
             dequeue();
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