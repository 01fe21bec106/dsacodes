#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct node
{
  int data;
  struct node *link;
};
typedef struct node *NODE;
void display(NODE head)
{
    NODE cur=head;
    if(head==NULL)
    {
        printf("No devotees to worship.");
    }
    else{
    printf("Remaining devotees: ");
    while(cur!=NULL)
    {
        printf("%d ",cur->data);
        cur=cur->link;
    }
    }
}
NODE insert_front(NODE head)
{
    NODE newnode=malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->link=head;
    head=newnode;
    return head;
}
NODE search_and_delete_highest(NODE head)
{
    NODE cur=head;
    NODE max=head;
    NODE prev=NULL;
    NODE PREV=NULL;
    while(cur!=NULL)
    {
        if(max->datadata)
        {
            PREV=prev;
            max=cur;
        }
        prev=cur;
        cur=cur->link;
    }
    if(max==head)
        head=max->link;
    else
        PREV->link=max->link;
    printf("Allowed for worship: %d\n",max->data);
    free(max);
    return head;
}
int main() {
    NODE head=NULL;
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        head=insert_front(head);
    }
    head=search_and_delete_highest(head);
    display(head);
    return 0;
}
