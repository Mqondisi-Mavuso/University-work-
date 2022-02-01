#include <stdio.h>

int main(void)
{
int i, j, n = 10, temp, minimum;
int arr[n];

 for (i = 0 ; i < n ; i++)
 {
 scanf("%d", &arr[i]);
 }

 for (i = 0 ; i < n-1; i++)
 {
 minimum = i;
   for (j = i +1 ; j < n; j++)
   {
     if (arr[j] < arr [minimum])
       minimum = j;
   }
   temp = arr[i];
   arr[i] = arr[minimum];
   arr[minimum] = temp;
 }
for (i = 0; i < n; i ++)
{
printf("%d ", arr[i]);
}

return 0;
}
