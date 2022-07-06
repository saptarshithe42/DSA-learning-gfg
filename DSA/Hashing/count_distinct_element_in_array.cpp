#include<iostream>
#include<unordered_set>
using namespace std;


int countDistinct(int arr[], int n)
{
    unordered_set<int> s(arr, arr+n);

    return s.size();
}

int main()
{
    int arr[] = {3, 2, 8,8, 2, 3, 15, 15, 15, -8, -8, -7};
    int n = 12;

    cout << countDistinct(arr, n);


    
    return 0;
}