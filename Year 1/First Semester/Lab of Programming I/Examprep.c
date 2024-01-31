//http://oj.csie.ndhu.edu.tw/problem/PR110-06-05

#include <stdio.h>
#include <math.h>

int main (void)
{
    int count  = 0, num_coordinates, test_cases, maximum, temp, i,j;
    scanf("%d", &test_cases);

    while (count < test_cases)

    {
        
        scanf("%d", &num_coordinates);
        int xArray[num_coordinates], yArray[num_coordinates];

        for (i = 0; i < num_coordinates; i++)
        {
            scanf("%d %d", &xArray[i], &yArray[i]);
        }

        for (i = 0; i < num_coordinates - 1; i++) //Sorting the xArray
        {
            maximum = i;
            for (j = i+1; j < num_coordinates; j++)
            {
                if (xArray[j] > xArray[maximum]) //Finding the maximum
                    maximum = j;
            }

            temp = xArray[i];
            xArray[i] = xArray[maximum];
            xArray[maximum] = temp;

            temp = yArray[i];
            yArray[i] = yArray[maximum];  //Swapping the yArray to correspond to it x Value
            yArray[maximum] = temp;
        }

        float sumLength = 0, rat, h;
        int highest = yArray[0];

        for (i = 1; i < num_coordinates; i++)
        {
            rat = ((float)(yArray[i]-highest))/((float)(yArray[i]-yArray[i-1]));
            if (yArray[i] > highest)
            {
                h = sqrt(((yArray[i]-yArray[i-1])*(yArray[i]-yArray[i-1]))+ ((xArray[i-1]- xArray[i])*(xArray[i-1]- xArray[i])));
                sumLength += h*rat;
                highest = yArray[i];
            }

        }
        float sum = sumLength;
        printf("%.2f\n", sum);
        count ++;
    }

  return 0;
}
