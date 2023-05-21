#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct node
{
    int dt;
    struct node *next;
};
typedef struct node *node;
node head=NULL,temp,temp1,newnode;

node insert(node head,FILE *fp1)
{

    newnode=(node)malloc(sizeof(struct node));
    fscanf(fp1,"%d",&newnode->dt);
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        temp=head;
        head=newnode;
        newnode->next=temp;
    }
    return head;
}

void display(node head,FILE *fp2)
{
    temp=head;
    while(temp!=NULL)
    {
        fprintf(fp2," %d\n",temp->dt);
        temp=temp->next;
    }
}

node sort(node head)
{
    int x;
    temp1=head;
    while(temp1->next!=NULL)
    {
        temp=head;
        while(temp->next!=NULL)
        {
            if(temp->dt > temp->next->dt)
            {
                x=temp->dt;
                temp->dt=temp->next->dt;
                temp->next->dt=x;

            }
            temp=temp->next;
        }
        temp1=temp1->next;
    }
    return head;
}

void main()
{
    int n;
    FILE *fp1,*fp2;
    double total;
    clock_t start,end;
    start=clock();
    fp1=fopen("array.txt","r");
    fp2=fopen("array1.txt","w");
    FILE *fp3=fopen("log.txt","w");
    printf("Enter the value of n\n: ");
    scanf("%d",&n);
    int i;
    for(  i=0;i<n;i++)
    {
        head=insert(head,fp1);
    }
    display(head,fp2);
    head=sort(head);
    fprintf(fp2,"After sorting\n");
    display(head,fp2);
    end=clock();
    total = (double)(end-start)/CLOCKS_PER_SEC;
    fprintf(fp3," TIME %f ",total);
    fclose(fp1);
    fclose(fp2);
}
