#include <iostream>
#include <cstdio>
#include <cstdlib>
//#define N 4
#define N 8
using namespace std;
/* print solution */
void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout<<board[i][j]<<" ";
        cout<<endl;

    }
cout<<endl;

}
/* check if a queen can be placed on board[row][col]*/
bool isSafe(int board[N][N], int row, int col)
{
//*************************

for (int i = 0; i < col; i++)
    if (board[row][i])
        return false;


for (int i=row, j=col; i>=0 && j>=0; i--, j--)
    if (board[i][j])
        return false;


for (int i=row, j=col; j>=0 && i<N; i++, j--)
    if (board[i][j])
        return false;

return true;
//**************************
}
/*solve N Queen problem */
bool solver(int board[N][N], int col)
{
if (col >= N)
{
    printSolution(board);
    return true;
}

bool res = false;

for (int i = 0; i < N; i++)
{
    if ( isSafe(board, i, col) )
    {

    board[i][col] = 1;

    res = solver(board, col + 1) || res;


    board[i][col] = 0;
    }
}
return res;

}
/* solves the N Queen problem using Backtracking.*/
bool solveNQ()
{
    int board[N][N] = {0};
    if (solver(board, 0) == false) {
    cout<<"Solution does not exist"<<endl;
    return false;
}

printSolution(board);
return true;

}// Main
int main()
{
    solveNQ();
    return 0;
}