#include <iostream>
#include <stdio.h>

using namespace std;

void allocArray(int ***p, int m, int n)
{
    * p = new int *[m];
    int size  = m*n;
    int _count = 0; //use the counter to
    int *t = new int[size];
    for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if(_count < size){
                (*p)[i] = &t[_count];
                _count ++;
            }
        }
    }
}

int main()
{
  int **array, *a;
  int j, k;
  allocArray(&array, 5, 10);
  for(j = 0;j < 5;j ++)
    for(k = 0;k < 10;k ++)
      array[j][k] = j * 10 + k;
  for(j = 0;j < 5;j ++)
    for(k = 0;k < 10;k ++)
      printf("%p ", &(array[j][k]));
}
