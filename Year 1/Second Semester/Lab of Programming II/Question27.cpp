#include <iostream>

using namespace std;

int main() {
    int t, x, y, i, j, test = 0;
    string directions;
    cin>>t;
    while(t > 0 ) {
        int map[32][32] = {};
        cin>>x>>y;
        cin>>directions;
        int size = directions.length();
        for(int i = 0; i < size; i++) {
            if(directions[i] =='E') {
                map[x][y-1] = 1;
                x++;
            }
            if(directions[i] =='N') {
                map[x][y] = 1 ;
                y++;
            }
            if(directions[i] =='W') {
                map[x-1][y] = 1;
                x--;
            }
            if(directions[i] =='S') {
                map[x-1][y-1] = 1;
                y--;
            }
        }
        cout<<"Bitmap #"<<++test<<endl;
        for(i = 31; i >= 0; i-- ) {
            for(j = 0; j <32; j++) {
                char to_print = (map[j][i] == 1)?'X':'.';
                cout<<to_print;
            }
            cout<<endl;
        }
        cout<<endl;
        --t;
    }
    return 0;
}
