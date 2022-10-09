// https://www.codingninjas.com/codestudio/problems/maze-obstacles_977241

int mod = (int)(1e9 + 7);

int f(int i, int j, vector< vector< int> > &mat)
{
    if(i >= 0 && j >= 0 && mat[i][j] == -1)
    {
        return 0;
    }
    
    if(i == 0 && j == 0)
    {
        return 1;
    }
    
    if(i < 0 || j < 0)
    {
        return 0;
    }
    
    int up = f(i-1, j, mat);
    int left = f(i, j-1, mat);
    
    return (up+left);
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    
    int dp[n][m];
   
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(mat[i][j] == -1)
                dp[i][j] = 0;
            
            else if(i == 0 && j == 0)
                dp[i][j] = 1;
            
            else
            {
                int up = 0, left = 0;
                
                if(i > 0)
                    up = dp[i-1][j] % mod;
                if(j > 0)
                    left = dp[i][j-1] % mod;
                
                dp[i][j] = (up + left) % mod;
             
            }
        }
    }
    
    return (dp[n-1][m-1]);
    
}