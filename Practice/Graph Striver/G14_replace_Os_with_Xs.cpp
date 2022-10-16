// https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1

#include<bits/stdc++.h>
using namespace std;



class Solution{
public:
    void dfs(int i, int j, vector<vector<char>>& mat, vector<vector<int>>& vis, vector<vector<char>>& ans)
    {
        int n = mat.size();
        int m = mat[0].size();
        
        vis[i][j] = 1;
        
        if(mat[i][j] == 'O')
            ans[i][j] = 'O';
        else
            return;
        
        if(i >= 1 && vis[i-1][j] == 0)
            dfs(i-1, j, mat, vis, ans);
        
        if(i <= (n-2) && vis[i+1][j] == 0)
            dfs(i+1, j, mat, vis, ans);
            
        if(j >= 1 && vis[i][j-1] == 0)
            dfs(i, j-1, mat, vis, ans);
            
        if(j <= (m-2) && vis[i][j+1] == 0)
            dfs(i, j+1, mat, vis, ans);
        
    }



    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        /*
            Observe that, if a set of zeros (connected up, down, left or right but not
            diagonally) are connected to a zero on the boundary, then they are surely
            not surrounded by X on 4 sides, and hence cannot be converted.
            
            - So, find out boundary zeroes and do DFS to go along all its connected 
              zeroes and mark them as not convertible.
            - Rest, of the zeroes are convertible.
        */
        
        
        vector<vector<char>> ans (n, vector<char> (m, 'X'));
        
        vector<vector<int>> vis (n, vector<int> (m, 0));
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if((i == 0 || i == (n-1) || j == 0 || j == (m-1)) && mat[i][j] == 'O' && vis[i][j] == 0)
                {
                    dfs(i, j, mat, vis, ans);
                    ans[i][j] = 'O';
                }
            }
        }
        
        return ans;
        
    }
};