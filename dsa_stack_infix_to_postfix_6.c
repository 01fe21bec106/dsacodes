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
void postfix_conv(char infix[SIZE]);
int pre(char ch);
int main()
{
    char infix[50];
    scanf("%s",infix);
    postfix_conv(infix);
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
    num=sptr->data[sptr->top];
    sptr->top--;
    return num;
}
char peek(struct stack *sptr)
{
    char c;
    c=sptr->data[sptr->top];
    return c;
}
void postfix_conv(char infix[SIZE])
{
    struct stack s, * sptr;
    sptr=&s;
    sptr->top=-1;
    char postfix[SIZE],ch,elem;
    int i=0,k=0;
    push(sptr,'#');
    while(infix[i]!='\0')
    {
        ch=infix[i];
        if(ch=='(')
        {
            push(sptr,ch);
        }
        else if(isalnum(ch))
        {
            postfix[k++]=ch;
        }
        else if(ch==')')
        {
            while(sptr->data[sptr->top]!='(')
            {
                postfix[k++]=pop(sptr);
            }
            elem=pop(sptr);
        }
        else
        {
            while(pre(peek(sptr))>=pre(ch))
            {
                postfix[k++]=pop(sptr);
            }
            push(sptr,ch);
        }
        i++;
    }
    while(sptr->data[sptr->top]!='#')
    {
        postfix[k++]=pop(sptr);
    }
    postfix[k]='\0';
    printf("Given Infix Expression: %s\nPostfix Expression: %s",infix,postfix);
}
int pre(char ch)
{
    switch(ch)
    {
        case '#':return 0;
            break;
        case '(':return 1;
            break;
        case '+':
        case '-':return 2;
            break;
        case '/':
        case '*':
        case '%':return 3;
            break;
        case '^':return 4;
            break;
    }
    return 0;
}

