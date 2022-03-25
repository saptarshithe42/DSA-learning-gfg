#include<iostream>
using namespace std;

int main()
{
    string s = "";
    s = s + "s";
    // s = s + 'm';
    cout << s << endl;

    char ch = '0';
    ch++;
    cout << ch << endl;

    char a = 'm';
    s = s + a + ch;
    cout << s << endl;

    return 0;
}