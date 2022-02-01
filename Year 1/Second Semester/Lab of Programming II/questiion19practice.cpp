#include <iostream>

using namespace std;

int main(){
    int x,y,i,j,testCases, tests=0;
    string directions;
    cin>>testCases;

    while (testCases > 0){
        int map[32][32]= {};
        cin >>x>>y; //starting point
        cin>>directions;

        int size = directions.length();
        for (int i =0; i < size; i++){
            if(directions[i] == 'E'){
             map[x][y-1] = 1;
             x++;
            }
            if (directions[i] == 'N'){
                map[x][y] = 1;
                x++;
            }
            if(directions[i] == 'W'){
                map[x-1][y] = 1;
                x--;
            }
            if (directions[i] == 'S'){
                map[x-1][y-1] = 1;
                y--;
            }
        }
       cout <<"Bitmap #"<<++tests<<endl;
       for(int i = 31; i >= 0; i--){
            for(int j = 0; j < 32; j++){
                char to_print = (map[j][i] == 1)?'X':'.';
                cout <<to_print;
            }
            cout <<endl;
       }
       cout<<endl;
       --testCases;
    }
 return 0;
}
