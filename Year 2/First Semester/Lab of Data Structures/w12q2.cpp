#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <queue>
#include <vector>
#include <map>

using namespace std;

template<class T>
class Node
{
public:
    Node()
    {
        data = new T;
    }
    Node(T d)
    {
        data = new T;
        (*data) = d;
    }
    Node &operator=(T d)
    {
        (*data) = d;
        return *this;
    }
    friend ostream &operator<<(ostream &out, Node n)
    {
        out << *(n.data);
        return out;
    }
    friend ostream &operator<<(ostream &out, Node *n)
    {
        out << *(n->data);
        return out;
    }
    void setData(T d)
    {
        *data = d;
    }
    T &getData() const
    {
        return *data;
    }
protected:
    T *data;
};

template<class T>
class ListNode : public Node<T>
{
public:
    ListNode() : Node<T>()
    {
        prev = NULL;
        next = NULL;
    }
    ListNode(T d) : Node<T>(d)
    {
        prev = NULL;
        next = NULL;
    }
    ListNode(ListNode *p, ListNode *n) : Node<T>()
    {
        prev = p;
        next = n;
    }
    ListNode(T d, ListNode *p, ListNode *n) : Node<T>(d)
    {
        prev = p;
        next = n;
    }
    ListNode *getNext() const
    {
        return next;
    }
    ListNode *getPrev() const
    {
        return prev;
    }
    void setNext(ListNode *n)
    {
        next = n;
    }
    void setPrev(ListNode *p)
    {
        prev = p;
    }
    ListNode &operator=(T d)
    {
        this -> setData(d);
        return *this;
    }
private:
    ListNode *prev, *next;
};

template<class T>
class LinkList
{
public:
    LinkList()
    {
        head = NULL;
        tail = NULL;
    }
    void addFromHead(T d)
    {
        ListNode<T> *node = new ListNode<T>(d);
        if (head != NULL)
        {
            head -> setPrev(node);
        }
        node -> setNext(head);
        head = node;
        if (tail == NULL) tail = node;
    }
    void addFromTail(T d)
    {
        ListNode<T> *node = new ListNode<T>(d);
        if (tail != NULL)
        {
            tail -> setNext(node);
        }
        node -> setPrev(tail);
        tail = node;
        if (head == NULL) head = node;
    }
    void addAfter(ListNode<T> *at, T d)
    {
        if (!exist(at)) return;
        ListNode<T> *node = new ListNode<T>(d);
        if (at->getNext() != NULL) at -> getNext() -> setPrev(node);
        node -> setNext(at->getNext());
        at -> setNext(node);
        node -> setPrev(at);
        if (node -> getNext() == NULL) tail = node;
    }
    ListNode<T> *removeFromHead()
    {
        ListNode<T> *n = head;
        if (head != NULL)
        {
            head = head -> getNext();
            if (head != NULL)
            {
                head->setPrev(NULL);
            }
            else
            {
                tail = NULL;
            }
            n -> setNext(NULL);
        }
        return n;
    }
    ListNode<T> *removeFromTail()
    {
        ListNode<T> *n = tail;
        if (tail != NULL)
        {
            tail = tail -> getPrev();
            if (tail != NULL)
            {
                tail->setNext(NULL);
            }
            else
            {
                head = NULL;
            }
            n -> setPrev(NULL);
        }
        return n;
    }
    ListNode<T> *remove(ListNode<T> *n)
    {
        if (!exist(n)) return NULL;
        if (n == head) return removeFromHead();
        if (n == tail) return removeFromTail();
        n -> getPrev() -> setNext(n -> getNext());
        n -> getNext() -> setPrev(n -> getPrev());
        n -> setNext(NULL);
        n -> setPrev(NULL);
        return n;
    }
    ListNode<T> *exist(T d)
    {
        ListNode<T> *j = head;
        while (j != NULL)
        {
            if (j -> getData() == d) return j;
            j = j -> getNext();
        }
        return NULL;
    }
    bool exist(ListNode<T> *n)
    {
        ListNode<T> *j = head;
        while (j != NULL)
        {
            if (j == n) return true;
            j = j->getNext();
        }
        return false;
    }
    ListNode<T> &operator[](int i)
    {
        ListNode<T> *j = head;
        for (int k = 0; k < i && j != NULL; k++)
        {
            j = j -> getNext();
        }
        if (j == NULL) throw std::invalid_argument("index does not exist.");
        return *j;
    }
    void print() const
    {
        ListNode<T> *j;
        j = head;
        while (j != NULL)
        {
            cout << (*j) << " ";
            j = j -> getNext();
        }
        cout << endl;
    }
protected:
    ListNode<T> *head, *tail;
};

/*
    Please finish the TreeNode class, TreeNode class represent a node in a general tree.
    A general tree is different from binary tree, every node in binary tree have at most two child node, but a node in general tree may have more than two child node.
*/
template<class T>
class TreeNode : public Node<T>
{
public:
    TreeNode() : Node<T>()
    {
        child = new LinkList<TreeNode<T> *>();
    }
    TreeNode(T d) : Node<T>(d)
    {
        child = new LinkList<TreeNode<T> *>();
    }
    /*
        Add a child to this node.
    */
    void addChild(TreeNode *n)
    {
        child->addFromTail(n);
    }
    /*
        Add a child to this node.
    */
    void addChild(T d)
    {
        child->addFromTail(new TreeNode<T>(d));
    }
    /*
        Return the nth child of the node.
    */
    TreeNode<T> *operator[](int n)
    {
        //return child->operator[](n).getData();
        return (*child)[n].getData();
    }
private:
    LinkList<TreeNode<T> *> *child;
};

/*
    Please finish the Tree class. Tree class respresent a general tree, that means node on this tree may have more than two child node.

*/
template<class T>
class Tree
{
public:
    Tree()
    {
        root = NULL;
    }
    /*
        return the nth node on this tree with level order.
    */
    TreeNode<T> *operator[](int n)
    {
        if (root == NULL) return NULL;
        queue<TreeNode<T>*> q;
        q.push(root);
        TreeNode<T> *cur = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            int j = 0;
            while (1)
            {
                try
                {
                    TreeNode<T> *t = (*cur)[j];
                    q.push(t);
                }
                catch(invalid_argument e)
                {
                    break;
                }
                j++;
            }
            cur = q.front();
            q.pop();
        }
        return cur;
    }
    /*
        return the number of nodes on this tree.
    */
    int count()
    {
        if (root == NULL) return 0;
        queue<TreeNode<T>*> q;
        q.push(root);
        int cnt = 0;
        while (!q.empty())
        {
            int size = q.size();
            cnt += size;
            for (int i = 0; i < size; i++)
            {
                TreeNode<T> *cur = q.front();
                q.pop();
                int j = 0;
                while (1)
                {
                    try
                    {
                        TreeNode<T> *t = (*cur)[j];
                        q.push(t);
                    }
                    catch(invalid_argument e)
                    {
                        break;
                    }
                    j++;
                }
            }
        }
        return cnt;
    }
    /*
        print all the node on this tree with level order.
    */
    void levelOrder()
    {
        if (root == NULL) return;
        cout << "LevelOrder: ";
        queue<TreeNode<T>*> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode<T> *cur = q.front();
                q.pop();
                cout << cur << " ";
                int j = 0;
                while (1)
                {
                    try
                    {
                        TreeNode<T> *t = (*cur)[j];
                        q.push(t);
                    }
                    catch(invalid_argument e)
                    {
                        break;
                    }
                    j++;
                }
            }
        }
        cout << endl;
    }
    /*
        print all the node on this tree with preorder.
    */
    void preorder()
    {
        _preorder(root);
    }
    /*
        print all the node on this tree with postorder.
    */
    void postorder()
    {
        _postorder(root);
    }
    /*
        set the root of this tree.
    */
    void setRoot(T d)
    {
        root = new TreeNode<T>(d);
    }
    TreeNode<T> *getRoot()
    {
        return root;
    }
private:
    TreeNode<T> *root;
    void _preorder(TreeNode<T> *r)
    {
        if (r == NULL) return;
        cout << r << " ";
        int j = 0;
        while (1)
        {
            try
            {
                _preorder((*r)[j]);
            }
            catch(invalid_argument e)
            {
                break;
            }
            j++;
        }
    }
    void _postorder(TreeNode<T> *r)
    {
        if (r == NULL) return;
        int j = 0;
        while (1)
        {
            try
            {
                _postorder((*r)[j]);
            }
            catch(invalid_argument e)
            {
                break;
            }
            j++;
        }
        cout << r << " ";
    }
};

template<class T>
class BinaryTreeNode : public Node<T>
{
public:
    BinaryTreeNode() : Node<T>()
    {
        left = NULL;
        right = NULL;
    }
    BinaryTreeNode(T d) : Node<T>(d)
    {
        left = NULL;
        right = NULL;
    }
    BinaryTreeNode(BinaryTreeNode<T> *l, BinaryTreeNode<T> *r) : Node<T>()
    {
        left = l;
        right = r;
    }
    BinaryTreeNode(T d, BinaryTreeNode<T> *l, BinaryTreeNode<T> *r) : Node<T>(d)
    {
        left = l;
        right = r;
    }
    void setLeft(BinaryTreeNode<T> *l)
    {
        left = l;
    }
    void setRight(BinaryTreeNode<T> *r)
    {
        right = r;
    }
    BinaryTreeNode<T> *&getLeft()
    {
        return left;
    }
    BinaryTreeNode<T> *&getRight()
    {
        return right;
    }
    bool operator>(BinaryTreeNode<T> n)
    {
        if (*(this -> data) > *(n.data)) return true;
        return false;
    }
    bool operator==(BinaryTreeNode<T> n)
    {
        if(*(this -> data) == *(n.data)) return true;
        return false;
    }
private:
    BinaryTreeNode<T> *left, *right;
};

template<class T>
class BinaryTree
{
public:
    BinaryTree()
    {
        root = NULL;
        count = 0;
    }
    /*
        Convert a general tree to sibling tree
    */
    static BinaryTree<T> *convertFromGeneralTree(Tree<T> *tree)
    {
        BinaryTree<T> *bt = new BinaryTree<T>();
        int size = tree -> count();
        vector<vector<int>> child(size);
        bt -> findChild(tree, child);
        // for (int i = 0; i < child.size(); i++) {
        //     for (int j = 0; j < child[i].size(); j++) {
        //         cout << "Father ID: " << i << " " << "Son ID: " << child[i][j] << endl;
        //         cout << "Father Val: " << (*tree)[i] << " " << "Son ID: " << (*(*tree)[i])[j] << endl;
        //     }
        // }
        vector<BinaryTreeNode<T>*> btNode(size, NULL);
        for (int i = 0; i < size; i++)
        {
            btNode[i] = new BinaryTreeNode<T>((*tree)[i] -> getData());
        }
        bt -> root = btNode[0];
        for (int i = 0; i < size; i++)
        {
            BinaryTreeNode<T> *t = btNode[i];
            if (child[i].size() != 0)
            {
                t -> setLeft(btNode[child[i][0]]);
                t = btNode[child[i][0]];
                for (int j = 1; j < child[i].size() && t; j++)
                {
                    t -> setRight(btNode[child[i][j]]);
                    t = btNode[child[i][j]];
                }
            }
        }
        for (int i = 0; i < size; i++)
        {
            cout << "Val: " << btNode[i];
            if (btNode[i] -> getLeft())
            {
                cout << " LeftVal: " << btNode[i] -> getLeft();
            }
            if (!btNode[i] -> getLeft())
            {
                cout << " LeftVal: " << "X";
            }
            if (btNode[i] -> getRight())
            {
                cout << " RightVal: " << btNode[i] -> getRight() << endl;
            }
            if (!btNode[i] -> getRight())
            {
                cout << " RightVal: " << "X" << endl;
            }
        }
        return bt;
    }
    void findChild(Tree<T> *tree, vector<vector<int>> &child)
    {
        map<TreeNode<T>*, int> m;
        setTreeNodeId(tree, m);
        int size = tree -> count();
        for (int i = 0; i < size; i++)
        {
            int j = 0;
            while (1)
            {
                try
                {
                    TreeNode<T> *t = (*(*tree)[i])[j];
                    child[i].push_back(m[t]);
                }
                catch(invalid_argument e)
                {
                    break;
                }
                j++;
            }
        }
    }
    void setTreeNodeId(Tree<T> *tree, map<TreeNode<T>*, int> &m)
    {
        TreeNode<T> *r = tree -> getRoot();
        if (r == NULL) return;
        queue<TreeNode<T>*> q;
        q.push(r);
        int id = 0;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode<T> *cur = q.front();
                q.pop();
                m[cur] = id++;
                int j = 0;
                while (1)
                {
                    try
                    {
                        TreeNode<T> *t = (*cur)[j];
                        q.push(t);
                    }
                    catch(invalid_argument e)
                    {
                        break;
                    }
                    j++;
                }
            }
        }
    }
    void print()
    {
        _print(root, 0);
    }
protected:
    BinaryTreeNode<T> *root;
    int count;
private:
    void _print(BinaryTreeNode<T> *r, int n)
    {
        if (r == NULL) return;
        _print(r -> getRight(), n + 1);
        for (int j = 0; j < n; j++)
        {
            cout << "   ";
        }
        cout << r << endl;
        _print(r -> getLeft(), n + 1);
    }
};

int main()
{
    Tree<int> *tree = new Tree<int>();
    srand(0);
    for (int j = 0; j < 10; j ++)
    {
        if (tree->count() == 0)
        {
            tree -> setRoot(j);
        }
        else
        {
            int k = rand() % tree->count();
            cout << k << ", " << (*tree)[k] << ", " << j << endl;
            (*tree)[k] -> addChild(j);
        }
    }
    cout << tree -> count() << endl;
    tree -> levelOrder();
    cout << "PreOrder: ";
    tree -> preorder();
    cout << endl;
    cout << "PostOrder: ";
    tree -> postorder();
    cout << endl;
    cout << "left-child right-sibling representation" << endl;
    BinaryTree<int> *binaryTree = BinaryTree<int>::convertFromGeneralTree(tree);
    binaryTree -> print();
    return 0;
}
