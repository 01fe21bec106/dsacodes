#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct node{
    int data;
    struct node *link;
};
typedef struct node *NODE;
NODE create_node()
{
    NODE newnode;
    newnode=malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->link=newnode;
    return newnode;
}
NODE insert_end(NODE tail)
{
    NODE newnode;
    newnode=create_node();
    if(tail==NULL)
    {
        tail=newnode;
    }
    else{
        newnode->link=tail->link;
        tail->link=newnode;
        tail=newnode;
    }
    return tail;
}
NODE remaining(NODE tail,int *count)
{
    NODE prev=tail;
    NODE cur=tail->link;
    NODE next=cur->link;
    *count=0;
    do{
        if(next->data)
        {
            prev->link=next;
            free(cur);
            cur=next;
            next=next->link;
            (*count)++;
        }
        else{
          prev=cur;
          cur=next;
          next=next->link;
        }
    }while(cur!=tail);
    if(cur->data>next->data)
    {
        tail=prev;
        prev->link=next;
        free(cur);
        (*count)++;
    }
    return tail;
}
void display(NODE tail)
{
    NODE cur=tail->link;
    do{
    printf("%d ",cur->data);
    cur=cur->link;
    }while(cur!=tail->link);
}
int main() {
    NODE tail=NULL;
    int n;
    scanf("%d",&n);
    int i;
    for( i=0;i<n;i++)
        insert_end();
}
