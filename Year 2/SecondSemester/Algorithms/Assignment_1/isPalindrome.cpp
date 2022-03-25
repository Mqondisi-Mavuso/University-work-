#include <iostream>
#include <vector>
using namespace std;

void isPalindrome(vector<string> words) {
	for (string word : words) {
		bool ispal = true;
		if (word.length() < 2) {
			ispal = false;
		}
		else {
			int mid = word.length() / 2;
			int opposite = word.length() - 1;
			for (int i = 0; i <= mid; i++) {
				if (word[i] != word[opposite])
					ispal = false;
				--opposite;
			}
		}
		string result = (ispal) ? "true" : "false";
		cout << word << " -> " << result << endl;
	}
}


int main() {
	vector<string> words = {};
	int number_of_words = 0;
	cout << "Welcome, please type in the words you want to check if they are palindrome or not" << endl;
	cout << "How many words do you wanna check? ";
	cin >> number_of_words;

	for (int i = 0; i < number_of_words; i++) { //for inserting the numbers into the vector
		string word = "";
		cin >> word;
		words.push_back(word);
	}
	isPalindrome(words);

	return 0;
}