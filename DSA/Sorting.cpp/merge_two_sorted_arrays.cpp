#include<iostream>
using namespace std;


// time complexity : theta(m+n)
void merge_sorted_arr(int a[], int b[], int n1, int n2)
{
    int i = 0, j = 0;
    while ((i < n1) && (j < n2))
    {
            if(b[j] >= a[i])
            {
                cout << a[i] << " ";
                i++;
            }
            else
            {
                cout << b[j] << " ";
                j++;
            }
    }

    while (i < n1)
    {
        cout << a[i] << " ";
        i++;
    }

    while (j < n2)
    {
        cout << b[j] << " ";
        j++;
    }

}

int main()
{

    // int a[] = {10, 15, 20};
    // int b[] = {5, 6,6,15};
    // merge_sorted_arr(a, b, 3, 4);

    int a[] = {1,1,2,3,4,5,6,7};
    int b[] = {3,6,77,81,90};
    merge_sorted_arr(a, b, 8,5);



    return 0;
}