#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>



int main (void)
{
 int num, count=0, maximum, minimum;


 while (scanf("%d", &num) != EOF)
     {

        if (count == 0)
          {
           maximum=num;
           minimum=num;
          }
        else
            {
            if (num>maximum)
                {
                  maximum=num;
                }
            if(num<minimum)
                {
                  minimum=num;
                }
            }
    count++;
     }
printf("%d %d", maximum, minimum);

return 0;
}
