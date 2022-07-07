#include<iostream>
#include<unordered_map>
using namespace std;

void countFrequency(int arr[], int n)
{
    unordered_map<int, int> m;

    for(int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }

    for(auto x : m)
    {
        cout << x.first << " " << x.second << "\n";
    }
}


int main()
{
    int arr[] = {10, 12, 10, 15, 10, 20, 12, 12};
    int n = 8;

    countFrequency(arr, n);
    
    return 0;
}