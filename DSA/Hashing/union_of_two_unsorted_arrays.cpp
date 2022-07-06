#include<iostream>
#include<unordered_set>
using namespace std;

int count_distinct_union(int a[], int m, int b[], int n)
{
    unordered_set<int> s(a, a+m);

    for(int i = 0; i < n; i++)
    {
        s.insert(b[i]);
    }

    return s.size();
}       


int main()
{
    int a[] = {10, 15, 20, 5, 30};
    int m = 5 ;
    int b[] = {30, 5, 30, 80};
    int n = 4;

    cout << count_distinct_union(a, m, b, n);
    
    return 0;
}