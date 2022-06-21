#include<iostream>
using namespace std;

bool areRotations(string& s1, string& s2)
{
    if(s1.length() != s2.length())
        return false;

    return ((s1 + s1).find(s2) != string::npos);
}


int main()
{
    
    string s1 = "ABAAA";
    string s2 = "BAAAA";

    cout << std::boolalpha;
    cout << areRotations(s1, s2) << endl;

    return 0;
}