#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define SI 100
struct queue
{
    int data[SI],front,rear;
};
void enqueue(struct queue *qptr,int num)
{
    if(qptr->rear==SI-1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        qptr->rear++;
        qptr->data[qptr->rear]=num;
    }
}
int dequeue(struct queue *qptr)
{
    int num=0;
    if(qptr->front==qptr->rear)
    {
        return num;
    }
    else
    {
        qptr->front++;
        num=qptr->data[qptr->front];
        return num;
    }
}
void check(struct queue *qptr)
{
    int n,sum1=0,sum2=0;
    while(qptr->front!=qptr->rear)
    {
        n=dequeue(qptr);
        if(n%3==0)
        {
            sum1=sum1+n;
        }
        if(n%2==0)
        {
            sum2=sum2+n;
        }
    }
    if(sum1<sum2) { printf("Shaktiman"); } else { printf("krrish"); } } int main() { struct queue * qptr; struct queue q; qptr=&q; qptr->front=qptr->rear=-1;
    int num,n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        enqueue(qptr,num);
    }
    check(qptr);
    return 0;
}

