#include<iostream>
using namespace std;

// my sol
// tail recursive
// pass low = 0, high = s.length()-1 initially
// bool check_palindrome(string& s, int low, int high)
// {
//     if (low < high)
//         if (s[low] != s[high])
//             return false;
//     else
//         return true;


//     return check_palindrome(s, low+1, high-1);
// }


// gfg sol
bool check_palindrome(string& s, int start, int end)
{
    if (start >= end)
        return true;

    return (s[start] == s[end]) && (check_palindrome(s, start+1, end-1));
}


int main()
{
    
    string s1 = "abbcbba";
    string s2 = "abba";
    string s3 = "geeks";
    cout << std::boolalpha;

    cout << check_palindrome(s1, 0, s1.length()-1) << endl;
    cout << check_palindrome(s2, 0, s2.length()-1) << endl;
    cout << check_palindrome(s3, 0, s3.length()-1) << endl;



    return 0;
}