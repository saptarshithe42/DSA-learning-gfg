#include<iostream>
using namespace std;


// time complexity : theta(n)

void frequencies_in_sorted_array(int arr[], int n)
{
    int i = 1, freq = 1;
    while(i < n)
    {
        while(i < n && arr[i] == arr[i-1])
        {
            freq++;
            i++;
        }

        cout << arr[i-1] << " " << freq << "\n";
        freq = 1;
        i++;
    }
    if (n == 1 || arr[n-1] != arr[n-2])
        cout << arr[n-1] << " " << 1<< "\n";

}



int main()
{
    int a1[] = {10, 10, 10, 25, 30, 30};
    frequencies_in_sorted_array(a1, 6);
    cout << endl;


    int a2[] = {10, 20, 30, 40};
    frequencies_in_sorted_array(a2, 4);
    cout << endl;


    int a3[] = {40, 40, 40, 40};
    frequencies_in_sorted_array(a3, 4);
    cout << endl;
   
    
    return 0;
}