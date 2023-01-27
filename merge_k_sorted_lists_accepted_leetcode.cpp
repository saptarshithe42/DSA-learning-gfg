// https://leetcode.com/problems/merge-k-sorted-lists/

#include<bits/stdc++.h>
using namespace std;


struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *h1, ListNode *h2)
    {

        if (h1 == NULL)
        {
            return h2;
        }

        if (h2 == NULL)
        {
            return h1;
        }

        ListNode *head = NULL;
        ListNode *curr1 = NULL, *curr2 = NULL;
        ListNode *prev1 = NULL, *prev2 = NULL;

        if (h1->val <= h2->val)
        {
            head = h1;
            curr1 = h1;
            curr2 = h2;
        }
        else
        {
            head = h2;
            curr1 = h2;
            curr2 = h1;
        }

        while (1)
        {
            while (curr1 != NULL && curr1->val <= curr2->val)
            {
                prev1 = curr1;
                curr1 = curr1->next;
            }

            prev1->next = curr2;

            if (curr1 == NULL)
            {
                break;
            }

            while (curr2 != NULL && curr2->val <= curr1->val)
            {
                prev2 = curr2;
                curr2 = curr2->next;
            }

            prev2->next = curr1;

            if (curr2 == NULL)
            {
                break;
            }
        }

        return head;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        int n = lists.size();

        ListNode *head = NULL;

        for (int i = 0; i < n; i++)
        {
            head = mergeTwoLists(head, lists[i]);
        }

        return head;
    }
};