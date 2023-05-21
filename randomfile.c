#include<stdio.h>
#include<time.h>
int main()
{
    FILE **fp2;
    FILE **fp;
    int p,q;

    double total;

    printf("Enter the range \n");
    scanf("%d",&p,&q);
    clock_t start,end;

    fp2 = fopen("randomoutput.txt","w+");
    int n,r,a[900],i,j,temp;
    fp =fopen("log.txt","w+");
    start=clock();
    fscanf(fp2,"%d",&n);
    for(i=1;i<100;i++)
    {
        r=rand();
        r=r%100;
        fprintf(fp2,"%d\t",r);
    }
    rewind(fp2);

    fscanf(fp2,"%d",&n);
    for(i=0;i<n;i++)
    {
        fscanf(fp2,"%d",&a[i]);
    }
    fclose(fp2);
    fp2=fopen("randomoutput.txt","w");
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;            }
        }

    }
    for(i=0;i<n;i++)
    {
    fprintf(fp2,"%d\t",a[i]);
    }
    end= clock();
    total= (double)(end-start)/CLOCKS_PER_SEC;
    fprintf(fp,"random number %f second \n",total);
    return 0;
}
