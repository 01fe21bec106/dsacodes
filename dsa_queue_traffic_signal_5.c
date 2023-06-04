
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define SI 10
struct queue
{
    char data[SI];
    int front,rear;
};
void enqueue(struct queue *qptr,char num)
{
    if(qptr->rear==-1&&qptr->front==-1)
    {
        qptr->front=qptr->rear=0;
        qptr->data[qptr->rear]=num;
    }
    else if((qptr->rear+1)%SI==qptr->front)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        qptr->rear=(qptr->rear+1)%SI;
        qptr->data[qptr->rear]=num;
    }
}
int dequeue(struct queue *qptr)
{
    char num='0';
    if(qptr->front==-1&&qptr->rear==-1)
    {
        return num;
    }
    else if(qptr->front==qptr->rear)
    {
        num=qptr->data[qptr->front];
        qptr->front=qptr->rear=-1;
    }
    else
    {
        num=qptr->data[qptr->front];
        qptr->front=(qptr->front+1)%SI;
    }
    return num;
}
void check(struct queue *qptr)
{
    char c1;
    int count=0;
    while(qptr->front!=qptr->rear||(qptr->rear==0&&qptr->front==0))
    {
        c1=dequeue(qptr);
        if(c1=='R')
        {
            enqueue(qptr,'Y');
            count++;
        }
        else if(c1=='Y')
        {
            enqueue(qptr,'G');
            count++;
        }
    }
    printf("%d",count);
}
int main()
{
    struct queue * qptr;
    struct queue q;
    qptr=&q;
    qptr->front=qptr->rear=-1;
    int n,ch,i;
    scanf("%d",&n);
    if(n>0&&n<100)
    {
        for(i=0;i<n;i++)
    {
        scanf(" %lc ",&ch);
        enqueue(qptr,ch);
    }
    check(qptr);
    }
    return 0;
}
