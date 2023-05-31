
#include<stdio.h>

main()
{
    int a[30],n;
    FILE *fp;
    printf("Enter the number of elements(n)");
    scanf("%d",&n);
    printf("The array elements are:");
    int i;
    for(i=0;i<n;i++)
    {
        scanf(" %d",&a[i]);
    }
    fp=fopen("array.txt","w");
    int k;
    for(k=0;k<n;k++)
    {
        printf("\n %d",a[k]);
        fprintf(fp,"%d \t",a[k]);
    }
    fclose(fp);   int j,c=0;

    fp=fopen("array.txt","w+");
   for (i=0;i<n;i++)
   {
       for(j=0;j<n;j++)
       {
        if(a[i]==a[j])
        c++;
       }
       printf("The number %d is repeated for %d \n",a[i],c);
      fprintf(fp,"the number %d is repeated for %d \n",a[i],c);
       c=0;
   }
 fclose(fp);
}
