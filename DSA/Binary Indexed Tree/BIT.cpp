#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int bit[N];

int sum(int i)
{
    int ans = 0;
    while (i > 0)
    {
        ans += bit[i];
        i -= (i & -i);
    }
    return ans;
}

void update(int i, int x)
{
    while (i < N)
    {
        bit[i] += x;
        i += (i & -i);
    }
}

int rangeSum(int l, int r)
{
    // 1 based indexing
    return sum(r) - sum(l - 1);
}

int main()
{
    int n = 10;
    vector<int> arr(n, 1);

    // O(nlogn) construction
    // for (int i = 0; i < n; i++)
    // {
    //     update(i + 1, arr[i]);
    // }

    // O(n) construction
    for (int i = 1; i <= n; ++i)
    {
        bit[i] += arr[i - 1];
        int j = i + (i & -i);
        if (j <= n)
        {
            bit[j] += bit[i];
        }
    }

    // 1 based indexing in rangeSum, so add +1 to 0 based indexing queries

    cout << sum(5) << endl;
    cout << rangeSum(1, 5) << endl;
    cout << rangeSum(2, 4) << endl;

    return 0;
}
