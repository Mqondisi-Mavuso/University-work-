#include <stdio.h>

int main (void)

{
int i, j,minimum, temp,n=10, a[n],b;

for (b=0; b<10; b++) /*putting numbers in an array*/
scanf("%d",&a[b]);

for (b=n-1; b>=0; b--)
    {
    if (b=n-1)
        {
         printf ("%d", a[b]);
        }
    else{printf (" %d", a[b]);}


    }

return 0;
}
