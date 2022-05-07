 //deletion in doubly linked list at 
 //1.front 2.end 3. ith position
#include<stdio.h>
#include<malloc.h>
 typedef struct node
{
    int data;
    struct node*prev;
     struct node*next;
} node;
node*head=NULL;
node*temp;
void create()
{
     node*newnode;
     newnode=(node*)malloc(sizeof(node));
     printf("Enter the value in the node:");
     scanf("%d",&newnode->data);
     newnode->prev=NULL;
     newnode->next=NULL;
      if(head==NULL)
      {
          head=newnode;
          temp=newnode;
      }
      else
      {
         temp->next=newnode;
         newnode->prev=temp;
         temp=newnode;
      }

}
void delete_first()
{
    if(head==NULL)
    {
        printf("no data to delete\n");
    }
    else
    {
        head=head->next;
    }
   
}
void delete_middle()
{
    int i=1,pos;
    node*temp1,*ptr;
     temp1=head;
    if(head==NULL)
    {
        printf("no data to delete\n");
    }
    else
    {
        printf("Enter the position uh wanna enter:") ;
        scanf("%d",&pos);
        while (i<pos)
        {
            ptr=temp1;
            temp1=temp1->next;
            i++;
        }
        ptr->next=temp1->next;
        temp1=temp1->next;
        temp1->prev=ptr;
        
    }

}
void delete_end()
{
    if(head==NULL)
    {
        printf("no data to delete\n");
    }
    else
    {
          temp=temp->prev;
          temp->next=NULL;
    }
}

 void display()
 {
  node*temp;
  temp=head;
  while(temp!=NULL)
  {
    printf("%d ",temp->data);
    temp=temp->next;
  }
  printf("\n");
 }

int main()
{
    int choice;
     printf("1.Create\n2.Display\n3.delete_first\n4.delete_middle\n5.delete_end\n6.EXit\n");
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
             display();
             break;
        case 3:
             delete_first();
             break;
        case 4:
             delete_middle();
             break;
        case 5:
              delete_end();
              break;
        default:
            break;
        }
    } while (choice!=6);
    return 0;
}