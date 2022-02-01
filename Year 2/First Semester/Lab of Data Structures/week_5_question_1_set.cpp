#include<iostream>
#include<cstdlib>

using namespace std;

struct Node
{
	Node()
	{
		data = 0;
		next = NULL;
	}
	int data;
	Node *next;
};

class Set
{
public:
	Set()
	{
	    this->rear = NULL;
	    this->element = NULL;
	}

	int addElement(int e){
	    Node *r = new Node();
	    Node *find = element;

	        while(find){                            //this is for traversing through the list
                if(find->data == e) return -1;
                find = find->next;
	        }
            r->data = e;
            r->next = NULL;
            if(element == NULL) element = rear = r;
            else{
                rear->next = r;
                rear = r;
            }
        return 1;
	}

    Set *unions(const Set *b) {
      Set *set = new Set();
      Node *subset1 = getElement();                             //this assigns first node pointer to subset1, which will give us access to all the other nodes
      Node *subset2 = b -> getElement();
      while(subset1) {                                          //adds all the elements form subset1 to the new set
        set -> addElement(subset1 -> data);
        subset1 = subset1 -> next;
      }
      while(subset2) {                                         //adds all the elements of subset 2 to the set using addElement which avoids duplicates
            set -> addElement(subset2 -> data);
            subset2 = subset2 -> next;
          }
        return set;
       }

    Set *intersections(const Set *b) {
      Set *set = new Set();
      Node *subset1 = getElement();
      while(subset1) {
        Node *subset2 = b -> getElement();
        while(subset2){                                     //this will check an element of subset1 against all the subset2 elements
          if((subset1 -> data) == (subset2 -> data)){
            set -> addElement(subset1 -> data);
          }
          subset2 = subset2 -> next;
        }
        subset1 = subset1 -> next;
      }
      return set;
    }

    bool equivalent(const Set *b) {
      Node *subset1 = getElement();
      Node *subset2 = b -> getElement();

      while(subset1){                             //check each element of ss1 against ss2
        if(!found(subset1 -> data, subset2)) return false;
        subset1 = subset1 -> next;
      }
        subset1 = element;                         //reinitialize subset1
      while(subset2){                             //check each element of ss2 against ss1
        if(!found(subset2 -> data, subset1)) return false;
        subset2 = subset2 -> next;
      }
      return true;
    }

    bool found(int x, Node *node) {                         //this checks if x if found in the set
      while(node){
        if(x == node -> data) return true;
        node = node -> next;
      }
      return false;
    }

	void listAll() const
	{
		Node *cur = element;
		while(cur != NULL)
		{
			cout<<cur->data<<" ";
			cur = cur->next;
		}
	}

    Node *getElement() const {              //this returns a pointer to the first element
      return element;
    }
private:
	Node *element, *rear ;
};

int main()
{
	Set *a = new Set();
	Set *b = new Set();
	Set *c;
	Node *cur;

	a->addElement(1);
	a->addElement(2);
	a->addElement(3);
    a->addElement(3);
	b->addElement(1);
	b->addElement(4);
	b->addElement(3);
	//b->addElement(5);

	cout << "Unions; ";
	c = a->unions(b);
	c->listAll();
    cout << endl;

	c = a->intersections(b);
	cout << "intersections; ";
	c->listAll();
	cout << endl << "original set"<<endl;
	a->listAll();
	cout << endl;
	b->listAll();

	cout << endl;
	if(a->equivalent(b) == 1)
		cout<<"Equivalent.\n";
	else
		cout<<"Not Equivalent!\n";
}
