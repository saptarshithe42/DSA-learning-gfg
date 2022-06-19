#include<iostream>
using namespace std;


int leftmost_non_repeating_character(string& s)
{
    int fI[256];
    fill(fI, fI + 256, -1);

    for(int i = 0; i < s.length(); i++)
    {
        if(fI[s[i]] == -1)
            fI[s[i]] = i;
        else
            fI[s[i]] = -2;
    }

    int res = INT_MAX;
    for(int i = 0; i < 256; i++)
    {
        if(fI[i] >= 0)
            res = min(res, fI[i]);
    }

    return (res == INT_MAX ? -1 : res);
}


int main()
{   
    string s = "aabcd";


    cout << leftmost_non_repeating_character(s) << "\n";
    
    return 0;
}