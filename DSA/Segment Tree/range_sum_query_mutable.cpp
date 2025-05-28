// https://leetcode.com/problems/range-sum-query-mutable/

#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
    vector<int> tree;
    // vector<int> nums;

public:
    SegmentTree() {}

    SegmentTree(vector<int> &nums)
    {
        // this->nums = nums;

        int n = nums.size();

        this->tree = vector<int>(4 * n);

        build(0, n - 1, 0, nums);

        // cout << rangeSum(0, n-1, 0, n-1, 0);
    }

    int build(int ss, int se, int si, vector<int> &nums)
    {

        if (ss == se)
        {
            tree[si] = nums[ss];
            return nums[ss];
        }

        // cout << "In build" << endl;

        int mid = ss + (se - ss) / 2;
        // int mid = (ss + se) / 2;

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
        // int mid = (ss + se) / 2;

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

            // int mid = (ss + se) / 2;

            update(ss, mid, i, 2 * si + 1, diff);
            update(mid + 1, se, i, 2 * si + 2, diff);
        }
    }
};

class NumArray
{

    SegmentTree s;
    int size;
    vector<int> arr;

public:
    NumArray(vector<int> &nums)
    {

        s = SegmentTree(nums);

        size = nums.size();
        arr = vector<int>(nums.begin(), nums.end());
    }

    void update(int index, int val)
    {

        int diff = val - arr[index];

        arr[index] = val;

        s.update(0, size - 1, index, 0, diff);
    }

    int sumRange(int left, int right)
    {

        return s.rangeSum(left, right, 0, size - 1, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */