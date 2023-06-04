#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct node{
    int height;
    struct node *link;
};
typedef struct node *NODE;
NODE insert_end(NODE head);
NODE qualified(NODE head);
int main() {
    NODE head=NULL;
    int n;
    scanf("%d",&n);
    if(n<0 && n>=100)
        exit(0);
    for(int i=0;i<n;i++) { head=insert_end(head); } head=qualified(head); return 0; } NODE insert_end(NODE head) { NODE newnode=malloc(sizeof(struct node)); scanf("%d",&newnode->height);
    NODE cur=head;
    if(head==NULL)
    {
        head=newnode;
    }
    else{
        while(cur->link!=NULL)
        {
            cur=cur->link;
        }
        cur->link=newnode;
    }
    newnode->link=NULL;
    return head;
}
NODE qualified(NODE head)
{
    NODE cur=head,prev=NULL;
    int count=0;
    while(cur!=NULL)
    {
        if(cur->height<=185) { if(cur==head) { head=cur->link;
                free(cur);
                cur=head;
            }
            else{
            prev->link=cur->link;
            free(cur);
            cur=prev->link;
            }
            count++;
        }
        else{
            prev=cur;
            cur=cur->link;
        }
    }
    printf("%d",count);
    return head;
}
