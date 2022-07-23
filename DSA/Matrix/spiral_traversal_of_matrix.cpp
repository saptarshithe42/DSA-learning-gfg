#include <iostream>
#include <cmath>
#include <bits/stdc++.h> 
#include <climits>
#include <deque>
using namespace std;

const int R = 4, C = 4;

void printSpiral(int mat[4][4], int R, int C)
{
    int top = 0, right = C-1, bottom = R-1, left = 0;

    while((top <= bottom) && (left <= right))
    {
        // print top row from left to right
        for(int i = left; i <= right; i++)
        {
            cout << mat[top][i] << " ";
        }

        top++;

        // print right column from top to bottom
        for(int i = top; i <= bottom; i++)
        {
            cout << mat[i][right] << " ";
        }

        right--;


        if(top <= bottom)
        {
            // print bottom row from right to left
            for(int i = right; i >= left; i--)
            {
                cout << mat[bottom][i] << " ";
            }

            bottom--;
        }


        if(left <= right)
        {
            // print left column from bottom to top
            for(int i = bottom; i >= top; i--)
            {
                cout << mat[i][left] << " ";
            }

            left++;
        }

    }
}

int main()
{	
	int arr[R][C] = {{1, 2, 3, 4},
				    {5, 6, 7, 8},
				    {9, 10, 11, 12},
				    {13, 14, 15, 16}};

  printSpiral(arr, R, C);

	return 0;
}