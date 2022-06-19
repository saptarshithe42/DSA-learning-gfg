#include<iostream>
using namespace std;

bool check_palindrome(string s)
{
    int low = 0, high = s.length() - 1;

    while(low <= high)
    {
        if(s[low] != s[high])
            return false;

        low++;
        high--;
    }
    return true;
}


int main()
{
    string s = "ABCDCBA";

    cout << std::boolalpha;
    cout << check_palindrome(s) << "\n";

    
    
    return 0;
}