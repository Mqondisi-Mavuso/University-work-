#include <stdio.h>

int main (void)

{
    int i,j, siz, minimum, temp, sum=0;

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

//    for (i=0; i<siz; i++)
//    {
//     printf("%.2f ", arr[i]);
//    }
    for (i=3; i<=siz-3; i++)
    {
        sum++;
    }

printf("%.2f", sum);
    return 0;
}
