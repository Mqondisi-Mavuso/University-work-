#include <iostream>
#include <cstring>

#define SIZE 100

using namespace std;

class Stack
{
public:
    Stack()			//default constructor
    {
      top = -1;
    }
    int push(int data) {
    if (isFull()){
       return -1;
    } else {
        top++;						//making top to be positive so it can be used as the index of the array
        this->data[top] = data;		//assigning the num passed to the data array
      return 1;
    }
}

    int *pop(){
    int *num = NULL;
    if (isEmpty()){
        return NULL;
    } else {
        num = &data[top];			//assign the address of the top element to the num pointer
        top--;						// make top the previous element in the array
    }
    return num;
}

  int isFull() {					//check whether the stack is full or not
    if (top == SIZE-1){
        return 1;
    }
    return 0;
}

int isEmpty() {
    if (top == -1){
        return 1;
    }
    return 0;
}
private:
    int data[SIZE];
  	int top;
};

int main()
{
    int data, *temp;
    char command[50];
    Stack *stack = new Stack();
    while(1)
    {
        cin>>command;
        if(strcmp(command, "exit") == 0)
        {
            break;
        }
        else if(strcmp(command, "push") == 0)
        {
            cout<<"Please input a integer data:";
            cin>>data;
            if(stack->push(data) == 1)
            {
                cout<<"Successfully push data "<<data<<" into stack.\n";
            }
            else
            {
                cout<<"Failed to push data into stack.\n";
            }
        }
        else if(strcmp(command, "pop") == 0)
        {
            temp = stack->pop();
            if(temp == NULL)
            {
                cout<<"Failed to pop a data from stack.\n";
            }
            else
            {
                cout<<"Pop data "<<*temp<<" from stack.\n"<<endl;
            }
        }
    }
}
