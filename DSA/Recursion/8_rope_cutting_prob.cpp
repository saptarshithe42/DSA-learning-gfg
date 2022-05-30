#include<iostream>
#include<algorithm>
using namespace std;

// gfg sol
// time : O(3^n)
int max_pieces(int n, int a, int b, int c)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return -1;

    int res = max_pieces(n-a, a, b, c);
    int res1 = max_pieces(n-b, a, b, c);
    int res2 = max_pieces(n-c, a, b, c);
    res = max(max(res, res1), max(res1,res2));

    if (res == -1)
        return -1;
    
    return (res + 1);
}


int main()
{
    cout << max_pieces(5,2,5,1) << endl;
    cout << max_pieces(23,12,9,11) << endl;
    cout << max_pieces(5,4,2,6) << endl;
    cout << max_pieces(9,2,2,2) << endl;




    return 0;
}