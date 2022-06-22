#include <iostream>
using namespace std;

const int CHAR = 256;
int fact(int n)
{
    return (n <= 1) ? 1 : n * fact(n - 1);
}

int lexRank(string& str)
{
    int res = 1;
    int n = str.length();

    int count[CHAR] = {0};
    int mul = fact(n);

    // count of all characters
    // assume all characters are distinct
    for(int i = 0; i < n; i++)
        count[str[i]]++;

    // cumulative sum
    for(int i = 1; i < CHAR; i++)
        count[i] += count[i-1];

    for(int i = 0; i < (n-1); i++)
    {
        mul = mul / (n-i);
        res += mul*count[str[i] - 1];
        // updating count array to reduce the count of used up alphabet
        for(int j = str[i]; j < CHAR; j++)
            count[j]--;
    }


    return res;
}

int main()
{
    string str = "STRING";
    cout << lexRank(str);
    return 0;
}