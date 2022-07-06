#include<iostream>
#include<unordered_set>
using namespace std;


bool isPairPresent(int arr[], int n, int sum)
{
    unordered_set<int> s;

    for(int i = 0; i < n; i++)
    {
        if(s.find(sum - arr[i]) != s.end())
        {
            return true;
        }
        else
        {
            s.insert(arr[i]);
        }
    }

    return false;
}

int main()
{
    int arr[] = {3, 2, 8, 15, -8};
    int n = 5;
    int sum = 17;

    cout << std::boolalpha;
    cout << isPairPresent(arr, n, sum);


    
    return 0;
}