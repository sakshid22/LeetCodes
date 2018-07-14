// #139
class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        
/*
        
if(wordDict.size()==0)
return false;
vector<bool> dp(s.size()+1, false);
dp[0]=true;

for(int i=1;i<=s.size(); i++)
{
    for(int j=i-1;j>=0; j--)
    {
        if(dp[j])
        {
        string word=s.substr(j,i-j);
            if(wordDict.find(word)!=wordDict.end())
            {
                dp[i]=true;
                break;
            }
        }
    }
}
return dp[s.size()];
}

*/
        
unordered_set<string>dict(begin(wordDict),end(wordDict));
int n=s.size();
vector<bool>dp(n+1, false);
        dp[0] = true;
        
for(int i=1; i<=n ; i++)
{
    for(int j=1; j<=i; j++)
    {
        string word = s.substr(i-j,j);
        if(dp[i-j] && dict.count(word))
        {
            dp[i]=true;
            break;
        }
    }
}
           
return dp[n];
    }
};