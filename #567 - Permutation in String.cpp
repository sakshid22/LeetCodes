class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        vector<int> D(256,0);
        int Total =0;
        for(auto &c: s1)
        {
            D[c]--;
        }
        
        for(int i=0, start = 0; i <= s2.size(); ++i)
        {
            if(Total==s1.size())
                return true;
            if(i==s2.size())
                break;
            
            char c=s2[i];
            if(D[c]<0)
            {
                D[c]++;
                Total++;
            }
            else
            {
                while (start <i && s2[start]!=c)
                {
                    Total --;
                    D[s2[start]]--;
                    start++;
                }
                start ++;
            }
        }
        return (false);
    }
};