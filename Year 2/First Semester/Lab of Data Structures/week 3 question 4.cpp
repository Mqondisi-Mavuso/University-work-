#include <iostream>
#include <string>

#define SIZE 100

using namespace std;

class Node
{
    public:
	int data;
	Node *next;
};

class Queue
{
public:
	Queue()
	{
        bot = NULL;
        top = NULL;
	}
	int enqueue(int data)
	{
	    Node *t = new Node;
	    if(t == NULL)   return -1;              //whenever the heap is full, the enqueue will be full too
	    else{
            t->data = data;
            t->next = NULL;

            if(top == NULL && bot==NULL)  bot = top = t;      //for the first node

            else{
               bot->next = t;
               bot = t;                    //the bot pointer will help when we want add a node at the end of the list
            }
	    }
	    return 1;
	}
	int *dequeue()
	{
	    int *x = new int;
	    Node* r = NULL;
	    if(top == NULL)     return NULL;      // meaning que is empty
	    else{
            r = top;
            top = top->next;
            *x = r->data;
            r->next = NULL;
            delete r;
	    }
    return x;
	}
private:
	Node *top, *bot;
};

int main()
{
	int data, *temp;
	string command;
	Queue *queue = new Queue();
	while(1)
	{
		cin>>command;
		if(command.compare("exit") == 0)
		{
			break;
		}
		else if(command.compare("enqueue") == 0)
		{
			cout<<"Please input a integer data:";
			cin>>data;
			if(queue->enqueue(data) == 1)
			{
				cout<<"Successfully enqueue data "<<data<<" into queue."<<endl;
			}
			else
			{
				cout<<"Failed to enqueue data into queue."<<endl;
			}
		}
		else if(command.compare("dequeue") == 0)
		{
			temp = queue->dequeue();
			if(temp == NULL)
			{
				cout<<"Failed to dequeue a data from queue.\n";
			}
			else
			{
				cout<<"Dequeue data "<<*temp<<" from queue."<<endl;
			}
		}
	}
}
