#include<iostream>
#include<algorithm>
#include<unordered_set>
using namespace std;

// naive solution
// based on sorting
// time comp : O(nlogn)
// int longest_consecutive_subsequence(int arr[], int n)
// {
//     sort(arr, arr+n);

//     int res = 0, temp = 1;

//     int i = 1;
//     while(i < n)
//     {
//         if(arr[i] == (arr[i-1] + 1))
//         {
//             res = max(res, ++temp);
//         }
//         else
//         {
//             temp = 1;
//         }
//         i++;
//     }

//     return res;

// }


int longest_consecutive_subsequence(int arr[], int n)
{
    unordered_set<int> s (arr, arr+n);

    int res = 1;
    for(auto x : s)
    {
        if(s.find(x - 1) == s.end())
        {
            int curr = 1;
            while(s.find(x + curr) != s.end())
            {
                curr++;
            }
            res = max(res, curr);
        }
        
    }

    return res;

}


int main()
{
    int arr[] = {1, 9, 3, 4, 2, 20, 5, 35, 6};
    int n = 9;

    cout << longest_consecutive_subsequence(arr, n);
    
    return 0;
}