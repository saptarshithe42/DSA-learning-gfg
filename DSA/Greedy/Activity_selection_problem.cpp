#include <iostream>
#include<utility>
#include<algorithm>
using namespace std;

bool myCmp(pair<int, int>& p1, pair<int, int>& p2)
{
    return p1.second < p2.second;
}

// first -> start time, second -> end time

int maxActivities(pair<int, int> arr[], int n)
{
    sort(arr, arr + n, myCmp);

    int res = 1;
    int prev = 0;

    for(int i = 1; i < n; i++)
    {
        if(arr[i].first >= arr[prev].second)
        {
            res++;
            prev = i;
        }
    }

    return res;
}

int main()
{
    // pair<int, int> arr[] = {make_pair(12, 25), make_pair(10, 20), make_pair(20, 30)};

    // pair<int, int> arr[] = {make_pair(2, 3), make_pair(1, 4), make_pair(5, 8), make_pair(6, 10)};

    pair<int, int> arr[] = {make_pair(1, 3), make_pair(2, 4), make_pair(3, 8), make_pair(10, 11)};
    int n = 4;

    cout << maxActivities(arr, n);

    return 0;
}