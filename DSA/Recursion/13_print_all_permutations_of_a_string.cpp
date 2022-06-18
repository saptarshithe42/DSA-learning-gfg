#include<iostream>
using namespace std;

void print_permutations(string s, int i = 0)
{
    if(i == s.length() - 1)
    {
        cout << s << " ";
        return;
    }

    for(int j = i; j < s.length(); j++)
    {
        swap(s[i], s[j]);
        print_permutations(s, i+1);
        swap(s[i], s[j]);
    }
    
}


int main()
{
    string s = "ABC";

    print_permutations(s, 0);

    
    return 0;
}