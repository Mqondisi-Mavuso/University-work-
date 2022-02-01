#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

class ListNode{
    private:
        int value; //this is the value that will be used in the add function

    public:
        ListNode * next;
        ListNode * prev;
        ListNode(int theValue){
        this -> value = value;
        this ->next = NULL;
        this ->prev = NULL;
        }

    int getValue(){
        return this->value; //this returns the value in the private scope
        }
};

class Digit
{

    private:
        int digit; //this is the digit that will be used in the setDigit function

    public:
        int n;
    Digit()
      {
      digit = 0;
      }

    Digit(int n){
        setDigit(n);
        }
        void setDigit(int digit){
            if (digit >=0 && digit <= 9){
            this -> digit = digit;
            }
            else this -> digit = 0;
        }

      int getDigit(){
      return digit;
      }
};
class IntNumber
{
   private:
    Digit digit[10000];
    int counter;
    char* number;
    bool plus = false;
    bool minus = false;
    bool start = false;

  public:

    IntNumber() {

    }

    IntNumber(char* number) {
      string num(number);
      counter = 0;
      for(int i = 0 ; i < num.size() ; i++) {

        if(num[0] == '+' && !plus) {
          plus = true;
          i++;
        } else if(num[0] == '-' && !minus) {
          minus = true;
          i++;
        }
        if(isalpha(num[i])) break;

        if(num[i] > '0' && num[i] <= '9') start = true;

        if(num[i] >= '0' && num[i] <= '9' && start) {
          digit[counter].setDigit(num[i] - 48);
          counter++;
        }
      }
    }

    void display() {
      if(counter == 0) {
        cout << "0";
        return;
      }
      if(plus);
      if(minus) cout << "-";
      for (int i = 0; i < counter; i++) {
        cout << digit[i].getDigit();
      }
    }
     char * getNumber(){
      return this -> number;
    }
    IntNumber * add(IntNumber * intNumber){
        ListNode * a = NULL;
        ListNode * b = NULL;
        ListNode * sumNode = NULL;

        for(int i = strlen(number)-1; i >=0; i--){
            int tempNumber = number[i] - '0';
            if (!a) a = new ListNode(tempNumber);
            else{}
        }
        long int sum = atol(number) + atol(intNumber this->getNumber());
        string theSum = to_string(sum);
        char* theSum = &theSum[0];
        return new IntNumber (theSum);
    }

};
int main()
{
  char num[10000];
  cin>>num;
  IntNumber *number = new IntNumber(num);
  number -> display();
  return 0;
}

