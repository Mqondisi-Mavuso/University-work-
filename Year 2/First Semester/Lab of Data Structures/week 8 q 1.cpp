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
	void inorder(Node *root)
	{
      if(root){
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
      }
	}
	void preorder(Node *root)
	{
      if(root){
      	cout << root->data<< " ";
        preorder(root->left);
        preorder(root->right);
      }
	}
	void postorder(Node *root){
      if(root){
        postorder(root->left);
        postorder(root->right);
        cout << root->data<< " ";
      }
	}
	void levelorder()
	{
      queue <Node *> myQueue;					//declare the STL Node queue
        Node *t = root;
        myQueue.push(t);						//push the address of t into the queue
        cout << t->data<<", ";

        while(!myQueue.empty()){
            t = myQueue.front();
            myQueue.pop();
            if(t->left != NULL){
                cout <<t->left->data<<", ";
                myQueue.push(t->left);
            }
            if(t->right != NULL){
                cout << t->right->data<<", ";
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
		node->data = rand();
		node->left = NULL;
		node->right = NULL;
		tree->insert(node);
	}
	tree->inorder(node);
	printf("\n");
	tree->preorder(node);
	printf("\n");
	tree->postorder(node);
	printf("\n");
	tree->levelorder();
	printf("\n");
}
