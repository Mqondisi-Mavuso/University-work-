#include<stdio.h>

int main(void){
    int r, c, n, i, j, value, row, column;

    scanf("%d %d %d", &r, &c, &n);
    int matrix[r][c];

    for (i = 0; i < r; i++){
        for (j = 0; j < c; j++){
            matrix[i][j] = 0;
        }
    }

    for(i = 0; i < n; i++){
        scanf("%d %d %d", &row, &column, &value);
        matrix[row][column] = value;
    }

    for (i = 0; i < r; i++){
        for (j = 0; j < c; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
