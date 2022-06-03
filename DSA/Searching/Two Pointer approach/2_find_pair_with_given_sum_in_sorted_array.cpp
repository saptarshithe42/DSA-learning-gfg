#include<iostream>
using namespace std;

bool isPair(int arr[], int n, int x)
{
    int left = 0, right = (n-1);

    while(left < right)
    {
        if(arr[left] + arr[right] == x)
        {
            return true;
        }
        else if (arr[left] + arr[right] > x)
            right--;
        else
            left++;
    }

    return false;
}


int main()
{
    int arr[] = {2, 5, 8, 12, 30};
    int n = 5;
    int x = 18;

    cout << std::boolalpha;

    cout << isPair(arr, n, x) << endl;


    
    return 0;
}