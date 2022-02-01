#include <iostream>
#include<cstdlib>
#include<ctype.h>
#include <queue>

using namespace std;

class Nurikabe
{
public:
    /*
    n is the size of the Nurikabe, n >= 5, n <= 20
    game is the result from some player
    here is one example
    n: 5
    game = { {'W', 'W', 'W', '1', 'W'},
             {'W', '.', 'W', 'W', 'W'},
             {'W', '2', 'W', '.', '3'},
             {'3', 'W', 'W', '.', 'W'},
             {'.', '.', 'W', 'W', 'W'} };
    W represent wall
    */
    Nurikabe(char game[20][20], int n)
    {
        size = n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                arrayA[i][j] = game[i][j];
    }
    /*
    return 1 if result fit the rule.
    return 0 if result not fit the rule.
    */
    int iscorrect()
    {
        //creates borderArr
        char borderArr[22][22];
        for (int i = 0; i < size + 2; i++)
            for (int j = 0; j < size + 2; j++)
                borderArr[i][j] = '*';

        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                borderArr [i + 1][j + 1] = arrayA[i][j];


        bool found = false;
        int walli, wallj;

        //Looks for invalid Chars and the first wall
        //the first wall
        //Looks if there is a square region of walls
        for (int i = 1; i < size + 1; i++) {
            for (int j = 1; j < size + 1; j++) {
                //Looks for invalid Chars and the first wall
                if (borderArr[i][j] != '.' && borderArr[i][j] != 'W' && !(borderArr[i][j] > '0' && borderArr[i][j] <= '9'))
                    return 0;
                //the first wall
                if (!found && arrayA[i][j] == 'W') {
                    walli = i;
                    wallj = j;
                    found = true;
                }
                if (borderArr[i][j] == 'W' && borderArr[i + 1][j + 1] == 'W' && borderArr[i + 1][j] == 'W' && borderArr[i][j + 1] == 'W')
                    return 0;
            }
        }

        //Looks for islands and see if they match their number
        for (int i = 1; i < size + 1; i++) {
            for (int j = 1; j < size + 1; j++) {
                if (borderArr[i][j] > '0' && borderArr[i][j] <= '9') {
                    int number = borderArr[i][j] - '0'; //convert the char number to int
                    int count = 1, x, y;
                    queue<int> Ix, Iy;                  //intialize two int queues
                    Ix.push(i);
                    Iy.push(j);
                    borderArr[i][j] = '-'; //mark index with '-' to show we have checked it
                    while (!Ix.empty() && !Iy.empty()) {
                        x = Ix.front();
                        y = Iy.front();

                        //Check if there is a dot ('.') below
                        if (borderArr[x + 1][y] == '.') {
                            Ix.push(x + 1);
                            Iy.push(y);
                            borderArr[x + 1][y] = '-'; //mark index with '-' to show we have checked it
                            count++;
                        }
                        else if (borderArr[x + 1][y] > '0' && borderArr[x + 1][y] <= '9')//islands should not touch
                            return 0;

                        //Above
                        if (borderArr[x - 1][y] == '.') {
                            Ix.push(x - 1);
                            Iy.push(y);
                            borderArr[x - 1][y] = '-';  //mark index with '-' to show we have checked it
                            count++;
                        }
                        else if (borderArr[x - 1][y] > '0' && borderArr[x - 1][y] <= '9')//islands should not touch
                            return 0;

                        //right
                        if (borderArr[x][y + 1] == '.') {
                            Ix.push(x);
                            Iy.push(y + 1);
                            borderArr[x][y + 1] = '-';  //mark index with '-' to show we have checked it
                            count++;
                        }
                        else if (borderArr[x][y + 1] > '0' && borderArr[x][y + 1] <= '9')//islands should not touch
                            return 0;

                        //Left
                        if (borderArr[x][y - 1] == '.') {
                            Ix.push(x);
                            Iy.push(y - 1);
                            borderArr[x][y - 1] = '-';  //mark index with '-' to show we have checked it
                            count++;
                        }
                        else if (borderArr[x][y - 1] > '0' && borderArr[x][y - 1] <= '9')//islands should not touch rule
                            return 0;

                        //island is bigger than number (its size)
                        if (count > number)
                            return 0;

                        Ix.pop();
                        Iy.pop();
                    }
                }
            }
        }

        //Are the islands continous or not
        int x, y;
        queue<int> Ix, Iy;
        Ix.push(walli); Iy.push(wallj);         //walli and wallj are the first index we found a wall at
        borderArr[walli][wallj] = 'B';          //mark the visited wall with B

        while (!Ix.empty() && !Iy.empty()) {
            x = Ix.front(); y = Iy.front();
            if (borderArr[x + 1][y] == 'W') {
                Ix.push(x + 1);
                Iy.push(y);
                borderArr[x + 1][y] = 'B';
            }
            if (borderArr[x - 1][y] == 'W') {
                Ix.push(x - 1); Iy.push(y);
                borderArr[x - 1][y] = 'B';
            }
            if (borderArr[x][y + 1] == 'W') {
                Ix.push(x); Iy.push(y + 1);
                borderArr[x][y + 1] = 'B';
            }
            if (borderArr[x][y - 1] == 'W') {
                Ix.push(x); Iy.push(y - 1);
                borderArr[x][y - 1] = 'B'; }
            Ix.pop();
            Iy.pop();
        }

        //Looks for discontinuous isands and walls
        for (int i = 1; i < size + 1; i++) {    //loop through the array again and if there is still b it means it is isolated
            for (int j = 1; j < size + 1; j++) {
                if (borderArr[i][j] == '.' || borderArr[i][j] == 'W')return 0;
            }
        }

        return 1;
    }
private:
    //Please design your own data structure to keep the result
    char arrayA[20][20];
    int size;
};
int main() {
    int n = 5, j, l, k;
    char game[20][20] = { {'W', 'W', 'W', '1', 'W'},
                         {'W', '.', 'W', 'W', 'W'},
                         {'W', '2', 'W', '.', '3'},
                         {'3', 'W', 'W', '.', 'W'},
                         {'.', '.', 'W', 'W', 'W'} };
    /*std::cin>>n;
    for(j = 0;j < n;j ++)
      for(k = 0;k < n;k ++)
        std::cin>>game[j][k];*/
    Nurikabe* a = new Nurikabe(game, n);
    std::cout << a->iscorrect();
    return 0;
}
