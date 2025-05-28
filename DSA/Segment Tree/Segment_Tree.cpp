#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
    vector<int> tree;

public:
    SegmentTree() {}

    SegmentTree(vector<int> &nums)
    {
        int n = nums.size();
        this->tree = vector<int>(4 * n);
        build(0, n - 1, 0, nums);
    }

    int build(int ss, int se, int si, vector<int> &nums)
    {

        if (ss == se)
        {
            tree[si] = nums[ss];
            return nums[ss];
        }
        int mid = ss + (se - ss) / 2;
        tree[si] = build(ss, mid, 2 * si + 1, nums) + build(mid + 1, se, 2 * si + 2, nums);

        return tree[si];
    }

    int rangeSum(int qs, int qe, int ss, int se, int si)
    {

        if (ss > qe || se < qs)
        {
            return 0;
        }

        if (ss >= qs && se <= qe)
        {
            return tree[si];
        }

        int mid = ss + (se - ss) / 2;

        return rangeSum(qs, qe, ss, mid, 2 * si + 1) + rangeSum(qs, qe, mid + 1, se, 2 * si + 2);
    }

    void update(int ss, int se, int i, int si, int diff)
    {

        if (i < ss || i > se)
        {
            return;
        }

        tree[si] = tree[si] + diff;

        if (se > ss)
        {

            int mid = ss + (se - ss) / 2;

            update(ss, mid, i, 2 * si + 1, diff);
            update(mid + 1, se, i, 2 * si + 2, diff);
        }
    }
};