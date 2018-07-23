//218

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
     
        vector<pair<int,int>> res;
        int cur=0, cur_X,cur_H =-1, len = buildings.size();
        priority_queue<pair < int,int>> liveBlg;      // Height, end time
            while(cur<len || !liveBlg.empty())
            {
                cur_X = liveBlg.empty() ? buildings[cur][0]:liveBlg.top().second;
                
                if(cur>=len || buildings[cur][0] > cur_X)
                {
                    while(!liveBlg.empty() && (liveBlg.top().second <= cur_X))
                        liveBlg.pop();
                }
                else
                {
                    // new building starts before the top one ends
                    cur_X = buildings[cur][0];
                    while(cur<len && buildings[cur][0] == cur_X)
                    {
                        liveBlg.push(make_pair(buildings[cur][2], buildings[cur][1]));
                        cur++;
                    }
                }
                cur_H = liveBlg.empty() ? 0:liveBlg.top().first;
                if(res.empty() || (res.back().second != cur_H))
                    res.push_back(make_pair(cur_X, cur_H));
            }
        return res;
    }
};