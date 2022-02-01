#include <iostream>
#include <string.h>


using namespace std;

int main ()
{
    string s;
    string new_s = "";
    int i;

    cin >> s;
    for (i = s.size()-1;i >= 0;i--){
        new_s += s[i];

        cout << static_cast<char>(toupper(s.at(i)));
    }


 return 0;
}
