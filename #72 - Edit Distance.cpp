class Solution {
public:
    
    int minDistance(string s1, string s2)
    {
    int m = s1.length();
    int n = s2.length();
    int dp[m+1][n+1];
    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = i;
    }

    for (int j = 0; j <= n; j++)
    {
        dp[0][j] = j;
    }

    for (int i = 1; i <= m; i++) 
    {
        for (int j = 1; j <= n; j++)
        {
        if (s1[i-1] == s2[j-1]) 
            dp[i][j] = dp[i-1][j-1];
            
        else
            dp[i][j] = 1 + min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1]);
        }
    }
    return dp[m][n];
}
/*
    
   int minDistance(string word1, string word2) {
      
        int m = word1.length();
        int n = word2.length();
        int i,j;
        int dp[m+1][n+1];
        
        for( i=0; i<=m; i++)
            dp[i][0] = i;
        for( j=0; j<=n; j++)
            dp[0][j] = j;
        
        for(int i=1; i<m; i++)
        {
            for(j=1; j<n; j++)
            {
                if(word1[i-1]==word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1+ min( min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]);
            }
        }
   //     cout<<m;
   //    cout<<n;
        return dp[m-1][n-1];

    //   return dp[m][n]; 
    }
*/
    
};