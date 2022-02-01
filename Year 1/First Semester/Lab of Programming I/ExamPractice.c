#include <stdio.h>

int main()
{
char m [20];
int i=0;
scanf("%s", &m);
for (i=0 ; i !='\0' ; i++)
        {
            if (m[i]==0)
                    {
                    printf("-----");
                    }
            else if (m[i]==1)
                    {
                       printf(".----");
                    }
            else if (m[i]==2)
                    {
                       printf("..---");
                    }
            else if (m[i]==3)
                    {
                       printf("...--");
                    }
            else if (m[i]==4)
                    {
                       printf("....-");
                    }
            else if (m[i]==5)
                    {
                       printf(".....");
                    }
            else if (m[i]==6)
                    {
                       printf("-....");
                    }
            else if (m[i]==7)
                    {
                       printf("--...");
                    }
            else if (m[i]==8)
                    {
                       printf("---..");
                    }
            else if (m[i]==9)
                    {
                       printf("----.");
                    }
    }


    return 0;
}
