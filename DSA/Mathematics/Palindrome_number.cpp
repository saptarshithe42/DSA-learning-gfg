#include<iostream>
using namespace std;

bool isPalindrome(int n)
{
    int temp = n;
    int rev = 0;
    while(temp != 0)
    {
        rev = (rev * 10) + (temp % 10);
        temp = temp / 10;
    }

    return (rev == n);
}

int main()
{
    cout << std::boolalpha;

    cout << isPalindrome(45454) << endl;
    cout << isPalindrome(12) << endl;
    cout << isPalindrome(1) << endl;
    cout << isPalindrome(121) << endl;
    


    return 0;
}