#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct node
{
    char song[20];
    char singer[20];
    float a;
    int b;
    struct node *rightlink;
    struct node *leftlink;
};
typedef struct node *NODE;
NODE insert_end(NODE head);
void display(NODE head);
void songs_of_singer(NODE head,char *a);
void delete_song(NODE head,char *ch);
NODE create_node();
int main() {
    int n;
    NODE head=NULL;
    scanf("%d",&n);
    int i;
    for( i=0;i<n;i++) {
head=insert_end(head); }
 char singer[20],delete[20];
 scanf("%s",singer);
scanf("%s",delete);
display(head);
songs_of_singer(head,singer);
 delete_song(head,delete);
 return 0; }
NODE create_node() {
NODE newnode;
newnode=malloc(sizeof(struct node));
 scanf("%s %s %f%d",newnode->song,newnode->singer,&newnode->a,&newnode->b);
    newnode->rightlink=NULL;
    newnode->leftlink=NULL;
    return newnode;
}
NODE insert_end(NODE head)
{
    NODE newnode;
    newnode=create_node();
    NODE cur=head;
    if(head==NULL)
    {
        head=newnode;
    }
    else{
    while(cur->rightlink!=NULL)
    {
        cur=cur->rightlink;
    }
    cur->rightlink=newnode;
    newnode->leftlink=cur;
    }
    return head;
}
void display(NODE head)
{
    NODE newnode=head;
    while(newnode!=NULL)
    {
        printf("%s %s %0.2f %d\n",newnode->song,newnode->singer,newnode->a,newnode->b);
        newnode=newnode->rightlink;
    }
    printf("\n");
}
void songs_of_singer(NODE head,char *singer)
{
    NODE cur=head;
    int status=0;
    while(cur!=NULL)
    {
        if(strcmp(cur->singer,singer)==0)
        {printf("%s %s %0.2f %d\n",cur->song,cur->singer,cur->a,cur->b);status=1;}
        cur=cur->rightlink;
    }
    if(status==0)
        printf("No songs of %s to display\n\n",singer);
    else
        printf("\n");
}
void delete_song(NODE head,char *song)
{
    NODE cur=head;
    int status=0;
    while(cur!=NULL)
    {
        if(strcmp(cur->song,song)==0)
        {
            printf("Deleted %s %s %0.2f %d\n",cur->song,cur->singer,cur->a,cur->b);
            status=1;
        }
        cur=cur->rightlink;
    }
    if(status==0)
        printf("No song %s to delete",song);
}
