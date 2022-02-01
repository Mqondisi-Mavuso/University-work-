#include<iostream>
#include<cstdlib>
#include<ctime>
#include <stack>

#define SIZE 11

using namespace std;

class Node
{
public:
	Node(): Node(0, 0)
	{
	}
	Node(int r, int c)
	{
		row = r;
		col = c;
	}
	int getRow() const { return row; }
	int getCol() const { return col; }
	void setRow(int r)
	{
		if(r >= 0 && r < SIZE)
			row = r;
	}
	void setCol(int c)
	{
		if(c >= 0 && c < SIZE)
			col = c;
	}
private:
	int col, row; //data;
};

class List
{
public:
	List()
	{
		top = 0;
	}
	/*
	function addElement
	Insert an element into list
	*/
	void addElement(int r, int c){
	    data[top] = Node(r, c);
        top++;
	}
	/*
	function removeElement
	remove an element from list and return a pointer point to the element.
	If list is empty, return NULL.
	*/
	Node *removeElement()
	{
	    if(!top) return NULL;
	    top --;                     //make top the previous element before we "delete" the current top
	    return &data[top + 1];
	}

	void printList()
	{
		int j;
		for(j = top -1  ;j >= 0;j --)
		{
			cout<<"("<<data[j].getRow()<<", "<<data[j].getCol()<<")"<<endl;
		}
	}

	int getTop(){return top;}
private:
	Node data[SIZE * SIZE];
	int top;
};

class Maze
{
public:
	Maze()
	{
		initMaze(SIZE);
	}

	void initMaze(int s)
	{
	    int **tempMaze  = new int*[s];                     //tempMaze is a pointer to an array of pointers that will point to the rows of the maze
	    for(int i = 0; i < s; i ++){
            tempMaze[i] = new int[s];
	    }

	    for(int a = 0; a < s; a++){
            for(int b = 0; b < s; b++){
                int random = rand() % 10;
                tempMaze[a][b] = random;
                if(random <= 2) tempMaze[a][b] = 1;
                else tempMaze[a][b] = 0;

                if(a == 0 || b == 0 || a == s -1 || b == s -1) tempMaze[a][b] = 1;        //generating the border
                if((a == 1 && b == 1) || (a == s - 2 && b == s - 2)) tempMaze[a][b] = 0;

                //cout << tempMaze[a][b] << " ";
            }
            //cout << endl;
	    }
	    maze = tempMaze;
	}

	List *getPath()
	{
        List *list = new List();
        solveMaze(list, 1, 1);
        if(list -> getTop() <= 1) return NULL;
        return list;
	}
	void printMaze()
	{
		int j, k;
//        int **temp[10];
//        temp = &maze;
		for(j = 0;j < SIZE;j ++)
		{
			for(k = 0;k < SIZE;k ++)
			{
				if(maze[j][k] == 0)
					cout << " ";
				else if(maze[j][k] == 1)
					cout << "*";
			}
			cout << "\n";
		}
	}

    void solveMaze(List *list, int i, int j) {
        if(i == SIZE - 2 && j == SIZE - 2){
            list->addElement(SIZE-2, SIZE-2);
            destination = true;
            return;
          }
        maze[i][j] = -7;                                       //flag this as starting point

        if(!destination && maze[i+1][j] == 0) {
            solveMaze(list, i+1, j);                            //recursive call below
          }
        if(!destination && maze[i-1][j] == 0) {
            solveMaze(list, i - 1, j);                          //recursive call above
          }

        if(!destination && maze[i][j+1] == 0) {
            solveMaze(list, i, j+1);                             //recursive on the right
          }
        if(!destination && maze[i][j-1] == 0) {
            solveMaze(list, i, j-1);                            //recursive call on the left
          }

        if(maze[i][j] == - 7) maze[i][j] = 0;

        if(destination) {
            list -> addElement(i, j);
          }
    }

private:
	int **maze;
	bool destination = false;
};

int main()
{
    srand(time(NULL));
    Maze *maze = new Maze();
    maze->printMaze();
    List *list = maze->getPath();
    if(!list) {
        cout<<"No path"<<endl;
    }else {
        list->printList();
    }
}
