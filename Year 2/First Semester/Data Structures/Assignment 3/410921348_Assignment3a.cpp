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

	T atNth(int pos) {
		
		T val{};
		Node<T>* p = start;
		if (length() && pos <= length()) {
			int count = 1;
			while (count < pos) {
				p = p->next;
				count++;
			}
			return p->data;
		}
		return NULL;
	}

	int occurances(T d) {
		int occ = 0;
		Node<T>* p = start;
		int count = 1;
		while (p && count <= length()) {
			if (p->data == d) {
				occ++;
			}
			p = p->next;
			count++;
		}
		return occ;
	}

	void deleteAll(int number, T d) {
		if (occurances(d) >= number) {
			int count = 0;
			Node<T>* p = start;
			while (count < number) {
				Node<T>* toDelete = NULL;
				Node<T>* previous = p->prev;
				if (p->data == d) {	
					toDelete = p;
					if (p == start) {
						start = start->next;
						end->next = start;
					}						
					else if (p == end) {
						end = previous;
						end->next = start;
					}
					else {
						previous->next = p->next;
					}	
					count++;
				}
				p = p->next;
				if (toDelete) {
					toDelete->next = NULL;
					delete toDelete;
				}				
			}
		}
	}

	void printList() {
		if (start) {
			Node<T>* iter = start;
			end->next = NULL;
			while (iter) {
				cout << iter->data<<" ";
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

	//populating list
	int A[] = { 15, 1, 3, 5, 7, 9, 11, 13, 19, 17, 19, 21, 2, 4, 6, 18, 11, 9, 15, 5, 3, 15};
	List<int>* l1 = new List<int>();
	char B[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'A', 'B', 'A' };
	for (int i = 0; i < 22; i++) {
		l1->insert(A[i]);
	}
	l1->printList();

	//Test for atNth()
	int position = 5;
	int atPos = l1->atNth(position);
	if (atPos) {
		cout << "The element at position " << position << " is " << atPos << endl;
	}
	else {
		cout << "Element was not found." << endl;
	}
	position = 500;
	atPos = l1->atNth(position);
	if (atPos) {
		cout << "The element at position " << position << " is " << atPos << endl;
	}
	else {
		cout << "Element was not found." << endl;
	}

	//Test deletAll with value in the begining, middle and at the end
	l1->deleteAll(3, 15);
	l1->printList();
	//****************************Character List*************************
	cout << endl;
	List<char > *l2 = new List<char>();
	for (int i = 0; i < 13; i++) {
		l2->insert(B[i]);
	}
	l2->printList();

	//Test for atNth()
	position = 5;
	char atPos2 = l2->atNth(position);
	if (atPos2) {
		cout << "The element at position " << position << " is " << atPos2 << endl;
	}
	else {
		cout << "Element was not found." << endl;
	}
	position = 500;
	atPos2 = l2->atNth(position);
	if (atPos2) {
		cout << "The element at position " << position << " is " << atPos2 << endl;
	}
	else {
		cout << "Element was not found." << endl;
	}

	//Test deletAll with value in the begining, middle and at the end
	l2->deleteAll(3, 'A');
	l2->printList();

	return 0;
}