#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    int level;
    struct node *left;
    struct node *right;
};
typedef struct node *NODE;
NODE create_node(int key);
NODE insertion(NODE root,int key);
void level_order(NODE root);
int height(NODE root);
void printlevel_order(NODE root , int i);
int main()
{
    NODE root=NULL;
    int m,key;
    while(1)
    {
        printf("1:Insertion 2:Level order display 3:exit\n");
        scanf("%d",&m);
        if(m==1)
        {
            printf("Enter the data \n");
            scanf("%d",&key);
            root=insertion(root,key);
        }
        else if(m==2)
        {
            level_order(root);
        }
        else if(m==3)
        {
            exit(0);
        }
        else
        {
            printf("Invalid choice\n");
        }
    }
}
NODE create_node(int key)
{
    NODE newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=key;
    newnode->right=newnode->left=NULL;
    newnode->level=1;
    return newnode;
}
NODE insertion(NODE root,int key)
{
    NODE newnode;
    if(root==NULL)
    {
        newnode=create_node(key);
        return newnode;
    }
    else
    {
        if(key>=root->data)
        {
            root->right=insertion(root->right,key);
        }
        else
        {
            root->left=insertion(root->left,key);
        }
    }
    root->level=1+root->level;
    return root;
}
int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int height(NODE root)
{
    if(root==NULL)
        return 0;
    else
        return root->level;
}
void level_order(NODE root)
{
    int ht;
    ht=height(root);
    for(int i=1;i<=ht;i++)
    {
        printlevel_order(root,i);
        printf("\n");
    }
}
void printlevel_order(NODE root , int i)
{
    NODE k;
    k=root;
    int m;
    m=i;
    if(k==NULL)
    {
        return;
    }
    else if(i==1)
    {
        printf("%d ",root->data);
    }
    else
    {
        printlevel_order(root->left,i-1);
        printlevel_order(k->right,m-1);
    }
}
