#include <iostream>
using namespace std;
// my solution
// int delete_element(int arr[], int n, int x)
// {
//     int index = -1;
//     if (n == 0)
//     {
//         return index;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] == x)
//         {
//             index = i;
//             break;
//         }
//     }

//     for (int i = index + 1; i < n; i++)
//     {
//         arr[i - 1] = arr[i];
//     }
//     return index;
// }


// gfg solution
int deleteEle(int arr[], int n, int x)
{
	int i = 0;

	for(i = 0; i < n; i++)
	{
		if(arr[i] == x)
			break;
	}

	if(i == n)
		return n;

	for(int j = i; j < n - 1; j++)
	{
		arr[j] = arr[j + 1];
	}

	return n-1;
} 



int main()
{

    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;
    int x = 20;

    cout << "\n";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    // int k = delete_element(arr, n, x);
    n = deleteEle(arr, n, x);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}