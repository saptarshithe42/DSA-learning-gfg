#include<iostream>
using namespace std;


int getMedian(int a1[], int a2[], int n1, int n2)
{
    int begin1 = 0, end1 = n1;

    while(begin1 <= end1)
    {
        int i1 = (begin1 + end1) / 2;
        int i2 = (n1 + n2 + 1)/2 - i1;

        int min1 = (i1 == n1) ? INT_MAX : a1[i1];
        int max1 = (i1 == 0) ? INT_MIN : a1[i1-1]; 
        int min2 = (i2 == n2) ? INT_MAX : a2[i2];
        int max2 = (i2 == 0) ? INT_MIN : a2[i2-1]; 

        if(max1 <= min2 && max2 <= min1)
        {
            if((n1 + n2) % 2 == 0)
            {
                return (double) (max(max1, max2) + min(min1, min2))/2;
            }
            else
            {
                return (double) (max(max1, max2));
            }
        }
        else if(max1 > max2)
        {
            end1 = i1-1;
        }
        else
        {
            begin1 = i1+1;
        }
    }
}


int main()
{
    int a1[] = {10,20,30,40,50};
    int n1 = 5;

    int a2[] = {5,15,25,27,28,55,65,75,85, 95};
    int n2 = 10;


    cout << getMedian(a1, a2, n1, n2) << endl;
    
    return 0;
}