#include <iostream>
#include <vector>

using namespace std;

    vector <int> A;                                  //declaring the stacks
    vector <int> B;
    vector <int> C;

void tower(int num, vector <int> *A, vector <int> *B, vector <int> *C);    //function prototypes

int main(){
    int num, a = 1, b = 2, c = 3;
    //char a = 'A', b = 'B', c = 'C';
    cout <<"Please entre the number of disks: ";
    cin >> num;
    for(int i = 0; i < num; i++){
        A.push_back(num - i);
    }
    cout << "Initial pegs"<<endl;
    cout << 'A';
    for (int i = 0; i < num; i++) {
        cout << A.at(i);
    }
    cout<<endl;
    cout << 'B';
    cout << endl;
    cout << 'C';
    cout << endl;
    tower(num, &A, &B, &C);

    return 0;
}

void tower(int num, vector <int> *A, vector <int> *B, vector <int> *C){
    if(num > 0){
        static vector<int> *addressA = A;
        static vector<int> *addressB = B;
        static vector<int> *addressC = C;

         tower(num - 1, A, C, B);
        char a{}, b{};
        if (A == addressA) {
            addressA->pop_back();
            a = 'A';
        }
        if (A == addressB) {
            addressB->pop_back();
            a = 'B';
        }
        if (A == addressC) {
            addressC->pop_back();
            a = 'C';
        }
        if (C == addressA) {
            addressA->push_back(num);
            b = 'A';
        }
        if (C == addressB) {
            addressB->push_back(num);
            b = 'B';
        }
        if (C == addressC) {
            addressC->push_back(num);
            b = 'C';
        }
        cout << "Move disk "<< num << " from peg "<< a <<" to peg " << b <<endl;
        cout << 'A';
        for (auto num : *addressA) {
            cout << num;
        }
        cout << endl;
        cout << 'B';
        for (auto num : *addressB) {
            cout << num;
        }
        cout << endl;
        cout << 'C';
        for (auto num : *addressC) {
            cout << num;
        }
        cout << endl;
        tower(num - 1, B, A, C);
        }
    }
