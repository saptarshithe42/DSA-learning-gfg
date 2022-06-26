#include <iostream>
using namespace std;

// Print those permutations of "ABC" which do not contain "AB"

bool isSafe(string s, int l, int i, int r)
{
    if(l != 0 && s[l-1] == 'A' && s[i] == 'B')
        return false;

    if(r == (l+1) && s[i] == 'A' && s[l] == 'B')
        return false;

    return true;
}

void permute(string s, int l, int r)
{
    if (l == r)
    {
        cout << s << " ";
        return;
    }
    else
    {
        for (int i = l; i <= r; i++)
        {

            if (isSafe(s, l, i, r))
            {
                swap(s[l], s[i]);
                permute(s, l + 1, r);
                swap(s[l], s[i]);
            }
        }
    }
}

int main()
{
    string s = "ABC";

    permute(s, 0, s.length() - 1);

    return 0;
}