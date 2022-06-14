//This is the Hungarian Algorithm 
// We are trying to find the minimum time required
// .. to travel to allocated places
#include <iostream>
#include <string.h>
#include <math.h>
#define eps 1e-6

using namespace std;

double W[105][105];
int N, M;
int mx[105], my[105]; // match arr
double lx[105], ly[105]; // label arr
int x[105], y[105]; // used arr

int hungary(int nd) {
    int i;
    x[nd] = 1;
    for (i = 1; i <= M; i++) {
        if (y[i] == 0 && fabs(W[nd][i] - lx[nd] - ly[i]) < eps) {
            y[i] = 1;
            if (my[i] == 0 || hungary(my[i])) {
                my[i] = nd;
                return 1;
            }
        }
    }
    return 0;
}
double KM() {
    int i, j, k;
    double d;
    memset(mx, 0, sizeof(mx));
    memset(my, 0, sizeof(my));
    memset(lx, 0, sizeof(lx));
    memset(ly, 0, sizeof(ly));
    for (i = 1; i <= N; i++)            // this will take O(n*m)
        for (j = 1, lx[i] = W[i][j]; j <= M; j++)
            lx[i] = lx[i] > W[i][j] ? lx[i] : W[i][j];
    for (i = 1; i <= N; i++) { // this will take {3n^2 * 2m}  = O(n^2 * m)
        while (1) {
            memset(x, 0, sizeof(x));
            memset(y, 0, sizeof(y));
            if (hungary(i))  break;
            d = 0xfffffff;
            for (j = 1; j <= N; j++) {      // this will take O(n*m)
                if (x[j]) {
                    for (k = 1; k <= M; k++)
                        if (!y[k])
                            d = d < lx[j] + ly[k] - W[j][k] ?
                            d : lx[j] + ly[k] - W[j][k];
                }
            }
            if (d == 0xfffffff)  break;
            for (j = 1; j <= N; j++)           // this will take O(n)
                if (x[j])    lx[j] -= d;
            for (j = 1; j <= M; j++)           // this takes O(m)
                if (y[j])    ly[j] += d;
        }
    }
    double res = 0;
    for (i = 1; i <= M; i++) {      // chosing the correct match for police criuze 
        if (my[i])
            res += W[my[i]][i];
    }
    return res;
}


int main() {
    int n, m;
    float x, y;
    while (scanf("%d %d", &n, &m) == 2) {// store the n(bank) and m(police cruise)
        if (n == 0 && m == 0)           // used for quiting the while loop
            break;
        N = n, M = m;
        for (int i = 1; i <= n; i++) {  //store values in 2d array
            for (int j = 1; j <= m; j++) {
                cin >> x;
                W[i][j] = x;
                W[i][j] *= -1;
            }
        }
        printf("%.2lf\n", -KM() / n + eps);
    }
    return 0;
}