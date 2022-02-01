#include <stdio.h>

int main (void)
{
    int r,c, n, row, column, element, i, j;
    scanf("%d %d %d", &r, &c, &n);
    int matrix[r][c];

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)  //Setting all the elements to zero
        {
          matrix[i][j] = 0;
        }
    }

    for (i = 0; i < n; i++)
    {
        scanf("%d %d %d", &row, &column, &element); // putting the numbers in the matrix
        matrix[row][column] = element;
    }

     for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)  //printing the entire marix
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

 return 0;
}
