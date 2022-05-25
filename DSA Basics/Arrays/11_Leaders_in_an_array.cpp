#include<iostream>
using namespace std;

// naive solution
// time complexity : O(n^2)

// void leaders_in_array(int arr[], int n)
// {
//     for(int i = 0; i < n; i++)
//     {
//         int j;
//         for (j = i+1;  j < n; j++)
//         {
//             if (arr[j] >= arr[i])
//                 break;
//         }

//         if (j == n)
//             cout << arr[i] << " ";
//     }
// }

// efficient solution
// time comp : theta(n)
// prints left to right
void leaders_in_array(int arr[], int n)
{
    int curr_ldr = arr[n-1];
    cout << curr_ldr << " ";

    for (int i = n-2; i >= 0; i--)
    {
        if (arr[i] > curr_ldr)
        {
            curr_ldr = arr[i];
            cout << curr_ldr << " ";
        }
    }

}



int main()
{
    int a1[] = {7, 10, 4, 3, 6, 5, 2};
    leaders_in_array(a1, 7);
    cout << endl;


    int a2[] = {10, 20, 30, 40};
    leaders_in_array(a2, 4);
    cout << endl;


    int a3[] = {40, 30, 20, 10};
    leaders_in_array(a3, 4);
    cout << endl;
   
    
    return 0;
}