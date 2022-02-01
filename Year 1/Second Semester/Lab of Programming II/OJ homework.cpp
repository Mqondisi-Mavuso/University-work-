#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
    int n, a, b,i,j;

    cin >> n;
    int arr[n][n];

     for (int i = 0; i < n; i++)
    {

        for (int j = 0; j <= i; j++)
        {
           if (j == 0  || i == j)
                arr[i][j] = 1;
          else arr[i][j] = arr[i-1][j] + arr[i - 1][j - 1];

        }
    }

     for (int i = 0; i < n; i++)
    {
        for(int space = 0; space<(n-i); space++){
            if(space>0)cout << "  ";
        }
        for (int j = 0; j <= i; j++)
        {
            if(i==j)cout << right << setw(2) << arr[i][j];
            else
                cout << right << setw(2) << arr[i][j] << "  ";
        }

        cout << endl;
    }
    cout << endl;

 return 0;
}
