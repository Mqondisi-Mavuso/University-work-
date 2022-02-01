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

class Stack
{
public:
    Stack()
    {
        top = NULL;                     //default constructor to let top == NULL;
    }
    int push(int d)
    {
        Node * p = new Node;
        if(p == NULL) return -1;        //this happens whenever the heap is full

        p->data = d;
        p->next = top;
        top = p;
        return 1;
    }

    int *pop()
    {
        int *x = new int();                         //allocating int on the heap and let x points to that memory
        Node *r = NULL;
        if(top == NULL) return NULL;                //stack is empty

        else{
            r = top;
            top = top->next;                       //first move top to the next node
            *x = r->data;
            delete r;
        }
      return x;
    }
private:
    Node *data, *top;
};

int main()
{
    int data, *temp;
    string command;
    Stack *stack = new Stack();
    while(1)
    {
        cin>>command;
        if(command.compare("exit") == 0)
        {
            break;
        }
        else if(command.compare("push") == 0)
        {
            cout<<"Please input a integer data:";
            cin>>data;
            if(stack->push(data) == 1)
            {
                cout<<"Successfully push data %d into stack.\n";
            }
            else
            {
                cout<<"Failed to push data into stack.\n";
            }
        }
        else if(command.compare("pop") == 0)
        {
            temp = stack->pop();
            if(temp == NULL)
            {
                cout<<"Failed to pop a data from stack.\n";
            }
            else
            {
                cout<<"Pop data %d from stack.\n"<<*temp;
            }
        }
    }
}

