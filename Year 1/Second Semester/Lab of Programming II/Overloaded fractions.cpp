#include <iostream>
#include <algorithm>
using namespace std;

using namespace std;
class Fraction
{
   private:
   int numerator, denominator;

   public:
   //default constructor
   Fraction(){
   }

  //constructor
   Fraction(int numerator, int denominator){
   setNumerator(numerator);
   setDenominator(denominator);
   }

   int getNumerator()const{
   return numerator;
   }

   int getDenominator()const{
   return denominator;
   }

   void setNumerator(int theNumerator){
   numerator = theNumerator;
   }

   void setDenominator(int theDenominator){
   denominator = theDenominator;
   }
    void display() const{
     int topNumber = getNumerator();
     int bottomNumber = getDenominator();

     int hcf = __gcd(topNumber, bottomNumber);//this helps to get the greatest common denominator
      topNumber = topNumber/hcf;
      bottomNumber = bottomNumber/hcf;

      if(bottomNumber == 1){
      cout <<topNumber;
     }
   	  else {cout<< "(" << topNumber << "/" << bottomNumber << ")";}
    }
	Fraction operator +(const Fraction& secondFraction){
        Fraction fracAnswer;
        fracAnswer.numerator = getNumerator() * secondFraction.denominator + secondFraction.numerator * getDenominator();
        fracAnswer.denominator = getDenominator() * secondFraction.denominator;
        return fracAnswer;
        }

    Fraction operator -(const Fraction& secondFraction){
        Fraction fracAnswer;
        fracAnswer.numerator = getNumerator() * secondFraction.denominator - secondFraction.numerator * getDenominator();
        fracAnswer.denominator = getDenominator() * secondFraction.denominator;
        return fracAnswer;
        }
    Fraction operator *(const Fraction& secondFraction){
        Fraction fracAnswer;
        fracAnswer.numerator = getNumerator() * secondFraction.numerator;
        fracAnswer.denominator = getDenominator() * secondFraction.denominator;
        return fracAnswer;
        }
    Fraction operator /(const Fraction& secondFraction){
        Fraction fracAnswer;
        fracAnswer.numerator = getNumerator() * secondFraction.denominator;
        fracAnswer.denominator = getDenominator() * secondFraction.numerator;
        return fracAnswer;
        }

    Fraction operator !(){
        Fraction fracAnswer;
        fracAnswer.numerator = this->getDenominator();
        fracAnswer.denominator = this->getNumerator();
        return fracAnswer;
    }

};
  ostream& operator <<(ostream& outputStream, const Fraction& a){
    a.display();
    return outputStream;
}

int main(){
    Fraction f1(2,4);
    Fraction f2(5,9);
    Fraction f3(12,4);
    Fraction f4(1,3);
    Fraction f5(3,4);
    Fraction f6(0,3);
    Fraction f7(5,0);

    f1.display();
    cout<<endl;
    f2.display();
    cout<<endl;
    f3.display();
    cout<<endl;
    f4.display();
    cout<<endl;
    f5.display();
    cout<<endl;
    f6.display();
    cout<<endl;

    Fraction a;
    a = ((((f1 + f2) - f3)*f4)/f5);
    cout<<"Overloaded Fraction: ";
    a.display();
    cout<<a;
    cout<<(!f1);
    cout<<endl;

    return 0;
}
