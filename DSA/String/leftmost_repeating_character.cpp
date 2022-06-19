#include<iostream>
using namespace std;

// better approach
// time comp : O(n)
// but 2 traversals
// int leftmost_repeating_character(string& s)
// {
//     int count[256] = {0};

//     for(int i = 0; i < s.length(); i++)
//     {
//         count[s[i]]++;
//     }

//     for(int i = 0; i < s.length(); i++)
//     {
//         if(count[s[i]] > 1)
//             return i;
//     }

//     return -1;
// }


// efficient approach - 1
// time comp : O(n)
// single traversal
// int leftmost_repeating_character(string& s)
// {
//     int fIndex[256];
//     fill(fIndex, fIndex + 256, -1);

//     int res = INT_MAX;
//     for(int i = 0; i < s.length(); i++)
//     {
//         if(fIndex[s[i]] == -1)
//             fIndex[s[i]] = i;
//         else
//             res = min(res, fIndex[s[i]]);
//     }

//     return (res == INT_MAX ? -1 : res);
// }

//efficient approach - 2
// time comp : O(n)
// single traversal
int leftmost_repeating_character(string& s)
{
    bool visited[256] = {false};

    int res = -1;

    for(int i = s.length()-1; i >= 0; i--)
    {
        if(visited[s[i]] == true)
            res = i;
        else    
            visited[s[i]] = true;
    }

    return res;
}


int main()
{   
    string s = "abdcccccd";

    cout << leftmost_repeating_character(s) << "\n";
    
    return 0;
}