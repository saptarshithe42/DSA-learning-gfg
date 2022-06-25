#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;

bool myCmp(pair<int, int>& p1, pair<int, int>& p2)
{
    return (p1.second > p2.second);
}

// first -> deadline, second -> profit

int maxProfit(pair<int,int> arr[], int n)
{
    int m = 0;
    for(int i = 0; i < n; i++)
    {
        m = max(m, arr[i].first);
    }

    bool slots[m];
    fill(slots, slots+m, false);

    sort(arr, arr + n, myCmp);


    int profit = 0;
    for(int i = 0; i < n; i++)
    {
        int slot = arr[i].first - 1;
        if(slots[slot] == false)
        {
            slots[slot] = true;
            profit += arr[i].second;
        }
        else
        {
            while(slot >= 0)
            {
                if(slots[slot] == false)
                {
                    slots[slot] = true;
                    profit += arr[i].second;
                    break;
                }
                slot--;
            }
        }
    }

    return profit;
}


int main()
{   
    // pair<int, int> arr[] = {{4, 70}, {1, 80}, {1, 30}, {1, 100}};
    // pair<int, int> arr[] = {{2, 50}, {2, 60}, {3, 20}, {3, 30}};
    pair<int, int> arr[] = {{2, 100}, {1, 50}, {2, 10}, {1, 20}, {3, 30}};
    int n = 5;

    cout << maxProfit(arr, n) << endl;
    
    return 0;
}