#include <iostream>
#include <random>

using namespace std;

int isMatch(int s, int g) {

	if (s == g) return 0;//match
	if (s < g) return 1;//above
	if (s > g) return -1; //below
}

int randomGenerator(int l, int h) {
	random_device rd;                               //create a random device object called rd
	mt19937 mt(rd());                               //create Non-deterministic 32-bit seed called mt. Always ensures number is new
	uniform_int_distribution<int> dist(l, h);       //set the range from low to high

	return dist(mt);
}


int main()
{
	bool match = false;
	int counter = 0;
	int secret{};
	int low = 1;
	int high = 100;

	//enter secret number
	cout << "Enter a secret number: ";
	cin >> secret;

	while(!match && counter < 4) {
		++counter;

		int guess = randomGenerator(low, high);                             //call random generator function

		int response = isMatch(secret, guess);                              //check if there is a match (0 - match, 1, too high, -1, too loow)

		//respond to user
		switch (response)
		{
		case 0:
			cout << "You guessed correct. The number was " << secret << endl;
			match = true;
			break;
		case 1:
			cout << "The number is less than " << guess << endl;
			high = guess - 1;
			break;
		case -1:
			cout << "The number is higher than " << guess << endl;
			low = guess + 1;
			break;
		default:
				break;
		}

		if (counter == 4 && !match) {
			cout << "Sorry. You are out of guesses. Game over!" << endl;
			cout << "The number was " << secret << endl;
		}

	}
}

