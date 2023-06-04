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
void push(struct stack *sptr, int num);
int pop(struct stack *sptr);
int evaluate(struct stack *sptr,char postfix[SIZE]);
int main()
{
    struct stack * sptr;
    struct stack s;
    char postfix[SIZE];
    sptr=&s;
    sptr->top=-1;
    scanf("%s",postfix);
    printf("Given postfix Expression: %s\n",postfix);
    int res=evaluate(sptr,postfix);
    printf("Result after Evaluation: %d\n",res);
    return 0;
}
void push(struct stack *sptr, int num)
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
int pop(struct stack *sptr)
{
    int num;
    num=sptr->data[sptr->top];
    sptr->top--;
    return num;
}
int evaluate(struct stack *sptr,char postfix[SIZE])
{
    int op1,op2,i=0;
    char ch;
    while(postfix[i]!='\0')
    {
        ch=postfix[i];
        if(isdigit(ch)!=0)
        {
            push(sptr,(ch-'0'));
        }
        else
        {
            op2=pop(sptr);
            op1=pop(sptr);
            switch(ch)
            {
                case '+':push(sptr,op1+op2);
                break;
                case '-':push(sptr,op1-op2);
                break;
                case '*':push(sptr,op1*op2);
                break;
                case '/':push(sptr,op1/op2);
                break;
            }
        }
        i++;
    }
    return pop(sptr);
}

