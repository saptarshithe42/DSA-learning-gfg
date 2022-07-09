#include<iostream>
#include<unordered_map>
using namespace std;


void count_distinct_in_each_window(int arr[], int n, int k)
{
    unordered_map<int, int> m;

    int low = 0;
    for(int i = 0; i < k; i++)
    {
        m[arr[i]]++;
    }

    cout << m.size() << " ";

    for(int i = k; i < n; i++)
    {
        if(--m[arr[low]] == 0)
        {
            m.erase(arr[low]);
        }
        low++;
        m[arr[i]]++;

        cout << m.size() << " ";
    }
}

int main()
{

    int arr[] = {10, 20, 20, 10, 30, 40, 10};
    int n = 7;
    int k = 4;

    count_distinct_in_each_window(arr, n, k);
    
    return 0;
}