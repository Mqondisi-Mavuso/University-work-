#include <iostream>
#include <stack>

using namespace std;

bool checkBalance(string str);

int main(){
    string chars{};
    while(cin >> chars){
        if(checkBalance(chars)) cout << "The parenthesis are Balanced and properly Nested\n";
        else cout << "The parenthesis are not balanced or properly Nested, try again\n";
    }

 return 0;
}

bool checkBalance(string expr)
{
	stack<char> s;
	char x;

	for (auto i: expr) {
		if (i == '(' || i == '[' || i == '{') {
			s.push(i);
			continue;
		}

		if (s.empty()) return false;

		switch (i) {
		case ')':
			x = s.top();
			s.pop();
			if (x == '{' || x == '[') return false;
			break;

		case '}':
			x = s.top();
			s.pop();
			if (x == '(' || x == '[') return false;
			break;

		case ']':
			x = s.top();
			s.pop();
			if (x == '(' || x == '{')
				return false;
			break;
		}
	}
	return (s.empty());
}
