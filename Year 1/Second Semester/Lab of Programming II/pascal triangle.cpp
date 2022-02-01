#include <iostream>
#include <iomanip>

using namespace std;

void printPascal(int n){
    int arr[n][n];

    for(int row=0; row<n; row++){
        for(int space=0; space<(n-row); space++){
            if (space>0)
                cout << "  ";
        }
        for(int col=0; col<=row; col++){
            if(col==0 || row==col)
                arr[row][col] = 1;
            else
                arr[row][col] = arr[row-1][col-1] + arr[row-1][col];
            if (col==row)
                cout << std::right << std::setw(2) << arr[row][col];
            else
                cout << std::right << std::setw(2) << arr[row][col] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

int main (){

    int n;
    cin >> n;
    printPascal(n);

return 0;
}
