#include<iostream>
#include<set>
using namespace std;

void ceiling_on_left_side(int arr[], int n)
{
    cout << -1 << " ";

    set<int> s;
    s.insert(arr[0]);

    for(int i = 1; i < n; i++)
    {
        auto it = s.lower_bound(arr[i]);
        if(it != s.end())
        {
            cout << *it << " ";
        }
        else
        {
            cout << -1 << " ";
        }

        s.insert(arr[i]);
    }

}


int main()
{
    int arr[] = {2, 8, 30, 15, 25, 12};
    int n = 6;

    ceiling_on_left_side(arr, n);
    cout << endl;


    
    return 0;
}