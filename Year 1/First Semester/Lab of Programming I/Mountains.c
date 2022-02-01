//http://oj.csie.ndhu.edu.tw/problem/PR110-06-05

#include <stdio.h>
#include <math.h>


int main (void)
{
    int num_coordinates, count=0, test_cases, temp, maximum, max;
    scanf("%d", &test_cases);
    while(count < test_cases)
    {
        scanf("%d", &num_coordinates);
        int i, j, xArray[num_coordinates], yArray[num_coordinates];

        for (i = 0; i < num_coordinates; i++)
        {
            scanf("%d %d", &xArray[i], &yArray[i]);

        }

        for (i = 0; i < num_coordinates-1; i++) //sorting the xArray
        {
            maximum = i;
            for (j = i+1; j<num_coordinates; j++)//finding the maximum
            {

            if (xArray[j] > xArray[maximum])
                {
                  maximum = j;
                }
            }
            temp = xArray[i];
            xArray[i] = xArray[maximum];  //sorting the XArray in discending order
            xArray[maximum] = temp;

            temp = yArray[i];
            yArray[i] = yArray[maximum]; // Swapping the yArray to correspond with the xArray
            yArray[maximum] = temp;
        }
        int highest = yArray[0];
        float sumlength = 0, rat, h;
        for (i = 1; i<num_coordinates; i++)
        {
            rat = ((float)(yArray[i]-highest)/(float)(yArray[i]-yArray[i-1]));
            if (yArray[i]>highest)
            {
                h = sqrt(((yArray[i] - yArray[i-1])*(yArray[i] - yArray[i-1]))+ ((xArray[i-1]-xArray[i])*(xArray[i-1]-xArray[i])));
                sumlength += h*rat;
                highest = yArray[i];
            }
        }
    float sum;
    sum = sumlength;
    printf("%.2f\n", sum);
    count++;
    }

return 0;
}
