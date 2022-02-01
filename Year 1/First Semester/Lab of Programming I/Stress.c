#include <stdio.h>

int main (void)
{
int a,b,c,i,n,dev;
scanf("%d %d %d", &a,&b,&c);

        //finding the lowest
        if (a<b && a<c)
            {
             n=a;
            }
        else if (b<a && b<c)
            {
             n=b;
            }
        else
            {
              n=c;
            }
        //printf("%d", n);
for (i=2;i<=n;i++)
    {
     if(a%i==0 && b%i==0 && c%i==0)
            dev=i;
    }
printf("%d", dev);

return 0;
}
