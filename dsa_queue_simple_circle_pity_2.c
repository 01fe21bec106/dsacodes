#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define SIZE 50
int queue[SIZE],n,front=-1,rear=-1;
void enqueue(int n)
{

    if(rear==SIZE-1)
    {
        printf("Overflow");
    }
    else
        if(front==-1)
    {
        front=0;
    }
    rear++;
    queue[rear]=n;
}
void dequeue()
{
    if(front==-1 || front>rear)
    {
        printf(" \nUnderflow");
    }
    else
        n=queue[front];
       front++;
       printf("\nDeleted element is %d",n);
}
void show()
{
    int i;
    if(front==-1)
    {
        printf("\nQueue is empty");
    }
    else
        printf("\nQueue");
        for(i=front;i<=rear;i++)
    {
        printf("\t%d",queue[i]);
    }
}
int main()
{
    int choice,n;
    while(1)
    {
        printf("\n Enter the choice");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\nEnter the number");
                     scanf("%d",&n);
                     enqueue(n);
                     break;
            case 2 :  dequeue();
                     break;
           case 3 : show();
                   break;
            case 4: exit(0);
              break;
            default :printf("Default statement");


        }
    }
}





