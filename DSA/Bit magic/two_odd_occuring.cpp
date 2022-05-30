#include<iostream>
using namespace std;


// time complexity : theta(n)
void two_odd_occurring(int arr[], int n)
{
    int temp = 0,res1 = 0, res2 = 0;
    for(int i = 0; i < n; i++)
    {
        temp = temp ^ arr[i];
    }

    int sn = temp & ~(temp-1);

    for (int i = 0; i < n; i++)
    {
        if ((arr[i] & sn) != 0)
        {
            res1 = res1 ^ arr[i];
        }
        else
        {
            res2 = res2 ^ arr[i];
        }
    }

    cout << res1 << " " << res2 << endl;
}

int main()
{
    int arr1[] = {3,4,3,4,5, 4,4,6,7,7};

    int arr2[] = {20, 15, 20, 16};

    two_odd_occurring(arr1, 10);
    two_odd_occurring(arr2, 4);


    
    return 0;
}