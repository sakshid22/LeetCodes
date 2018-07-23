//514

class Solution {
public:
    
    int help(string& ring, string& key, int k, int curr, vector<vector<int>>& record, unordered_map<char,vector<int>>& h )
    {
        if(record[k][curr]>=0)
            return record[k][curr];
        char ch = key[k];
        int n = ring.length();
        int m = key.length();
        int res=-1;
        for(auto i:h[ch])
        {
            int left = curr -i;
            if(left <0)
                left+=n;
            int right = i - curr;
            if(right <0)
                right+= n;
            int shift = min(left,right);
            if(res<0)
            {
                if(k+1<m)
                res = shift + help(ring,key, k+1, i, record, h);
                else
                    res = shift;
            }
            else
            {
                if(k+1<m)
                    res = min(res, shift + help(ring, key, k+1, i, record, h));
                else
                    res = min(res,shift);
            }
        }
        record[k][curr]=res;
        return res;
    }
    
    int findRotateSteps(string ring, string key) {
      int m = key.length();
        int n= ring.length();
        unordered_map <char,vector<int>>h;
            for(int i=0;i<n;i++)
            {
                h[ring[i]].push_back(i);
                
            }
        vector<vector<int>> record(m, vector<int>(n,-1));
        return m+help(ring, key, 0, 0, record, h);
    }
};