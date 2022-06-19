#include<iostream>
using namespace std;

void printFreq(string s)
{
    int count[26] = {0};

    for(int i = 0; i < s.length(); i++)
    {
        count[s[i] - 'a']++;
    }

    for(int i = 0; i < 26; i++)
    {
        if(count[i] > 0)
        {
            cout << (char) ('a' + i) << " " << count[i] << "\n";
        }
    }

}


int main()
{
    string s = "geeksforgeeks";

    printFreq(s);
    
    return 0;
}