#include<iostream>
#include<algorithm>

using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;
public:
    Fraction(){
        this ->numerator=0;
        this ->denominator=0;
    }
    Fraction(int numerator, int denominator){

        this->setNumerator(numerator);
        this->setDenominator(denominator);

    }
    int getNumerator()const{
        return numerator;
    }
    int getDenominator()const{
        return denominator;
    }
    void setNumerator(int _numerator){
        this ->numerator = _numerator;
    }
     void setDenominator(int _denominator){
        this->denominator = _denominator;
    }
    void display(){
        int _a = getNumerator();
        int _b = getDenominator();
        int hcf = __gcd(_a, _b);
        if(_b==0){
            return;
        }
        if(_a!=0){
             _a = _a/hcf;
            _b = _b/hcf;

        }
        if (_b==1){
            cout << _a;
        }
        else
        {
            cout << "(" << _a << "/" << _b << ")";
        }
    }

    Fraction operator +(const Fraction& example1){
        Fraction fracAnswer;
        fracAnswer.numerator = getNumerator() * example1.denominator + example1.numerator * getDenominator();
        fracAnswer.denominator = getDenominator() * example1.denominator;
        return fracAnswer;
        }

    Fraction operator -(const Fraction& example1){
        Fraction fracAnswer;
        fracAnswer.numerator = getNumerator() * example1.denominator - example1.numerator * getDenominator();
        fracAnswer.denominator = getDenominator() * example1.denominator;
        return fracAnswer;
        }
    Fraction operator *(const Fraction& example1){
        Fraction fracAnswer;
        fracAnswer.numerator = getNumerator() * example1.numerator;
        fracAnswer.denominator = getDenominator() * example1.denominator;
        return fracAnswer;
        }
    Fraction operator /(const Fraction& example1){
        Fraction fracAnswer;
        fracAnswer.numerator = getNumerator() * example1.denominator;
        fracAnswer.denominator = getDenominator()* example1.numerator;
        return fracAnswer;
        }
    void operator =(const Fraction& example1){
        numerator = example1.numerator;
        denominator = example1.denominator;
        }

};
