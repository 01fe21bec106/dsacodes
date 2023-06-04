#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define SIZE 100
struct stack
{
    int data[SIZE];
    int top;
};
void push(struct stack *sptr)
{
    int num;
    scanf("%d",&num);
    if(sptr->top==SIZE-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        if(num!=0)
       {
        sptr->top++;
        sptr->data[sptr->top]=num;
        }
    }
}
int pop(struct stack *sptr)
{
    int num;
    if(sptr->top==-1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        num=sptr->data[sptr->top];
        sptr->top--;
    }
    return num;
}
void asteriod(struct stack * s1ptr,struct stack * s2ptr)
{
    int c1=0,c2=0,num1,num2;
    while(s1ptr->top!=-1&&s2ptr->top!=-1)
    {
        num1=pop(s1ptr);
        num2=pop(s2ptr);
        if(num1>0&&num2>0)
        {
            printf("0 ");
            c1++;
        }
        else if(num1<0&&num2<0)
{
printf("0 ");
c1++; }
else
{
printf("1 ");
c2++;
}
}
printf("\n%d",c2);
printf("\n%d",c1);
 }
int main() {
struct stack * s1ptr;
struct stack * s2ptr;
struct stack s2,s1;
s1ptr=&s1;
s2ptr=&s2;
int i;
s1ptr->top=-1;
    s2ptr->top=-1;
    int n;
    scanf("%d",&n);
    if(n<1)
    {
        printf("Invalid input.");
        exit(0);
    }
   for(i=0;i<n;i++)
   {
       push(s1ptr);
   }
    for(i=0;i<n;i++)
   {
       push(s2ptr);
   }
   asteriod(s1ptr,s2ptr);
    return 0;
}

