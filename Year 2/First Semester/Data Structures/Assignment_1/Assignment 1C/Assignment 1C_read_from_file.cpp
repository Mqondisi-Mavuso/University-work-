#include <iostream>
#include <fstream>                              //for reading from file
#include <algorithm>                            //use this for the sort(), trasform function
#include <vector>                               //use this for begin() and end()

using namespace std;

void star(int times);
void display(vector<char> letters, int len);         //funtion prototypes


int times{0};
char letter{};
vector <char> letters{};

int main(){

        ifstream my_file;
        string line{};
        my_file.open("text.txt");

        if(!my_file){                                           //check to see if the file is there or not
            cerr << "Error could not read from file" << endl;
            return 1;
        }

        while(getline(my_file, line)){
            transform(line.begin(), line.end(), line.begin(), ::tolower);   //convert to lower cases
            line.erase(remove(line.begin(), line.end(), ' '), line.end());  //erase spaces
            for(char c : line){
                if(isalpha(c)){
                    letters.push_back(c);               //push only letters from each line into the vector
                }
            }
        }
        int len = letters.size();
        sort(letters.begin(), letters.end());           //sort the vector in alphabetic order
        display(letters, len);                          //display the histogram

    my_file.close();                                    //close the file
    return 0;
}

void display(vector <char> letters, int len){  //this displays the histogram with the help of the star()
    for(int i = 0; i < len; i += times){
        letter = letters.at(i);
        times = count(letters.begin(), letters.end(), letter);
        cout << letter << " ";
        star(times);
        cout << times << endl;
        }
    }

void star(int times){
    int a = times;
    while(times){
        cout << '*';
        times--;
    }
}
