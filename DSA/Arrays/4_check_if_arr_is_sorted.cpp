#include <iostream>
using namespace std;

bool check_sorted(int arr[], int n)
{
    bool flag = true;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            flag = false;
            break;
        }
    }
    return (flag);
}

int main()
{
    int a1[] = {8, 12, 15};
    cout << std::boolalpha;

    cout << check_sorted(a1, 3) << "\n";

    int a2[] = {10};
    cout << check_sorted(a2, 1) << "\n";

    int a3[] = {8, 10, 10, 12};
    cout << check_sorted(a3, 4) << "\n";

    int a4[] = {100, 20, 200};
    cout << check_sorted(a4, 4) << "\n";

    return 0;
}