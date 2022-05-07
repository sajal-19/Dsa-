#include<stdio.h>
# define max 100
int top;
int n;
int arr[max];

void push()
{
     if(top>=max-1)
      printf("STACK IS FULL\n");
    else
    {
     top++;
    printf("enter the element:");
    scanf("%d",&arr[top]);
    }
}
void pop()
{
     if(top==-1)
      printf("under flow");
    top--;
}
void display()
{
  int i;
  for(i=top;i>=0;i--)
   printf("%d\n",arr[i]);
}


int main()
{
    top=-1;
    int choice=1;
    
    printf(" 1. FOR PUSH\n 2. POP\n 3. DISPLAY\n 4. EXIT\n");
    do
  {
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
  printf("ENter the choice here:");
  scanf("%d",&choice);
  }
   while(choice!=4);
  return 0;
}