#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;
typedef long long ll;

bool myCompare(int, int );
void printLargest(vector<ll>);

int main(){
	vector<ll> num_inputs;
	int total, cases;
    ll num, sum;
    cout << "Please input test cases: ";
    cin >> cases;
    
    while(cases){
        
        cout << "Please input the number of intergers you want to check: ";
        cin >> total;
        cout << "Please input your individual numbers: ";
        while(total){
            cin >> num;
            num_inputs.push_back(num);
            total --;
        }
        cases--;
        cout << "The largest value is: ";
        sum = accumulate(num_inputs.begin(), num_inputs.end(), 0); //takes O(N)
        if (sum == 0) cout << "0";          
        else printLargest(num_inputs);
	    num_inputs.clear();                 // this takes O(N)
    }
	return 0;
}

bool myCompare(int x, int y){
	int xy = x, yx = y, x_count = 0, y_count = 0;
	while (x > 0) {
		x_count++;
		x /= 10;
	}

	while (y > 0) {
		y_count++;
		y /= 10;
	}

	x = xy;
	y = yx;

	while (x_count--) {yx *= 10;}

	while (y_count--) {xy *= 10;}
	yx += x;
	xy += y;
	
	return xy > yx;
}

void printLargest(vector<ll> arr){
	sort(arr.begin(), arr.end(), myCompare);        //takes O(nlog(n))
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i];
	cout << endl << endl;
}


/*
Example 1:
Input: nums = [1 23 456 789 101112]
Output: "789456231101112"
Explanation: 789 456 23 1 101112 is the largest number


Example 2:
Input: nums = [1, 2, 3, 4, 5]
Output: "54321"
Explanation: 5 4 3 2 1 is the largest number


Example 3:
Input: nums = [0, 0, 0]
Output: "0"

*/