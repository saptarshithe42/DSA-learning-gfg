#include<iostream>
#include<unordered_map>
using namespace std;

void more_than_n_by_k_occurrences(int arr[], int n, int k)
{
    int c = n/k;

    unordered_map<int, int> m;

    for(int i = 0; i < n; i++)
        m[arr[i]]++;

    for(auto x : m)
    {
        if(x.second > c)
            cout << x.first << " ";
    }

}

int main()
{
    int arr[] = {30, 10, 20, 20, 10, 20, 30, 30};
    int n = 8;
    int k = 4;

    more_than_n_by_k_occurrences(arr, n, k);


    
    return 0;
}