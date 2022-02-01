#include  <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int compareWordSets(string s1, string s2);              //function prototypes
void printResults(int value);
string s1{}, s2{};

int main(){

    int value{};
    cout << "Please input your two strings you want to compare: " << endl;
    while(cin >> s1 >> s2){
        value = compareWordSets(s1,s2);
        printResults(value);
    }
    return 0;
}

int compareWordSets(string s1, string s2){
    int num = -2;
    vector <char> vectorA{}, vectorB{};
    for(auto x: s1)                             //for pushing each charector into the vector
        vectorA.push_back(x);
    for(auto y: s2)
        vectorB.push_back(y);

    transform(vectorA.begin(), vectorA.end(), vectorA.begin(), ::tolower);      //this helps to allow comparison between lower and uppercase strings
    transform(vectorB.begin(), vectorB.end(), vectorB.begin(), ::tolower);

    sort(vectorA.begin(), vectorA.end());       //sorting ensures that we can compare even string which are input in any order
    sort(vectorB.begin(), vectorB.end());

    if((includes(vectorB.begin(), vectorB.end(), vectorA.begin(), vectorA.end())) && includes(vectorA.begin(), vectorA.end(), vectorB.begin(), vectorB.end()))
        num = 0;
    else if(includes(vectorA.begin(), vectorA.end(), vectorB.begin(), vectorB.end()))   //check if the values in vectorB are available in vectorA and return true or false
        num = 1;
    else if(includes(vectorB.begin(), vectorB.end(), vectorA.begin(), vectorA.end()))
        num = -1;
    else
        num = INT_MAX;

 return num;
}

void printResults(int value){
    switch(value){
        case -1: cout << "{"<< s1 << "}"<< " Is a Proper Subset of " << "{" << s2 << "}" << endl;
            break;
        case 1: cout << "{" << s1 << "}" << " Is a Proper Superset of " << "{" << s2 << "}" << endl;
            break;
        case 0: cout << "{" << s1 << "}" << " Is equivalent to " << "{" << s2 << "}" << endl;
            break;
        default: cout << "The strings are incomparable" << endl;
            break;
    }
}
