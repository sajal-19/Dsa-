#include<stdio.h>
#define max 10
int queue[max];
int front=-1;
int rear=-1;
void insert_front();
void insert_rear();
int delete_front();
int delete_rear();
int isfull();
int isempty();
void display();

int main()
{
    int choice=1;
 do
 {
     printf("\n1.Insert at front.\n2.Insert at rear.\n3.Delete at front.\n4.Delete at end.\n5.Display\n6.exit\n");
     printf("Enter the choice:");
     scanf("%d",&choice);

    switch (choice)
    {
    case 1:
         insert_front();
        break;
    case 2:
         insert_rear();
        break;
    case 3:
         printf("\nThe deleted element:%d\n",delete_front());
        break;
    case 4:
        printf("\nThe deleted element:%d\n", delete_rear());
        break;
    case 5:
          display();
        break;
    case 6:
         exit(1);
         
    default:
        printf(" Choice dekh ke daaalo yarr!!");
        break;
    }
 } while (choice!=4);
 return 0;
}
int isfull()
{
    if((rear==max-1 && front==0) || (front==rear+1))
       return 1;
    return 0;
}
int isempty()
{
   if(front==-1)
    return 1;
  return 0;
}
void insert_front()
{
    if(isfull())
     printf("\nQueue is full\n");
    else
    {
        int item;
        printf("\nEnter the data\n");
        scanf("%d",&item);
    if(front==-1)
    {
        front=0;
        rear=0;
    }
    else if(front==0)
      front=max-1;
    else
      front=front-1;
   queue[front]=item;
    }
}
void insert_rear()
{
    if(isfull())
     printf("\nQueue is full\n");
    else
    {
        int item;
        printf("\nEnter the data\n");
        scanf("%d",&item);
    if(rear==-1)
    {
        front=0;
        rear=0;
    }
    else if(rear==max-1)
      rear=0;
    else
      rear=rear+1;
   queue[rear]=item;
    }
}
int delete_front()
{ 
    int item;
    item=queue[front];
    if(isempty())
     printf("\nQueue is empty:\n");
    if(front==rear)
    {
      front=-1;
      rear=-1;
    }
    else
    {
        if(front==max-1)
         front=-1;
        else
           front=front+1;
    }
    return item;
}
int delete_rear()
{ 
    int item;
    item=queue[rear];
    if(isempty())
     printf("\nQueue is empty:\n");
    if(front==rear)
    {
      front=-1;
      rear=-1;
    }
    else
    {
        if(rear==0)
         rear=max-1;
        else
           rear=rear-1;
    }
    return item;
}
void display()
{
    int i;
    if(isempty())
     printf("\nQueue is empty:\n");
     i=front;
     if(front<=rear)
     {
         while(i<=rear)
            printf("%d ",queue[i++]);
     }
     else
     {
         while(i<=max-1)
          printf("%d ",queue[i++]);
        i=0;
         while(i<=rear)
          printf("%d ",queue[i++]);
     }
     printf("\n");

}