
#include<stdio.h>

void read(int a[90][90],int r,int c)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf(" %d",&a[i][j]);
        }
    }
}
void display(int a[90][90],int r,int c)
{
    int i,j;
    printf("\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf(" %d ",a[i][j]);
        }
        printf("\n");
    }
}
void symmetry(int a[90][90],int c,int r,FILE *fp)
{
    int i,j;
    int f=0;
    for(i=0;i<r;i++)
    {
        for(j=0;i<c;i++)
        {
            if(i!=j && (i+j)==(j+i))
            {

            if(a[i][j]==a[j][i])
            {
                f=1;
                break;
            }
        }
    }
    }
    if(f==1)
    {
        printf("\n  The matrix is symmetry ");
        fprintf(fp,"The matrix is symmetry \n");
    }
    else
    {
        printf("\n  The matrix is not  symmetry ");
         fprintf(fp,"The matrix is not  symmetry \n");
    }
}
int main()
{
    int r1,c1,a[90][90];
    FILE *fp;
    fp=fopen("array.txt","w");
    printf("Enter the size of rows and column of 1 st matrix");
    scanf("%d%d",&r1,&c1);
    if(r1==c1)
    {
        printf("The 1st array elements are:");
        read(a,r1,c1);
        printf("the elements:");
        display(a,r1,c1);
        symmetry(a,c1,r1,fp);
    }
    else
    {
        printf("\n The matrix is not a square matrix so,it is not a symmetry\n ");
    }
}
