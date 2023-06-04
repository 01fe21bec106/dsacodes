#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define SIZE 100
struct stack
{
    char data[SIZE];
    int top;
};
void push(struct stack *sptr, char num);
char pop(struct stack *sptr);
int main()
{
    struct stack * sptr1,* sptr2;
    struct stack s1,s2;
    sptr1=&s1;
    sptr1->top=-1;
    sptr2=&s2;
    sptr2->top=-1;
    int num,i;
    char ch;
    scanf("%d",&num);
    if(num<2)
    {
        printf("More number of cards needed.");
        exit(0);
    }
    for(i=0;i<num;i++) {
 scanf(" %c",&ch);
if(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
{
push(sptr1,ch);
}
else {
push(sptr2,ch);
}
}
char ch1;
if(sptr1->top==-1)
    {
       printf("0 ");
    }
    else
    {
        printf("%d ",sptr1->top+1);
    }
    if(sptr2->top==-1)
    {
       printf("0\n");
    }
    else
    {
        printf("%d\n",sptr2->top+1);
    }
    if(sptr1->top==-1)
        {
            printf("-1");
        }
    while(sptr1->top!=-1)
    {
        ch1=pop(sptr1);
        printf("%c ",ch1);
    }
    printf("\n");
    if(sptr2->top==-1)
        {
            printf("-1\n");
        }
    while(sptr2->top!=-1)
    {
        ch1=pop(sptr2);
        printf("%c ",ch1);
    }
    return 0;
}
void push(struct stack *sptr, char num)
{
    if(sptr->top==SIZE-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        sptr->top++;
        sptr->data[sptr->top]=num;
    }
}
char pop(struct stack *sptr)
{
    char num;
    if(sptr->top==-1)
    {
        return -1;
    }
    else
    {
        num=sptr->data[sptr->top];
        sptr->top--;
    }
    return num;
}
