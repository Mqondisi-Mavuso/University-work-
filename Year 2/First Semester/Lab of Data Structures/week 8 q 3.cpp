#include<iostream>
#include<cstdlib>
#include<ctime>
#include <queue>

using namespace std;

class Tree
{
public:
	Tree()
	{
		int j;
		for(j = 0;j < 2000;j ++)
			root[j] = -1;
	}
	int insert(int node)
	{
		int index = 0;
		while(index < 2000 && root[index] != -1)
		{
			if(root[index] < node)
				index = index * 2 + 2;      //right child
			else
				index = index * 2 + 1;
		}
		root[index] = node;
		return root[index];
	}

    void inorder(int current) {
        if(root[current] == -1) {
          return;
        }
        inorder(current * 2 + 2);
        cout << root[current] << " ";
        inorder(current * 2 + 1);
    }

    void preorder(int current) {            //pass int index of the node "current"
        if(root[current] == -1) {
          return;
        }
        cout << root[current] << " ";
        preorder(current * 2 + 2);              //call the function upon leftchild of the node
        preorder(current * 2 + 1);              //call it upon right child
  }

    void postorder(int current) {
        if(root[current] == -1) {
          return;
        }
        postorder(current * 2 + 2);
        postorder(current * 2 + 1);
        cout << root[current] << " ";
  }
    void levelorder(int current) {
        if(root[current] == -1) {
          return;
        }
        queue <int> q;                       //use an STL queue to store the values


        q.push(current);                    //this is to enque the index of the elements into the STL queue

        while (q.empty() == false) {

          int temp = q.front();            // store the front element "index" of the queue into a new integer
          cout << root[temp] << " ";
          q.pop();                          //remove the top element to make way for printing the next one
          int left = temp * 2 + 2;          //general formular to calculate the left child of a node
          int right = temp * 2 + 1;         // location of the right child of a node in the array

          if(root[left] != -1) {
            q.push(left);
          }
          if(root[right] != -1) {
            q.push(right);
          }
        }
    }
private:
	int root[2000];
};

int main()
{
	Tree *tree = new Tree();
	int j, node;
	srand(time(NULL));
	for(j = 0;j < 10;j ++)
	{
		node = rand() % 1000;
		tree->insert(node);
	}
	int current = 0;
	cout << "Inorder: ";
	tree->inorder(current);
	printf("\n\n");
	cout << "Preoder: ";
	tree->preorder(current);
	printf("\n\n");
	cout << "Postorder: ";
	tree->postorder(current);
	printf("\n\n");
	cout << "Level order: ";
	tree->levelorder(current);
	printf("\n");
}
