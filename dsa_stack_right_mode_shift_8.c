#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main() {
    int n,b;
    scanf("%d",&n);
    if(n>0)
    {
        int i=0;
        while(n!=0)
        {
           b=(n%2)*pow(10,i);
            if(n%2==1)
                break;
            n=n/2;
            i++;
        }
        printf("%d",i);
    }
    else{
        printf("Invalid");
    }
    return 0;
}
