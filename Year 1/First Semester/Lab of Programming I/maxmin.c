#include <stdio.h>


int main (void)
{
 int num;
 int count=0, maximum, minimum;


 while (scanf("%d", &num) != EOF)
     {

        if (count == 0)
          {
           maximum=num;
           minimum=num;
          }
        else
            {
            if (num > maximum)
                {
                  maximum = num;
                }
            if(num < minimum)
                {
                  minimum = num;
                }
            }
    count++;
     }
printf("%d %d", maximum, minimum);

return 0;
}
