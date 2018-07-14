// 568
class Solution{
public:
    int maxVacationDays(vector<vector<int> &flights, vector<vector<int>&days){
int N= flights.size();
int K = days[0].size();

vector<vector<int>> dp(K,vector<int>(N,0));
vector<vector<bool>> reach(K, vector<bool>(N,false));

//First week, no guesses for the previous city
for(int city =0; city < N; ++city)
{
    if( city==0 || flights[0][city])
    {
    dp[0][city]=days[city][0];
    reach[0][city] = true;
    }
}

//Topological Order(week)
    for(int week =1; week<K; ++week)
    {
    //current city
        for(int city=0; city<N; ++city)
        {
            for(int prevCity =0; prevCity <N; ++prevCity)
            {
                if(reach[week-1][prevCity] && (city==prevCity     ||flights[prevCity][city]))
                {
dp[week][city] = max(dp[week][city],                         dp[week-1][prevCity]+days[city][week]);
reach[week][city] = true;
                }
            }
        }
    }
int res=0;
for(int city =0;city<N; ++city)
    res=max(res, dp[K-1][city]);
return res;
}
};
