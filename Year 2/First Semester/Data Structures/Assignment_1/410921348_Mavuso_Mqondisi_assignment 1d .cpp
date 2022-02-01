#include <iostream>

using namespace std;

void calculate(int a, char op, int b){
        float results = 0;
        try{
            if(op != '+' && op != '-' && op != '*' && op != '/') throw 0;           //if it's an unkown operator throw an exeption and catch it on line 26
                else if( op == '+') results = a + b;
                else if(op == '-') results = a - b;
                else if (op == '*') results = a * b;
                else{
                    try{
                        if(b == 0) throw 0;
                        float A =  a, B = b;                                   //trying to divide by 0? throw an exeption and catch it on line 18
                            results = A / B;

                    }catch(int &ex) {
                        cout<< "Sorry, Cannot divide by zero"<<endl;
                    }
                }
         cout <<"Results: " <<  results << endl;
        }catch(int &e){
            cout << "Unknown operator" << endl;
        }

}

int main(){
    char op;
    int a, b;
    do{
        cout<<"Please enter 2 operands the operator in this format (2 * 3): "<<endl;
        cin >> a >> op >> b;
        calculate(a, op, b);                                                        //calling the calculate function

    }while(op);

  return 0;
}
