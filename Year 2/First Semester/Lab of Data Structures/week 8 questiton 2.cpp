#include<iostream>
#include<cstdlib>
#include<ctime>
#include <queue>

using namespace std;

class Tree
{
public:
	Tree() {
		int j, k;
		for(j = 0;j < 20;j ++) {
          for(k = 0;k < 4;k ++) {
            root[j][k] = -1;
          }
        }
	}
	int insert(int node) {
		int f = 0;
        int index = 0;

		while(root[index][0] != -1){ //looping through the 1st column 2d array and find a non -1 value to do something
        index++;
        }
		if(index >= 20){    //meaning we reached the end of the 2d array
            return -1;
        }

		if(index == 0) {
			root[0][0] = 1;
			root[0][1] = node;
			return 1;
		}
		else {
			root[index][0] = 1;
			root[index][1] = node;
			while(1) {
				if(root[f][1] < node) {
					if(root[f][3] == -1) {
						root[f][3] = index;
						return 1;
					}
					else {
						f = root[f][3];
					}
				}
				else {
					if(root[f][2] == -1) {
						root[f][2] = index;
						return 1;
					}
					else {
						f = root[f][2];
					}
				}
			}
		}
	}
  void inorder() {
    int current = 0;
    if(root[0][0] == -1) {
      return;
    }
    inorder(root[0][2]);  //call upon left child                                //calling this function that takes the 2d array as parameter
    cout << root[0][1] << endl; //call up the root
    inorder(root[0][3]);        //call upon right child
  }
	void preorder(){
        int current = 0;
        if(root[0][0] == -1) {
        return;
        }
        cout << root[0][1] << endl;
        preorder(root[0][2]);
        preorder(root[0][3]);
	}
	void postorder() {
        int current = 0;
        if (root[0][0] == -1) {
        return;
        }
        postorder(root[0][2]);
        postorder(root[0][3]);
        cout << root[0][1] << endl;
        }

    void levelorder(){
        int current = 0;            //this will be the start point since arrays are zero indexed
        if(root[0][0] == -1 ) {     //if the root is empty then we don't have a tree
        return;
        }
        queue <int> q;              //STL queue which will store the indexes of the nodes
        q.push(current);            //push 0 'current' into the queue, that's like pushing root

        while(!q.empty()) {         //while the queue is not empty, use it to print the nodes, level by level
          int temp = q.front();     //assigns the index of the first element 'front' to temp
          cout << root[temp][1] << endl;
          q.pop();                  //pop the current front
          int right = root[temp][2];//use it's index to access the values of it's left and right child
          int left = root[temp][3];

          if (left != -1) {         //before pushing the index into the queue, check if there exist a node or not
            q.push(left);
          }
          if(right != -1) {
            q.push(right);
          }
        }
	}
private:
	int root[20][4];

  void inorder(int current) {
    if (current == -1) {
      return;
    }
    inorder(root[current][2]);
    cout << root[current][1] << endl;
    inorder(root[current][3]);
  }

  void preorder(int current) {
    if (current == -1) {
      return;
    }
    cout << root[current][1] << endl;
    preorder(root[current][2]);
    preorder(root[current][3]);
  }
  void postorder(int current) {
    if (current == -1) {
      return;
    }
    postorder(root[current][2]);
    postorder(root[current][3]);
    cout << root[current][1] << endl;
  }

};

int main() {
	Tree *tree = new Tree();
	int j, node;
	srand(time(NULL));
	for(j = 0;j < 10;j ++) {
		node = rand() % 500;
		tree->insert(node);
	}
	cout << "Inorder: ";
	tree->inorder();
	printf("\n");
	cout << "preoder: ";
	tree->preorder();
	printf("\n");
	cout << "Postoder: ";
	tree->postorder();
	printf("\n");
	cout << "Level order: ";
	tree->levelorder();
	printf("\n");
}
