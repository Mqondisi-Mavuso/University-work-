#include <stdio.h>

int main (void)

{
    int i, j,minimum, temp,n=10, a[n],b;

    for (b=0; b<n; b++) /*putting numbers in an array*/
        scanf("%d",&a[b]);

    for (i=0; i<n-1; i++) /*selection sort algorithm*/
    {

        minimum = i;
        for (j=i+1; j<n; j++) /*finding the minimum*/
        {
            if (a[j] < a[minimum])
                minimum = j;
        }
        temp = a[i];
        a[i] = a[minimum];
        a[minimum] = temp;

    }

    for (i=0; i < n ; i++)
        printf("%d ",a[i]);
return 0;
}
