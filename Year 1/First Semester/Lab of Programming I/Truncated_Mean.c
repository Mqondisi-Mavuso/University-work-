#include <stdio.h>

int main (void)
{
  int i, j, n, temp, minimum;
  float sum = 0, tMean;
  scanf("%d", &n);

  float arr[n];
  for (i = 0; i < n; i++)
  {
      scanf("%f", &arr[i]);
  }

  for (i = 0; i <n-1; i++)
  {
      minimum = i;
      for (j = i+1; j < n; j++)
      {
          if (arr[j] < arr[minimum]) //sorting the array
            minimum = j;
      }
      temp = arr[i];
      arr[i] = arr[minimum];
      arr[minimum] = temp;
  }

//    for (i = 0; i < n; i++)
//    {
//        printf("%d ", arr[i]);
//    }

    for (i = 3; i < (n-3); i++)
    {
        sum += arr[i];
    }
    tMean = (sum)/(float)(n-6);

    printf("%.2f", tMean);
return 0;
}
