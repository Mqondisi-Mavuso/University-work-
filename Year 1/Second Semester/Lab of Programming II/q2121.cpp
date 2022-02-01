#include<iostream>
#include<string>
#include<sstream>
#include<ctype.h>

using namespace std;

class Decode{
public:
    string str;
    string str2;
    Decode(string a){
        for(int i=0; i<a.length(); i++){
            str += a[i];
        }
         for (int i = 0; i < str.length(); i+=3)
        {
            string temp;
            for(int j = i; j<i+3; j++){
                temp += str[j];
            }
                int asciiVal = stoi(temp);
                char letter  = char(asciiVal);
                stringstream ss;
                ss << letter;
                str2 += ss.str();
        }
    }
    string decode(){
        return str2;
    }
};
int main() {
  string str;
  cin>>str;
  Decode *code = new Decode(str);
  cout<<code->decode();
  return 0;
}
