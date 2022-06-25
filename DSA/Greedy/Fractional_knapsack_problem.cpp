#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

bool myCmp(pair<int, int> a, pair<int, int> b)
{
    double r1 = (double)a.first / a.second;
    double r2 = (double)b.first / b.second;

    return (r1 > r2);
}

// first of pair is value, second is weight (first / second is value per weight)

//  time comp : O(nlogn)

double fKnapS(int w, pair<int, int> arr[], int n)
{
    sort(arr, arr + n, myCmp);

    double res = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i].second <= w)
        {
            res += arr[i].first;
            w = w - arr[i].second;
        }
        else
        {
            res += arr[i].first * ((double)w / arr[i].second);
            break;
        }
    }

    return res;
}

int main()
{
    pair<int, int> arr[] = {{600, 50}, {500, 20}, {400, 30}};
    int n = 3;
    int w = 70;

    cout << fKnapS(w, arr, n);

    return 0;
}