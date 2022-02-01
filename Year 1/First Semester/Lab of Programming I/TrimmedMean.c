#include <stdio.h>

int main (void)

{
    int i,j, siz, minimum, temp, sum=0;
    float mean;

    scanf("%d", &siz);

    float arr[siz];

    for (i = 0; i < siz; i++) //Putting numbers in an array
    {
        scanf ("%f", &arr[i]);
    }

    for (i=0; i<siz-1; i++) //Selection sorting
    {
       minimum = i;
       for (j=i+1; j<siz; j++)
       {
           if (arr[j]<arr[minimum]) //finding the minimum value
            minimum=j;
       }
        if (minimum >i)
        {
            temp=arr[i];
            arr[i]= arr[minimum];  //Swapping numbers in the array
            arr[minimum]= temp;
        }
    }

    for ( i = 3; i < (siz-3); i++)
    {
        sum += arr[i];
    }

    mean = (float)(sum)/(float)(siz-6);

    printf("%.2f", mean);
    return 0;
}
