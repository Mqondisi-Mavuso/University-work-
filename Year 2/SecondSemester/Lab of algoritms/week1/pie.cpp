// https://oj.csie.ndhu.edu.tw/status?problemID=ALG02A
// Sharing pie equally among friends
#include<iostream>
#include<cstdio>
#include<math.h>

#define PI acos(-1.0)

using namespace std;


double volume[10010];
int pies;

int friends(double mid) {                       // divide each pie by the given mid from binary search
    int count = 0;
    for (int i = 0; i < pies; i++)
        count = count + (int)(volume[i] / mid);
    return count;

}

int main() {

    int cases, people;
    cin >> cases;
    while (cases--) {
        cin >> pies >> people;
        people++;                                       //ensures that the owner also gets a piece
        for (int i = 0; i < pies; i++) {
            cin >> volume[i];                           // inputing the radii of the pie
            volume[i] = (volume[i] * volume[i] * PI);   //volume of cylinder
        }

        //binary search
        double high = 1e9, low = 0.0, mid;
        for (int i = 0; i < 100; i++) {
            mid = (high + low) / 2.0;                   // mid starts as 500 million
            if (friends(mid) >= people)
                low = mid;
            else
                high = mid;
        }
        printf("%.6lf\n", mid);
    }
    return 0;
}
