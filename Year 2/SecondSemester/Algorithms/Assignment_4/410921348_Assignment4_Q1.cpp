//  The test cases we were asked to provide are provided as inputs in the main function
//

/*
* hello + low + owl = hellowl, length = 7
hello + owl + low = hellowlow, length = 9
low + hello + owl = lowhellowl, length = 10
low + owl + hello = lowolhello, length = 10
owl + hello + low = owlhellolow, length = 11
owl + low + hello = owlowhello, length = 10
Thus, the answer of this case is "hellowl" with length = 7.
Please find a way to solve the problem using strategy DP or Greedy.

*/


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

string compareWordSets(string s1, string s2) {
    string construct{};
    static string newWord{};

    //this helps to allow comparison between lower and uppercase strings
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    if (s1.find(s2) != std::string::npos)// check if S[i] is a subset of T
        return s1;
    // check if T is a subset of S[i]
    else if (s2.find(s1) != std::string::npos)
        return s2;
    else {
        int count = 0;
        char* front = &s2.front();
        char* back = &s2.back();
        char* front1 = &s1.front();
        char* back1 = &s1.back();

        //move to the point where the longest positive join is possible
        while (front[0] != back1[0] && front1 != back1 && count < s2.size()) {
            back1--;
            count++;
        }
        //s1 was less than s2
        if (count == s1.size() - 1)
        {
            newWord += s2;
            construct = compareWordSets(s2, s1);
        }
        else {
            for (auto it = s2.begin() + count + 1; it != s2.end(); it++) {
                construct += *it;
            }
            //if pattern is not repeating or construct is just a single letter
            if (!(s1.find(construct) != std::string::npos) || construct.length() == 1)
                newWord = s1 + construct;
            else
                newWord = s1;
        }
    }

    return newWord;
}

string minT(vector<string> words) {
    if (words.size() == 1) return words.at(0); //if only one word
    string s = words.at(0); //get first word and form T
    transform(s.begin(), s.end(), s.begin(), ::tolower);//transform to small caps
    words.erase(words.begin());// remove it form S

    //for each string in S
    for (string word : words)
    {
        s = compareWordSets(s, word); //pass T and S[i]
    }
    return s;
}


int main()
{
    vector<string> s1 = { "hello", "low", "owl" };
    vector<string> s2 = { "hello", "owl", "low" };
    vector<string> s3 = { "low", "hello", "owl" };
    vector<string> s4 = { "low", "owl", "hello" };
    vector<string> s5 = { "owl", "hello", "low" };
    vector<string> s6 = { "owl", "low", "hello" };


    cout << endl << "Answer: " << minT(s1) << endl;
    cout << endl << "Answer: " << minT(s2) << endl;
    cout << endl << "Answer: " << minT(s3) << endl;
    cout << endl << "Answer: " << minT(s4) << endl;
    cout << endl << "Answer: " << minT(s5) << endl;
    cout << endl << "Answer: " << minT(s6) << endl;
}

