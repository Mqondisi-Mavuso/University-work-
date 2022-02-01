#include <stdio.h>
#include <string.h>

int main (void)

{
    char arrA[100], arrB[100];

    gets(arrA);

    strcpy(arrB, arrA);
    strrev(arrB);

    if (strcmp(arrA, arrB) == 0)

    printf("%s is a palindrome.",arrA);

    else
          printf("%s is not a palindrome.",arrA);


return 0;
}
