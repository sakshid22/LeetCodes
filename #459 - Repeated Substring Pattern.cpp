class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len=s.length();
        for(int i=1; i<=len/2;i++)
        {
            if(len%i==0)
            {
                string str1 = s.substr(0,i);
                int count =1;
                for(int j=i;j<s.length();j=j+i)
                {
                    string str2 = s.substr(j,i);
                    if(str1==str2)
                        count++;
                    else
                        break;                  
                }
                if(count==len/i)
                        return true; 
            }
            
        }
         return false;
    }
};