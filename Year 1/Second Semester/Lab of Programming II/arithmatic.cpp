#include <iostream>

using namespace std;

int main ()
{
    int firstTerm, increment, n, i,a, previousNumber = 0;


    cin >> firstTerm >> increment >> n;
    int arr[n];

    a = 1;
    for ( i = 0; i < n; i ++)
    {


            cout <<"a"<<"["<< a <<"]"<<"="<< firstTerm+(i)*increment<< endl;

            a ++;

    }

 return 0;
}
