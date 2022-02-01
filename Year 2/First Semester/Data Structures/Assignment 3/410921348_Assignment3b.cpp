#include<iostream>
#include<cctype>
#include<stack>
using namespace std;

template <class T>
class Node {
public:

	T data;
	Node<T>* next, * prev;

	Node(T x)
	{
		data = x;
		next = NULL;
		prev = NULL;
	}

};

template<class T>
class List {
public:
	List() {
		start = end = NULL;
	}
	void insert(T d) {
		Node<T>* temp = new Node<T>(d);
		if (length() == 0)
		{
			start = end = temp;

		}
		else
		{
			temp->prev = end;
			temp->next = start;
			end->next = temp;
			end = temp;
		}
	}

	int length() {
		if (!start) return 0;
		int count = 1;
		Node<T>* iter = start;
		while (iter->next != start && iter->next != NULL)
		{
			iter = iter->next;
			count++;
		}
		return count;
	}

	void shift(char dir, int num) {
		for (int i = 0; i < num; i++) {
			if (toupper(dir) == 'L') {
				Node<T>* temp = start;
				start = start->next;
				end->next = temp;
				end = temp;
			}
			else if (toupper(dir) == 'R') {
				Node<T>* temp = end;
				end = end->prev;
				start = temp;
			}
			else {
				cout << "could not determine direction\n";
			}
		}		
	}

	bool isSymmetric() {
		bool sym = true;
		if (length() % 2 == 0) {
			stack<T> compare;
			Node<T>* it = start;
			for (int i = 0; i < length() / 2; i++) {
				compare.push(it->data);
				it = it->next;
			}
			T* compIt = &compare.top();
			for (int i = 0; i < length() / 2; i++) {
				if (*compIt != it->data) {
					sym = false;
					break;
				}
				it = it->next;
				if (i < (length() / 2) - 1)
					compare.pop();
				compIt = &compare.top();
			}
		}

		return sym;
	}
	void printList() {
		if (start) {
			Node<T>* iter = start;
			end->next = NULL;
			while (iter) {
				cout << iter->data;
				iter = iter->next;
			}
			end->next = start;
		}
		else {
			cout << "list is empty";
		}
		cout << endl;
	}

private:
	Node<T>* start;
	Node<T>* end;
};




int main() {
	int A[] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 21, 19, 17, 15, 13, 11, 9, 7, 5, 3, 1 };
	char B[] = { 'A', 'B', 'C', 'D', 'D','C', 'B', 'A'};
	//List of integers
	List<int>* l1 = new List<int>();
	for (int i = 0; i < 22; i++) {
		l1->insert(A[i]);
	}
	l1->printList();
	//check symetric
	if(l1->isSymmetric())
		cout << "is symmetric\n";
	else
		cout << "is not symmetric\n";
		
	cout << endl;
	//List of Characters
	List<char>* l2 = new List<char>();
	for (int i = 0; i < 8; i++) {
		l2->insert(B[i]);
	}
	l2->printList();
	//check symetric
	if (l2->isSymmetric())
		cout << "is symmetric\n";
	else
		cout << "is not symmetric\n";
	//shift right
	l2->shift('r', 3);
	l2->printList();
	//shift left
	l2->shift('l', 2);
	l2->printList();
	//check symetric
	if (l2->isSymmetric())
		cout << "is symmetric\n";
	else
		cout << "is not symmetric\n";
	//shift right
	l2->shift('r', 3);
	l2->printList();
	//check symetric
	if (l2->isSymmetric())
		cout << "is symmetric\n";
	else
		cout << "is not symmetric\n";

	return 0;
}