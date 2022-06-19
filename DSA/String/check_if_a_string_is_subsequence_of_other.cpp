#include<iostream>
using namespace std;

// iterative solution
// Time comp : O(n1 + n2)
// Aux sp : O(1)
bool check_subsequence(string& s1, string& s2)
{
    int n1 = s1.length(), n2 = s2.length();

    int j = 0;
    
    for(int i = 0; (i < n1) && (j < n2); i++)
    {
        if(s1[i] == s2[j])
            j++;
    }

    return (j == n2);
}

// recursive sol

bool check_subsequence(string& s1, string& s2, int n, int m)
{
    if(m == 0)
        return true;

    if(n == 0)
        return false;

    if(s1[n-1] == s2[m-1])
        return check_subsequence(s1, s2, n-1, m-1);
    else
        return check_subsequence(s1, s2, n-1, m);


}


int main()
{
    string s1 = "ABCD";
    string s2 = "AD";

    cout << std::boolalpha;
    cout << check_subsequence(s1, s2) << "\n";
    cout << check_subsequence(s1, s2, s1.length(), s2.length()) << "\n"; 

    
    return 0;
}