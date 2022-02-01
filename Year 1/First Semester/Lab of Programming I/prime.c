#include <stdio.h>
#include <stdbool.h>

bool (isPrimeNumber (int n));
int main (void)

{
    int n,i;
    scanf("%d", n);
    if (isPrimeNumber (n))
        printf ("%d is Prime Number", n);
return 0;
}
{
bool isPrimeNumber (int n);

for (int i=2 ; i<n; i++)
    {
      if ( n % i == 0)
          {
             break;
          }
    }
    if (i == n)
        {
          return true;
        }
    else
        return false;

}
