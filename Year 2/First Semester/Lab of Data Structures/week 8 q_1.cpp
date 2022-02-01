#include<iostream>
#include<cstdlib>
#include<ctime>
#include <queue>

using namespace std;

class Node
{
public:
	int level, data;
	Node *left, *right;
};

class Tree
{
public:
	Tree()
	{
		root = NULL;
	}
	int insert(Node *n)
	{
		insert(&root, n);
	}
	void inorder(){
        Node *p = root;
        inorder(p);
	}
	void inorder(Node *p)
	{
      if(p){
        inorder(p->left);
        cout << p->data << " ";
        inorder(p->right);
      }
	}
	void preorder(){            //to avoid changing the main function, this function just calls the other function that accepts a parameter
        Node *p = root;
        preorder(p);
	}
	void preorder(Node *p)
	{
      if(p){
      	cout << p->data << " ";     //uses recursion to traverse through the binary tree
        preorder(p->left);
        preorder(p->right);
      }
	}

	void postorder(){
        Node *p = root;
        postorder(p);
	}

	void postorder(Node *p){
      if(p){
        postorder(p->left);
        postorder(p->right);
        cout << p->data << " ";
      }
	}
	Node *getRoot(){
        return root;
	}

	void levelorder()
	{
      queue <Node *> myQueue;		//declare the STL Node queue,it will store the addresses of our nodes
        Node *t = root;
        myQueue.push(t);						//push the address of t into the queue
        cout << t->data << " ";

        while(!myQueue.empty()){
            t = myQueue.front();
            myQueue.pop();                          //pop out the address from the queue
            if(t->left){
                cout <<t->left->data << " ";
                myQueue.push(t->left);              //insert the address of t's left to queue
            }
            if(t->right){
                cout << t->right->data << " ";
                myQueue.push(t->right);
            }
        }
	}
private:
	Node *root;
	void insert(struct Node **r, struct Node *n)
	{
		if(*r == NULL)
			*r = n;
		else if(n->data > (*r)->data)
			insert(&((*r)->right), n);
		else
			insert(&((*r)->left), n);
	}
};

int main()
{
	Tree *tree = new Tree();
	Node *node;
	int j;
	srand(time(NULL));
	for(j = 0;j < 10;j ++)
	{
		node = new Node();
		node->data = rand()%100;        //just made it generate randon numbers between 1 and 100
		node->left = NULL;
		node->right = NULL;
		tree->insert(node);
	}
	cout << "Inorder: ";
	tree->inorder();
	printf("\n\n");
	cout << "Preorder: ";
	tree->preorder();
	printf("\n\n");
	cout << "Postorder: ";
	tree->postorder();
	printf("\n\n");
	cout << "Level order: ";
	tree->levelorder();
	printf("\n");
}
