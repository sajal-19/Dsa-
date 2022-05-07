#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *next;
};
struct node* last=NULL;

void insert_at_front()
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
void insert_at_end()
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
          last=newnode;
    }
}
void insert_at_ith()
{
    int pos,i=1;
    struct node*newnode,*temp,*temp1;
    temp=last->next;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the position");
    scanf("%d",&pos);
     if(last==NULL)
    {
        last=newnode;
        last->next=last;
    }
    else
  {
         printf("Enter the value :");
         scanf("%d",&newnode->data);
         newnode->next=NULL;
    while (i<pos)
    {
         temp1=temp;
         temp=temp->next;
         i++;
    }
    newnode->next=temp;
    temp1->next=newnode;
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
    printf("1.insert_at_front\n2.insert_at_end\n3.inser_at_ith_position\n4.display\n4.exit\n");
    do
    {
        printf("Enter the choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            insert_at_front();
            break;
        case 2:
             insert_at_end();
             break;
        case 3:
             insert_at_ith();
             break;
        case 4:
             display();
             break;
        default:
            break;
        }
    } while (choice!=5);

   return 0;
}