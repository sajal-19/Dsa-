#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *next;
};
struct node* last=NULL;

void create()
{   
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value :");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(last==NULL)
    {
        last=newnode;
        last->next=last;
    }
    else
    {
          newnode->next=last->next;
          last->next=newnode;
    }
}

void delete_from_front()
{
    struct node*temp;
    temp=last->next;
  if(last==NULL)
       printf("no data in linked list:");
  else
  {
         last->next=temp->next;
  }
 free(temp);
}
void delete_from_end()
{
 if(last==NULL)
       printf("no data in linked list:");
else
{
     struct node*temp;
     temp=last->next;
     while(temp->next!=last)
     {
         temp=temp->next;
     }
     temp->next=last->next;
     last=temp;

}
}
void delete_from_ith_position()
{
     int pos,i=1;
    struct node* temp,*temp1;
    temp=last->next;
    printf("Enter the position:");
    scanf("%d",&pos);
    
     if(last==NULL)
       printf("no data in linked list:");
    else
    {
        while(i<pos)
        {
            temp1=temp;
            temp=temp->next;
            i++;
        }
        temp1->next=temp->next;
        free(temp);
    }
}
 
void display()
{
       struct node*temp,*temp1;
       temp1=last->next;
       temp=last;
       while(temp1!=temp)
       {
           printf("%d ",temp1->data);
           temp1=temp1->next;
       }
       printf("%d ",temp1->data);
  printf("\n");
}
int main()
{
    int choice;
    printf("1.create\n2.delete_from_front\n3.delete_from_end\n4.delete_from_ith_position\n5.display\n6.exit\n");
    do
    {
        printf("Enter the choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
             delete_from_front();
             break;
        case 3:
             delete_from_end();
             break;
        case 4:
             delete_from_ith_position();
             break;
        case 5:
             display();
             break;
        default:
            break;
        }
    } while (choice!=6);

   return 0;
}