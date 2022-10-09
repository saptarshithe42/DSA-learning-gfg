// https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003



int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    
    vector<vector<int>> dp(n, vector<int> (4, 0));
    
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][1], points[0][0]);
    dp[0][3] = max(points[0][0], max(points[0][1],points[0][2]));
    
    for(int day = 1; day < n; day++)
    {
        for(int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;
            
            for(int task = 0; task < 3; task++)
            {
                if(task != last)
                {
                    int point = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }
    
    return dp[n-1][3];

}

//     if(day == 0)
//     {
//         int maxi = 0;
//         for(int i = 0; i < 3; i++)
//         {
//             if(i != last)
//             {
//                 maxi = max(maxi, points[0][i]);
//             }
//         }
        
//         return maxi;
//     }
    
//     int maxi = 0;
    
//     for(int i = 0; i < 3; i++)
//     {
//        if(i != last)
//        {
//            int point = points[day][i] + helper(day-1, i, points);
//            maxi = max(maxi, point);
//        }
//     }
    
//     return maxi;