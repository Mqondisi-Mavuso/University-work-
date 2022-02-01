#include <stdio.h>
#include <stdbool.h>


int main (void)
{
int num, i;
bool prime;

scanf("%d", &num);
for (i=2; i<=num-1; i++)
     {
        if (i==1)
            {
              prime= false;
            }
        else if (i==2)
            prime = true;
        else if (i%2 == 0)
                {
                 prime = false;
                }
        else prime = true;
     }
if (prime=true)
    {
     printf("is Prime");
    }
else
    {
       printf("is not Prime");
    }

return 0;
}
