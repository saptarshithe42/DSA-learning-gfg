#include<iostream>
using namespace std;

// efficient sol
// time comp : O(n)
// Moore's voting algorithm
int majority_element(int arr[], int n)
{
    // 1st phase - finds a candidate
    int res = 0, count = 1;
    for(int i = 1; i < n; i++)
    {
        if(arr[res] == arr[i])
            count++;
        else
            count--;

        if(count == 0)
        {
            res = i;
            count = 1;
        }
    }


    // 2nd phase - checks if candidate is actually a majority element

    count = 0;
    for(int i = 0; i < n; i++)
    {
        if (arr[res] == arr[i])
            count++;
    }
    if (count <= (n/2))
        return -1;
    
    return res;
}




int main()
{
    int arr[] = {8,3,4,8,8};
    int n = 5;

    cout << majority_element(arr, n) << endl;
    
    return 0;
}