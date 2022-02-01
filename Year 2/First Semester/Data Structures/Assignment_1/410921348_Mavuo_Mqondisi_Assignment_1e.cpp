#include <iostream>

using namespace std;

void magic(int n)
// create a magic square of size n, n is odd
{
    const int MaxSize = 51; // maximum square size
    int square[MaxSize][MaxSize], k, l;

    // check correctness of n
    if ((n > MaxSize) || (n < 1)) { cerr << "Error!..n out of range \n"; return; }
    else if (!(n % 2)) { cerr << "Error!..n is even \n"; return; }

    // n is odd. Coxeter's rule can be used
    for (int i = 0; i < n; i++) // initialize square to 0
        for (int j = 0; j < n; j++)
            square[i][j] = 0;
    square[0][(n - 1) / 2] = 1; // middle of first row

    // i and j are current position
    int key = 2; int i = 0; int j = (n - 1) / 2;
    while (key <= n * n) {
        // move up and left
        if (i - 1 < 0)  k = n - 1; else k = i - 1;
        if (j - 1 < 0)  l = n - 1; else l = j - 1;
        if (square[k][l])  i = (i + 1) % n;
        else { // square[k][l] is unoccupied
            i = k;
            j = l;
        }
        square[i][j] = key;
        key++;
    } // end of while

    // print the magic square
    cout << "magic square of size " << n << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            cout << square[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int sizes[] = { 5, 7, 9, 11 };
    int i;
    clock_t start, stop;
    for (i = 0; i < 4; i++) {
        double runTime = 0;
        double totRunTime = 0;
        int j;
        cout << sizes[i] << " magic boxes:" << endl;
        for (j = 5; j <= 50; j += 5) {
            clock_t start, stop;
            int k;
            start = clock();//start time
            for (k = 1; k <= j; k++) {
                magic(sizes[i]);
            }
            stop = clock();//stop time
            auto totalTime = (double)(stop - start) / CLOCKS_PER_SEC;
            runTime = totalTime / (double)(j);
            cout << "Total runtime for " << j << ": " << totalTime << endl;
            cout << " Average runtime for " << j << ": " << runTime << endl;
            cout << "Times are in seconds." << endl;
            cout << endl;
        }
        cout << endl;
    }
}
