#include<stdio.h>
int a[90][90],b[90][90],h[90][90];
main()
{
    int *p,n,m,*q,*r,*s,*x,*y,n1,m1;
    p=&a[90][90];
    r=&b[90][90];
    s=&m;
    q=&n;
    x=&n1;
    y=&m1;
    printf("enter the number of rows and columns of first matrix: \n");
    scanf("%d%d",&n,&m);
    read(p,q,s);
    display(p,q,s);
    printf("Enter the number of elements rows and columns of 2nd matrix \n");
    scanf(" %d%d",&n1,&m1);
    read1(r,x,y);
    display1(r,x,y);
    mul(p,q,s,r,x,y);

}
void mul(int *p,int *q,int *s,int *r,int *x,int *y)
{
    int i,j,sum,k;
      int  *w;
      w=&h[90][90];
    if(*s==*x)
    { sum=0;
    for(i=0;i<*q;i++)
    {
        for(j=0;j<*y;j++)
         {
             for(k=0;k<*s;k++)

        {
            sum=sum+a[i][k]*b[k][j];
        }
          h[i][j]=sum;
          sum=0;
         }
        printf("\n ");
    }
    printf("The multiplication of matrix is:");
    display2(w,q,s);
    }


    else{
        printf("\n The multiplication can not found\n ");
    }
}
void read(int *p,int *q,int *s)
{
    int i,j;
    for(i=0;i<*q;i++)
    {
        for(j=0;j<*s;j++)
        {
        scanf(" %d",&a[i][j]);
    }
    printf("\n");
    }
}
void display(int *p,int *q,int *s)
{
    int i,j;
    for(i=0;i<*q;i++)
    {
        for(j=0;j<*s;j++)
        {

        printf("%d\t",a[i][j]);
    }

    printf("\n");
}
}
void read1(int *r,int *x,int *y)
{
    int i,j;
    for(i=0;i<*x;i++)
    {
        for(j=0;j<*y;j++)
        {
        scanf(" %d",&b[i][j]);
    }
    printf("\n");
    }
}
void display1(int*r,int *x,int *y)
{
    int i,j;
    for(i=0;i<*x;i++)
    {
        for(j=0;j<*y;j++)
        {

        printf(" %d\t",b[i][j]);
    }

    printf("\n");
}

}
void display2(int *w,int *q,int *s)
{
    int i,j;
    printf("\n");
    for(i=0;i<*q;i++)
    {
        for(j=0;j<*s;j++)
        {

        printf("%d\t",h[i][j]);
    }

    printf("\n");
}

}



