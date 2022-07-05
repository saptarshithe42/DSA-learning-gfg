#include<iostream>
#include<queue>
using namespace std;


void medianOfStream(int arr[], int n)
{
    priority_queue<int> s;
    priority_queue<int, vector<int>, greater<int>> g;

    s.push(arr[0]);
    cout << arr[0] << " ";

    for(int i = 1; i < n; i++)
    {
        int x = arr[i];

        if(s.size() > g.size())
        {
            if(x < s.top())
            {
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else
                g.push(x);

            cout << (s.top() + g.top()) / 2.0 << " ";
        }
        else
        {
            if(x <= s.top())
                s.push(x);
            else
            {
                g.push(x);
                s.push(g.top());
                g.pop();
            }

            cout << s.top() << " ";
        }

    }
}


int main()
{
    int arr[] = {25, 7, 10, 15, 20};
    int n = 5;

    medianOfStream(arr, n);


    return 0;
}