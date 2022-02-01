#include <iostream>
#include <cstring>
#include <math.h>

#define SIZE 5

using namespace std;

class Queue
{
public:
    Queue()
    {
     front = -1, rear = -1, counter = 0;			            //use front to keep track
    }
    int enqueue(int d)
    {
        if(counter == SIZE) return -1;                  //meaning the queue is full
        else{
            rear = (rear + 1) % SIZE;
            data[rear] = d;
            counter++;
        }
        return 1;
    }
    int *dequeue()
    {
        int *p = NULL;
        if(counter == 0) return NULL;                    //meaning the queue is empty
        else{
            front = (front + 1) % SIZE;                 //this ensures that the index pointer goes back to zero after reaching the end of array
            p = &data[front];
            counter--;
        }
        return p;
    }
private:
    int data[SIZE];
    int front, rear, counter;
};

int main()
{
    int data, *temp;
    char command[50];
    Queue *queue = new Queue();
    while(1)
    {
        cin>>command;
        if(strcmp(command, "exit") == 0)
        {
            break;
        }
        else if(strcmp(command, "enqueue") == 0)
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
        else if(strcmp(command, "dequeue") == 0)
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
