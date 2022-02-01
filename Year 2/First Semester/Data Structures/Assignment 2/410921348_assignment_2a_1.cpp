#include <iostream>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>


using namespace std;

int setA[]{5, 2, 2, 9, 10, 1}, setB[]{2, 4, 6, 8, 10};
void display();
void displaySet(set <int> sett);
class Set{
    public:
    set <int> s;
    set <int> intersect, s1, s2, difference;            //standard template library set
    void setUnion(){
        for(auto x: setA)
            s.insert(x);                                //instert will not include duplicates
        for(auto y: setB)
            s.insert(y);

        displaySet(s);
    }

    void setIntersection(){                          //intersection was found using the algorithm library function "set_difference" and "inserter"
        for(auto x: setA)
            s1.insert(x);

        for(auto p: setB)
            s2.insert(p);
        set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(),        //set_intersection is from the algorithm library
                 std::inserter(intersect, intersect.begin()));

        displaySet(intersect);
    }

    void setDifference(char a, char b){                 //difference was found using the algorithm library function "set_difference" and "inserte"
        if(a == 'A' && b == 'B'){
            std::set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(),
            std::inserter(difference, difference.end()));
            displaySet(difference);
        }

        else if(a == 'B' && b == 'A'){
            difference.clear();             //delete all the elements in the set before computing the difference
            std::set_difference(s2.begin(), s2.end(), s1.begin(), s1.end(),
            std::inserter(difference, difference.end()));
            displaySet(difference);
        }
        else
            cout << endl << "Please check your input and try again" << endl;

    }
};

int main(){
    Set theSet;
    char A, B, G, I;
    display();
    cout << endl;
    cout << "The set union: ";
    theSet.setUnion();
    cout <<endl << endl << "The set Intersect: ";
    theSet.setIntersection();
    cout << endl;
    cout <<endl << "The set Difference (A - B): ";
    theSet.setDifference('A', 'B');
    cout << endl;
    cout <<endl << "The set Difference (B - A): ";
    theSet.setDifference('B', 'A');
    cout << endl;
 return 0;
}

 void display(){                    //this is for displaying the intial arrays
    cout << "Original sets: ";
    cout << "Set A {";
    for(auto x: setA)
        cout << x << " ";
        cout <<"}";
    cout  << " Set B {";
    for(auto y: setB)
        cout << y << " ";
        cout <<"}" << endl;
 }

 void displaySet(set <int> sett){           //displays the set elements with the help of an iterator
    set<int , greater<int> >::iterator itr;
        for(itr = sett.begin(); itr != sett.end(); itr++)
            cout << *itr << " ";
 }
