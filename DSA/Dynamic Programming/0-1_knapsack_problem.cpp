#include<iostream>
using namespace std;

int knapSack(int w, int wt[], int val[], int n)
{   
    if(n == 0 || w == 0)
        return 0;

    if(wt[n-1] > w)
        return knapSack(w, wt, val, n-1);
    
    else
        return max(knapSack(w, wt, val, n-1), val[n-1] + knapSack(w - wt[n-1], wt, val, n-1));

}


int main()
{
    int val[] = {10, 40, 30, 50};
    int wt[] = {5, 4, 6, 3};
    int n = 4;
    int w = 10;

    cout << knapSack(w, wt, val, n);
    
    return 0;
}