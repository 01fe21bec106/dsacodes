#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct node
{
    int weight;
    int number;
    char a[20],b[20],c[20];
    struct node *link;
};
typedef struct node *NODE;
void display_lightweight(NODE head);
void display_heavyweight(NODE head);
void display_min(NODE head);
NODE insert_end(NODE head)
{
    NODE cur=head;
    NODE newnode=malloc(sizeof(struct node));
    scanf("%d %s %s %s %d",&newnode->number,newnode->a,newnode->b,newnode->c,&newnode->weight);

    if(head==NULL)
    {
        head=newnode;
    }
    else{
        while(cur->link!=NULL)
            cur=cur->link;
        cur->link=newnode;
    }
    newnode->link=NULL;
    return head;
}
int main() {
    int n;
    scanf("%d",&n);
    NODE head=NULL;
    int i;
    for(i=0;i<n;i++) { head=insert_end(head); } display_lightweight(head); display_heavyweight(head); display_min(head); return 0; } void display_lightweight(NODE head) { NODE newnode=head; while(newnode!=NULL) { if(newnode->weight<30) printf("%d %s %s %s %d\n",newnode->number,newnode->a,newnode->b,newnode->c,newnode->weight);
        newnode=newnode->link;
    }
      printf("\n");
}
void display_heavyweight(NODE head)
{
    NODE cur=head;
    while(cur!=NULL)
    {
        if(cur->weight>=30)
            printf("%d %s %s %s %d\n",cur->number,cur->a,cur->b,cur->c,cur->weight);
        cur=cur->link;
    }
      printf("\n");
}
void display_min(NODE head)
{
    NODE min=head;
    NODE cur=head;
    while(cur!=NULL)
    {
        if(min->weight>cur->weight)
            min=cur;
        cur=cur->link;
    }
    printf("%d %s %s %s %d\n",min->number,min->a,min->b,min->c,min->weight);
}
