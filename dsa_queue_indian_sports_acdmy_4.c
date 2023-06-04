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

int main()
{
    struct queue * qptr;
    struct queue q;
    qptr=&q;
    qptr->front=qptr->rear=-1;
    int num,n,i,sum=0,c,count=0;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
scanf("%d",&num);
enqueue(qptr,num); }
 while(qptr->rear!=qptr->front)
    {
        c=dequeue(qptr);
        if(c<=185)
        {
            count++;
        }
    }
    printf("%d",count);
    return 0;
}
