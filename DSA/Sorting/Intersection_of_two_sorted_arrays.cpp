#include <iostream>
using namespace std;

void intersection(int a[], int b[], int m, int n)
{
    if(m == 0 || n == 0)
        return;

    int i = 0, j = 0;
    
    while(i < m && j < n)
    {
        if(i > 0 && a[i] == a[i-1])
        {
            i++;
            continue;
        }

        if(a[i] < b[j])
            i++;
        else if(a[i] > b[j])
            j++;
        else
        {
            cout << a[i] << " ";
            i++; j++;
        }
    }
}

int main()
{

    int a[] = {1, 3, 5, 10, 10, 10, 15, 15, 20};
    int b[] = {1, 5, 10, 10, 15, 20, 30};

    int m = sizeof(a) / sizeof(a[0]);
    int n = sizeof(b) / sizeof(b[0]);
    intersection(a, b, m, n);
    return 0;
}