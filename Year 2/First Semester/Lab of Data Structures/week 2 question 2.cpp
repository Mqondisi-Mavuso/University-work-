#include <iostream>
#include <cstring>

#define SIZE 100

using namespace std;

class Stack
{
public:
    Stack(int SIZE)			//default constructor
    {
      this->SIZE = SIZE;
      top = -1;
      S = getArray(); 	//allocating array on the heap
    }
    int push(int x) {
    if (isFull()){
       return -1;
    } else {
        top++;
        S[top] = x;
      return 1;
    }
}

    int *pop(){
    int *num = NULL;
    if (isEmpty()){
        return NULL;
    } else {
        num = &S[top];
        top--;
    }
    return num;
}

  	int * getArray(){
    	return this->data;
    }
  int isFull() {
    if (top == size-1){
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
  	int top = -1;
  	int * S = NULL;
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
