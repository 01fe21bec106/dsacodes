#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct node
{
    char ws[30];
    int yr;
    struct node *link;
};
typedef struct node *NODE;
NODE newnode,cur;
NODE createnode();
NODE insert_e(NODE tail);
void display(NODE tail);
NODE count_a(NODE tail);
NODE tail=NULL;
int main()
{
    int i,n;
    scanf("%d",&n);
    if(n>0)
    {
        for(i=0;i<n;i++) { tail=insert_e(tail); } display(tail); tail=count_a(tail); } else { exit(0); } return 0; } void display(NODE tail) { cur=tail->link;
    while(cur!=tail)
    {
        printf("%s %d",cur->ws,cur->yr);
        printf("\n");
        cur=cur->link;
    }
    printf("%s %d",tail->ws,tail->yr);
    printf("\n");
}
NODE createnode()
{
    newnode=(NODE)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        exit(0);
    }
    scanf("%s %d",newnode->ws,&newnode->yr);
    newnode->link=newnode;
    return newnode;
}
NODE insert_e(NODE tail)
{
    newnode=createnode();
    if(tail==NULL)
    {
        tail=newnode;
    }
    else
    {
        newnode->link=tail->link;
        tail->link=newnode;
        tail=newnode;
    }
    return tail;
}
NODE count_a(NODE tail)
{
    int k,count=0;
    scanf("%d",&k);
    cur=tail->link;
    printf("\n");
    while(cur!=tail)
    {
        if(cur->yr==k)
        {
            count++;
            printf("%s %d\n",cur->ws,cur->yr);

        }
        cur=cur->link;
    }
    if(tail->yr==k)
        {
            count++;
            printf("%s %d\n",tail->ws,tail->yr);

        }
    if(count!=0)
        printf("\n");
    printf("%d",count);

    return tail;
}
