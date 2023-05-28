#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
typedef struct node *NODE;
NODE create_node();
int length(NODE head);
NODE insert_front(NODE head);
NODE insert_end(NODE head);
void display(NODE head);
NODE insert_position(NODE head);
NODE delete_end(NODE head);
NODE delete_front(NODE head);
NODE delete_position(NODE head);
void reversing(NODE head);
int main()
{
    NODE head=NULL;
    int n;
    while(1)
    {
        printf("1:insert front 2:insert end 3:insert position 4:delete end 5:delete front 6:delete position 7:Reversing 8:display\n");
        printf("Enter the choice \n");
        scanf("%d",&n);
        if(n==1)
        {
            head=insert_front(head);
        }
        else if(n==2)
        {
            head=insert_end(head);
        }
        else if(n==3)
        {
            head=insert_position(head);
        }
        else if(n==4)
        {
            head=delete_end(head);
        }
        else if(n==5)
        {
            head=delete_front(head);
        }
        else if(n==6)
        {
            head=delete_position(head);
        }
        else if(n==8)
        {
            display(head);
        }
        else if(n==7)
        {
            reversing(head);
        }
        else
        {
            printf("Invalid choice\n");
            exit(0);
        }

    }
}
NODE create_node()
{
    NODE newnode;
    newnode=malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d",&newnode->data);
    newnode->link=NULL;
    return newnode;
}
NODE insert_front(NODE head)
{
    NODE cur,newnode;
    newnode=create_node();
    if(head==NULL)
    {
        head=newnode;
        head->link=NULL;
    }
    else
    {
        newnode->link=head;
        head=newnode;
    }
    return head;
}
NODE insert_end(NODE head)
{
    NODE cur,newnode;
    newnode=create_node();
    if(head==NULL)
    {
        head=newnode;
        head->link=NULL;
    }
    else
    {
        cur=head;
        while(cur->link!=NULL)
        {
            cur=cur->link;
        }
        cur->link=newnode;
        newnode->link=NULL;
    }
    return head;
}
NODE insert_position(NODE head)
{
    NODE newnode,prev,cur;
    int k,m,count=0;
    m=length(head);
    printf("Enter the position you want to add the node\n");
    scanf("%d",&k);
    if(k==1)
    {
        head=insert_front(head);
    }
    else if(k==m)
    {
        head=insert_end(head);
    }
    else
    {
        cur=head;
        prev=head;
        newnode=create_node();
        while(cur!=NULL)
        {
            prev=cur;
            cur=cur->link;
            count++;
            if(count==k)
            {
                prev->link=newnode;
                newnode->link=cur;
                cur=newnode->link;
            }
        }
    }
    return head;
}
NODE delete_end(NODE head)
{
    NODE cur=head,prev=head;
    if(head==NULL)
    {
        printf("THe linked list is empty\n");
    }
    else
    {
        cur=head;
        while(cur->link!=NULL)
        {
            prev=cur;
            cur=cur->link;
        }
        prev->link=NULL;
        free(cur);
        cur=prev->link;
    }
    return head;
}
NODE delete_front(NODE head)
{
    NODE cur;
    if(head==NULL)
    {
        printf("The linked list is empty\n");
    }
    else
    {
        cur=head;
        head=head->link;
        free(cur);
        cur=head;
    }
    return head;
}
NODE delete_position(NODE head)
{
    NODE cur,prev;
    int k,l;
    l=length(head);
    printf("Enter the position that you want to delete\n");
    scanf("%d",&k);
    int count=0;
    if(k==1)
    {
        head=delete_front(head);
    }
    else if(k==l)
    {
        head=delete_end(head);
    }
    else
    {
        prev=head;;
        cur=head;
        while(cur!=NULL)
        {
         prev=cur;
         cur=cur->link;
         count++;
         if(count==k-1)
         {
             prev->link=cur->link;
             free(cur);
             cur=prev->link;
         }
        }
    }
    return head;
}
int length(NODE head)
{
    int m=0;
    NODE cur;
    if(head==NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        cur=head;
        while(cur!=NULL)
        {
            m++;
            cur=cur->link;
        }
    }
    return m;
}
void display(NODE head)
{
    NODE cur;
    if(head==NULL)
    {
        printf("The linked list is empty\n");
    }
    else
    {
        cur=head;
        while(cur!=NULL)
        {
            printf("%d->",cur->data);
            cur=cur->link;
        }
        printf("\n");
    }
}
void reversing(NODE head)
{
    NODE cur,temp;
    cur=head;
    temp=head;
    int l;
    l=length(head);
    int a[l],i=0;
    int k;
    while(cur!=NULL)
    {
        a[i]=cur->data;
        cur=cur->link;
        i++;
    }
    cur=head;
    i=l-1;
    while(cur!=NULL)
    {
        cur->data=a[i];
        cur=cur->link;
        i--;
    }
    display(head);
}
