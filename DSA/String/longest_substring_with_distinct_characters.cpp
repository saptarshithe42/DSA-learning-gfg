#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// my sol
// time comp : O(n)
// int longestDistinct(string& s)
// {
//     int i = 0, n = s.length(), l = 0, res = 0, curr = 0;
//     unordered_set<char> m;

//     while(i < n)
//     {
//         if(m.find(s[i]) == m.end())
//         {
//             curr++;
//             m.insert(s[i]);
//             res = max(res, curr);
//             i++;
//         }
//         else
//         {
//             while(m.find(s[i]) != m.end())
//             {
//                 m.erase(m.find(s[l]));
//                 l++;
//                 curr--;
//             }
//         }
//     }

//     return res;
// }

// gfg sol
// time comp : O(n)

int longestDistinct(string str)
{
    int n = str.length();
    int res = 0;
    vector<int> prev(256, -1);
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        i = max(i, prev[str[j]] + 1);
        int maxEnd = j - i + 1;
        res = max(res, maxEnd);
        prev[str[j]] = j;
    }
    return res;
}

int main()
{
    string str = "geeksforgeeks";
    int len = longestDistinct(str);
    cout << "The length of the longest distinct characters substring is " << len;
    return 0;
}
