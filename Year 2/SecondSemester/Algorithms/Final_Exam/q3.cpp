#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

string shortest_subString(string s, string t);

int main()
{
    string s1 = "gocodeiscool", t1 = "goose", s2 = "xxxxyxyyyzyzzzz",
           t2 = "zzxxy", s3 = "abcdefg", t3 = "cdex", s4 = "yxyyyzyzzzzxxxx";

    cout<<"Input:"<<"s = "<<s1<<", "<<"t = "<<t1<<endl;
    cout <<"Output: " << shortest_subString(s1, t1) << endl<<endl;
    
    cout<<"Input:"<<"s = "<<s2<<", "<<"t = "<<t2<<endl;
    cout <<"Output: " << shortest_subString(s2, t2) << endl<<endl;
    
    cout<<"Input:"<<"s = "<<s3<<", "<<"t = "<<t3<<endl;
    cout <<"Output: " << shortest_subString(s3, t3) << endl<<endl;
    
    cout<<"Input:"<<"s = "<<s4<<", "<<"t = "<<t2<<endl;
    cout <<"Output: " << shortest_subString(s4, t2) << endl<<endl;
}


string shortest_subString(string s, string t)
{

    int m[256] = {0};

    int ans = INT_MAX; 
    int start = 0;     
    int count = 0;

    
    for (int i = 0; i < t.length(); i++)
    {
        if (m[t[i]] == 0)
            count++;
        m[t[i]]++;
    }

    
    int i = 0;
    int j = 0;

    
    while (j < s.length())
    {
    
        m[s[j]]--;
        if (m[s[j]] == 0)
            count--;

        if (count == 0)
        {
            while (count == 0)
            {
            
                if (ans > j - i + 1)
                {
                    ans = min(ans, j - i + 1);
                    start = i;
                }
                
                m[s[i]]++;
                if (m[s[i]] > 0)
                    count++;

                i++;
            }
        }
        j++;
    }

    if (ans != INT_MAX)
        return s.substr(start, ans);
    else
        return "";
}
