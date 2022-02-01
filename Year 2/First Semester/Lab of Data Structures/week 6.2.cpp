#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

#define SIZE 11
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3


class Grid {
  public:
  	Grid():Grid(0) {}
  	Grid(int s) {
  		state = s;
  		dir[UP] = NULL;
  		dir[DOWN] = NULL;
  		dir[LEFT] = NULL;
  		dir[RIGHT] = NULL;
  	}
  	Grid *getDir(int d) const { return dir[d]; }
  	int getState() const { return state; }
  	void setDir(int d, Grid *g) { dir[d] = g; }
  	void setState(int s) { state = s;}
  private:
  	Grid *dir[4];
  	int state;
};

class List {
  public:
  	List() {
  		top = 0;
  	}
  	/*
  	Insert an element from top
  	*/
  	void addElement(Grid *g){
			data[top] = g;
      top++;
  	}
  	/*
  	remove an element from top and return a pointer point to the element.
  	If list is empty, return NULL.
  	*/
  	Grid *removeElement(){
        if(top == 0) return NULL;               //meaning the list is empty
        top--;                                  //move top to the previous grid
        return data[top+1];
  	}

    //***********************************************************
  	void printPath() const {
      cout<<top<<endl;
  		int j;
  		for(j = top - 1 ; j > 0 ; j--) {
  			if(data[j - 1] == data[j]->getDir(UP)) {
  				cout<<"UP\n";
  			}
  			else if(data[j - 1] == data[j]->getDir(DOWN)) {
  				cout<<"DOWN\n";
  			}
  			else if(data[j - 1] == data[j]->getDir(LEFT)) {
  				cout<<"LEFT\n";
  			}
  			else if(data[j - 1] == data[j]->getDir(RIGHT)) {
  				cout<<"RIGHT\n";
  			}
  		}
  	}
		int getTop() {
			return top;
		}
  private:
  	Grid *data[SIZE * SIZE];                //this will contain the grids which will represent the path
  	int top;                                //this is just an index "pointer" that we'll use to traverse the array of grids
};

class Maze{
  public:
  	Maze(){
  		initMaze(SIZE);
      reach = false;
  	}
  	/*
  	function initMaze
  	Alocate a 2-D link list with s * s sizes as the map of maze.
  	Inside the maze enery gird with state 0 represent empty space and 1 represent wall.
  	The gird in left top is start point and right bottom is finish point.
  	Randomly generate 20% wall in the maze.
  	Make sure start point and finish point are 0
  	動態配置一個二維的鏈結串列，大小是 s * s，用這個鏈結串列表示迷宮的地圖
  	節點中 0 的值表示可以移動的空間， 1 表示牆壁
  	左上角的位置表示起點，右下角的位置表示終點
  	請在迷宮中加入 20% 的牆壁
  	然後確定起點跟終點都是可以移動的位置
  	*/
  	void initMaze(int s) {
      Grid *tempMaze[s][s];                     //declaring a 2d grid array of s by s (10 by 10)
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < s; j++) {
                tempMaze[i][j] = new Grid();     //allocating Grind on each index of the 10 by 10 array (an array of grids)
            }
        }
      for (int x = 0; x < s; x++){             //this is for going through the s by s grid array and asigning random states(1 or 0)
        for (int y = 0; y < s; y++){
          int temp = rand() % 10;


          if(temp <= 2) {
            tempMaze[x][y]->setState(1); // assign one to represent the wall
          } else {
            tempMaze[x][y]->setState(0); // road
          }
          //if(x == 0 || y == 0 || x == s -1 || y == s -1) tempMaze[x][y] -> setState(1);  //generating the border
          if((x == 0 && y == 0) || (x == s - 1 && y == s - 1)) tempMaze[x][y]->setState(0);

					// =========
					// Diraction
						if((x + 1) < SIZE) tempMaze[x][y]->setDir(DOWN, tempMaze[x + 1][y]);   //defining what "DOWN" means in this maze
						if((x - 1) >= 0) tempMaze[x][y]->setDir(UP, tempMaze[x - 1][y]);
                        if((y + 1) < SIZE) tempMaze[x][y]->setDir(RIGHT, tempMaze[x][y + 1]);
						if((y - 1) >= 0) tempMaze[x][y]->setDir(LEFT, tempMaze[x][y - 1]);
					// =========

        }
      }
      maze = **tempMaze;                                                    //assign the pointer of pointers to maze
  	}
  	/*
  	function getPath
  	This function will find a path between start point and finish point.
  	Return a list content the path information inside.
  	If there is no path between two point then the list will be empty.
  	這個函數會找到起點到終點間的一條路徑
  	回傳一個 list 包含著路徑的資訊
  	如果找不到路徑的話 list 就會是空的
  	*/
  	List *getPath(Maze *m) {
        List *list = new List();                    //dynamically allocating a new list and assign it to the list pointer
        solveMaze(list, maze, m);
        if(list -> getTop() <= 1) return NULL;      //if list's top is only 1 or 0 it means the path was not found
      return list;
  	}
  	void printMaze() const {
  		Grid *j = maze, *k;
  		while(j != NULL) {
  			k = j;
  			while(k != NULL) {
  				cout<<k->getState()<<" ";
  				k = k->getDir(RIGHT);
  			}
  			cout<<endl;
  			j = j->getDir(DOWN);

  		}
      cout<<endl;
  	}

    void solveMaze(List *list, Grid* maze, Maze *m) {
      maze -> setState(7);                              //marking the first grid state
      if(maze->getDir(RIGHT) == NULL && maze->getDir(DOWN) == NULL){       //when we reach the bottom right corner
        list->addElement(maze);                             //adding that grid pointer to our list
        reach = true;
        return;
      }
    // =========
      if(!reach && maze->getDir(UP) && maze->getDir(UP)->getState() == 0){
        solveMaze(list, maze->getDir(UP), m);
      }
      if(!reach && maze->getDir(DOWN) && maze->getDir(DOWN)->getState() == 0){
        solveMaze(list, maze->getDir(DOWN), m);
      }
      if(!reach && maze->getDir(LEFT) && maze->getDir(LEFT)->getState() == 0){
        solveMaze(list, maze->getDir(LEFT), m);
      }
      if(!reach && maze->getDir(RIGHT) && maze->getDir(RIGHT)->getState() == 0){
        solveMaze(list, maze->getDir(RIGHT), m);
      }
      //if(maze->getState() == 7) maze->setState(0);
    // ========
      if(reach){                                                    //add the elements during return time
        list -> addElement(maze);
      }
    }
  private:
  	Grid *maze;
    bool reach;
};
Maze *ma;
int main() {
    srand(time(NULL));
    Maze *maze = new Maze();
    ma = maze;
	maze->printMaze();
    List *list = maze->getPath(maze);
    if(!list)
        cout<<"No path"<<endl;
    else list->printPath();
}
