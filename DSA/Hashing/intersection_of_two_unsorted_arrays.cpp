#include<iostream>
#include<unordered_set>
using namespace std;

int count_distinct_intersection(int a[], int m, int b[], int n)
{
    unordered_set<int> s(a, a+m);

    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(s.find(b[i]) != s.end())
        {
            count++;
            s.erase(b[i]);
        }
    }

    return count;
}       


int main()
{
    int a[] = {10, 15, 20, 5, 30};
    int m = 5 ;
    int b[] = {30, 5, 30, 80};
    int n = 4;

    cout << count_distinct_intersection(a, m, b, n);
    
    return 0;
}