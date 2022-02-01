#include <stdio.h>
 int main (void)
{
 float x, y;
 scanf("%f %f", &x, &y);

 float velocity=x/y;
 printf("%.6f", velocity);

return 0;
}
