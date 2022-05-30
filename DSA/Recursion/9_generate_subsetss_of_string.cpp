#include <iostream>
using namespace std;

void generateSubsets(string& s, string curr=" ", int index=0)
{
    if (index == s.length())
    {
        cout << curr << " ";
        return;
    }

    generateSubsets(s, curr, index + 1);
    generateSubsets(s, curr + s[index], index + 1);
}

int main()
{

    string s1 = "ABC";
    generateSubsets(s1, "", 0);

    return 0;
}