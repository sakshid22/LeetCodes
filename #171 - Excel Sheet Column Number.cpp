//171

class Solution {
public:
    int titleToNumber(string s) {        
        int ret=0;
        for(int i=0; i<s.length(); i++)
            ret= (s[i]-64) + ret*26;
        return ret;
    }
};