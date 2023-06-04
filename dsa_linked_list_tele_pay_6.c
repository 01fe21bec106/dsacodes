#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct node
{
    char tr[30];
    float rech;
    int str;
    struct node *link;
};
typedef struct node *NODE;
NODE newnode,cur;
NODE createnode();
NODE insert_e(NODE tail);
void display(NODE tail);
NODE recha(NODE tail);
NODE tail=NULL;
int main()
{
    int i,n;
    scanf("%d",&n);
    if(n>0)
    {
        for(i=0;i<n;i++) { tail=insert_e(tail); } display(tail); tail=recha(tail); } else { exit(0); } return 0; } void display(NODE tail) { cur=tail->link;
    printf("All transactions details:\n");
    while(cur!=tail)
    {
        printf("%s %0.2f %d",cur->tr,cur->rech,cur->str);
        printf("\n");
        cur=cur->link;
    }
    printf("%s %0.2f %d",cur->tr,cur->rech,cur->str);
    printf("\n");
}
NODE createnode()
{
    newnode=(NODE)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        exit(0);
    }
    scanf("%s %f %d",newnode->tr,&newnode->rech,&newnode->str);
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
NODE recha(NODE tail)
{
    int k,count=0;
    scanf("%d",&k);
    cur=tail->link;
    printf("\n");
    while(cur!=tail)
    {
        if(strcmp("recharge",cur->tr)==0)
        {
            count++;
            printf("%s %0.2f %d\n",cur->tr,cur->rech,cur->str);
        }
        cur=cur->link;
    }
    if(strcmp("recharge",tail->tr)==0)
        {
            count++;
            printf("%s %0.2f %d",tail->tr,tail->rech,tail->str);
        }
    if(count==0)
        printf("No transactions found related to recharge.");

    return tail;
}

