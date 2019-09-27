#3 - Longest substring with repeating characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int last[300];
        int len=s.length();
        if(len==0) return 0;
        int temp=1;
        memset(last, -1, sizeof(last));
        int ans=1;
        last[s[0]] =0;
        for(int i=1; i<len; i++)
        {
            int lastApp =last[s[i]];
            if(lastApp ==-1) 
                temp++;
            else 
                temp = min(temp+1, i-lastApp);
            last[s[i]]=i;
            ans=max(ans,temp);
        }
        return ans;
    }
};