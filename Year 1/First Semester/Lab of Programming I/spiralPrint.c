#include <stdio.h>

int main (void)

{
    int row, col, i, j, count = 0;
    scanf("%d %d", &row, &col);
    int matrix[row][col];

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    int row_start = 0, col_start = 0, row_end = row - 1, col_end = col - 1;
    while ( count < row * col)
    {
        for ( j = col_start; j <= col_end; j++)//first row
        {
            i = row_start;
            printf("%d ", matrix[i][j]);
            count ++;
        }
        row_start ++;

        if (count < row * col)
        {
            for (i = row_start; i <= row_end; i++) //last column
            {
                j = col_end;
                printf("%d ", matrix[i][j]);
                count ++;
            }
            col_end--;
        }

        if (count < row * col)
        {
            for (j = col_end; j >= col_start; j--) //bottom row
            {
                i = row_end;
                printf("%d ", matrix[i][j]);
                count++;
            }
            row_end--;
        }

        if (count < row * col)
        {
            for (i = row_end; i >= row_start; i--) //first column
            {
                j = col_start;
                printf("%d ", matrix[i][j]);
                count++;
            }
            col_start++;
        }
    }


 return 0;
}
