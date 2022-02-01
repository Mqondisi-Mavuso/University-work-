#include<iostream>
#include<cctype>
using namespace std;

#define SIZE 20

template <class T>
class Node;

template <class T>
class Queue;

template <class T>
class Node {
public:

	T data;
	Node<T>* next;
	Node<T>* before;

	Node(T x)
	{
		data = x;
		next = NULL;
		before = NULL;
	}

};

template <class T>
class Queue {
public:

	Queue()
	{
		start = end = NULL;
	}

	int countNodes()
	{
		int c = 0;
		Node<T>* iterator = start;
		while (iterator) {
			c++;
			iterator = iterator->next;
		}
		return c;
	}

	bool isEmpty() {
		return (countNodes() == 0) ? true : false;
	}

	bool isFull() {
		return (countNodes() == SIZE) ? true : false;
	}

	void addFront(T d) {
		Node<T>* temp = new Node<T>(d);
		if (isFull()) {
			cout << "Queue is full. Could not add node\n";
		}
		else {
			if (isEmpty()) {
				start = end = temp;
			}
			else {
				start->before = temp;
				temp->next = start;
				start = temp;
			}
		}		
	}

	void addRear(T d) {
		Node<T>* temp = new Node<T>(d);
		if (isFull()) {
			cout << "Queue is full. Could not add node\n";
		}
		else {
			if (isEmpty()) {
				start = end = temp;
			}
			else {
				temp->before = end;
				end->next = temp;
				end = temp;
			}
		}
	}

	void addMiddle(T d) {
		Node<T>* temp = new Node<T>(d);
		int mid = countNodes() / 2;
		Node<T>* iterPoint = start;
		if (countNodes() % 2 == 0)
			mid--;
		for (int i = 0; i <= mid; i++) {
			iterPoint = iterPoint->next;
		}
		if (isFull()) {
			cout << "Queue is full. Could not add node\n";
		}
		else {
			if (isEmpty()) {
				start = end = temp;
			}
			else {
					temp->before = iterPoint->before;
					temp->next = iterPoint;
					temp->before->next = temp;
					iterPoint->before = temp;							
			}
		}
	}

	void DeleteLastTwo(int code, Node<T>* t) {
		if (code == 1) {
			start = end;
			t->next = NULL;
			delete t;
		}
		else {
			end = start;
			start->next = NULL;
			delete t;
		}
	}

	void deleteFront() {
		if (!isEmpty()) {
			Node<T>* temp = start;
			if (countNodes() > 1) {
				start = start->next;
				temp->next = NULL;
				delete temp;
			}
			else if (countNodes() == 2) {
				temp = start;
				DeleteLastTwo(1, temp);
			}
			else {
				temp = start;
				start = end = NULL;
				delete temp;
			}
		}
		else {
			cout << "Could not delete node. Queue is empty.";
		}
		
	}

	void deleteMiddle() {
		if (!isEmpty()) {
			Node<T>* temp = NULL;
			if (countNodes() > 2) {
				Node<T>* iterPoint = start;
				int mid = (countNodes() % 2 == 0) ? countNodes() / 2 + 1 : countNodes() / 2;
				for (int i = 0; i < mid; i++) {
					iterPoint = iterPoint->next;
				}
				temp = iterPoint;
				temp->before->next = temp->next;				
				if(temp->next)
					temp->next->before = temp->before;
				delete temp;
			}
			else if (countNodes() == 2) {
				temp = end;
				DeleteLastTwo(2, temp);
			}
			else {
				temp = start;
				start = end = NULL;
				delete temp;
			}
		}
		else {
			cout << "Could not delete node. Queue is empty.";
		}
	}

	void deleteRear() {
		if (!isEmpty()) {
			Node<T>* temp = end;
			if (countNodes() > 1) {
				end = end->before;
				end->next = NULL;
				delete temp;
			}
			else if (countNodes() == 2) {
				temp = end;
				DeleteLastTwo(2, temp);
			}
			else {
				temp = start;
				start = end = NULL;
				delete temp;
			}
		}
		else {
			cout << "Could not delete node. Queue is empty.";
		}
	}

	void printQueue() {
		Node<T>* iter = start;
		while (iter) {
			cout << iter->data;
			iter = iter->next;
		}
		cout << endl;
	}

	~Queue() { 
		delete start; 
		delete end;
	}
private:
	Node<T>* start;
	Node<T>* end;
};



int main() {
	Queue<int>* q = new Queue<int>();
	q->addFront(1);
	q->printQueue();
	q->addFront(0);
	q->printQueue();
	q->addRear(3);
	q->printQueue();
	q->addMiddle(2);//test middle for odd
	q->printQueue();
	q->addMiddle(5);//test Middle for even
	q->printQueue();
	q->deleteFront();
	q->printQueue();
	q->deleteRear();
	q->printQueue();
	q->deleteMiddle();
	q->printQueue();
	q->deleteMiddle();
	q->printQueue();
	q->deleteFront();
	q->printQueue();
	q->deleteMiddle();
	q->printQueue();
	return 0;
}