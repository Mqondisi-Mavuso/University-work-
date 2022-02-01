#include<stdio.h>


int findPath(int i, int j, int n, int arr[][n]);

int main(){
    int len;
    int path;
    scanf("%d", &len);

    int maze[len][len];
    int x, y;
    for (x = 0; x < len; x++){
        for (y = 0; y < len; y++){
            scanf("%d", &maze[x][y]);
        }
    }

    path = findPath(0, 0, len, maze);

    if(path == 1){
        printf("Yes");
    } else {
        printf("No");
    }

    return 0;
}

int findPath(int i, int j, int n, int arr[][n]){
    if (i == n-1 && j == n-1){
        return 1;
    }
    // Mark original array as visited
    arr[i][j] = 2;

    //check right
    if(j+1 < n && arr[i][j+1] == 0){
        if(findPath(i, j+1, n, arr) == 1) return 1;
    }

    //check down
    if(i+1 < n && arr[i+1][j] == 0){
        if(findPath(i+1, j, n, arr) == 1) return 1;
    }

     //check left
    if(j-1 >= 0 && arr[i][j-1] == 0){
        if(findPath(i, j-1, n, arr) == 1) return 1;
    }

    //check up
    if(i-1 >= 0 && arr[i-1][j] == 0){
        if(findPath(i-1, j, n, arr) == 1) return 1;
    }


    return 0;
}
