// #76
class Solution {
public:
    string minWindow(string s, string t) {
      
        if(s.empty() || t.empty())
            return "";
        int count = t.size();
        int require[128] ={0};
        bool chset[128] = {false};
        for( int i=0;i<count; ++i)
        {
            require[t[i]]++;
            chset[t[i]]=true;
        }
        int i=-1;
        int j=0;
        int minlen = INT_MAX;
        int minIdx =0;
        while(i<(int)s.size() && j<(int)s.size())
        {
            if(count)
            {
                i++;
                require[s[i]]--;
                if(chset[s[i]] && require[s[i]] >=0)
                    count --;
            }
            else
            {
                if(minlen >i-j+1)
                {
                    minlen = i-j+1;
                    minIdx=j;
                }
                require [s[j]]++;
                if(chset[s[j]] && require[s[j]]>0)
                {
                    count++;
                }
                j++;
            }
        }
        if(minlen == INT_MAX)
            return "";
        return s.substr(minIdx, minlen);
            
        
    }
};