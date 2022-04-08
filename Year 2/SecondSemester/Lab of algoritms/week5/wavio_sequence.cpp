#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int n, num[10000], lis[10000], lds[10000];          // declaring the arrays to store the numbers 
    vector<int> v;
    while (scanf("%d", &n) != EOF)  // this will run until, we reach the end of file 
    {
        int i;
        for (i = 0; i < n; i++) // This is for collecting the sequence and store it in the num array
            scanf("%d", &num[i]);       // this takes O(n)

        v.clear();
        int size = 1;
        v.push_back(num[0]);           
        lis[0] = 1;
        for (i = 1; i < n; i++)     // This takes O(n), this is for adding the numbers that are in susequence into the vector 
        {
            if (num[i] > v.back())
            {
                v.push_back(num[i]);
                lis[i] = ++size;
            }
            else
            {
                int temp = lower_bound(v.begin(), v.end(), num[i]) - v.begin();
                v[temp] = num[i];
                lis[i] = temp + 1;
            }
        }

        v.clear();
        size = 1;
        v.push_back(num[n - 1]);
        lds[n - 1] = 1;
        for (i = n - 2; i >= 0; i--)            // This takes O(n)
        {
            if (num[i] > v.back())
            {
                v.push_back(num[i]);
                lds[i] = ++size;
            }
            else
            {
                int temp = lower_bound(v.begin(), v.end(), num[i]) - v.begin();
                v[temp] = num[i];
                lds[i] = temp + 1;
            }
            
        }

        int max = 0;
        for (i = 0; i < n; i++)         // This takes O(n)
        {
            int temp = min(lis[i], lds[i]); // stores the mininum into the temp variable 
            if (max < temp)
                max = temp;
        }

        printf("%d\n", max * 2 - 1);
    }

    return 0;
}
