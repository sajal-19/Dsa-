// circular _ queue through array 
#include<stdio.h>
# define max 5
typedef struct create
{
 int rear,front;
 int n;
 int arr[max];
}create;
void enqueue(create *c)
{
   if(((c->rear+1)% max) ==c->front &&  c->rear!=-1)  // for circular queue
      printf("queue IS FULL\n");
    else
    {
        if(c->front==-1)
            c->front=0;
     c->rear=(c->rear+1)%max;
   
    printf("enter the element:");
    scanf("%d",&c->arr[c->rear]);
    }
}
void dequeue(create *c)
{
     if(c->front==-1)
       printf("under flow\n");
      else
      {
          if(c->front==c->rear)
             c->front=-1;
            else
              c->front=(c->front+1)%max;
      }
    
}
void display(create *c)
{ 
    int i;
    
    if(c->front==-1)
      printf("under flow");
  
    for(i=c->front;i!=c->rear;i=(i+1)%max)
        printf("%d\n",c->arr[i]);
      printf("%d\n",c->arr[i]); 
    printf("\n");

}



int main()
{
    create *c;
    c->rear=-1;
    c->front=-1;
    int choice=1;
    //printf(" enter value of n:");
      //  scanf("%d",&n);
    printf(" 1. FOR PUSH\n 2. POP\n 3. DISPLAY\n 4. EXIT\n");
    do
  {
    switch (choice)
    {
    case 1:
        enqueue(c);
        break;
    
    case 2:
       dequeue(c);
       break;
    case 3:
       display(c);
       break;
    default:
        break;
    } 
  printf("ENter the choice here:");
  scanf("%d",&choice);
  }
   while(choice!=4);
  return 0;
}