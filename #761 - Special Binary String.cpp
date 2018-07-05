#761
class Solution {
public:
    string makeLargestSpecial(string S) {
        string ans =S;
        string cur =S;
        while(makespecial(cur, ans))
        {
            cur = ans;
        }
        return ans;
    }
    
    bool makespecial( string S, string &result){
        
        for(int i0=0; i0<S.size(); ++i0){
            int n0=0;
            int n1=0;
            for(int i1=i0; i1<S.size();++i1)
            {
                if(S[i1] == '1')
                    n1++;
                else
                    n0++;
                if(n1<n0)
                    break;
                else if(n1 == n0)
                {
                    string s1= S.substr(i0, i1-i0+1);
                    int j0 = i1+1;
                    int m0 = 0;
                    int m1 = 0;
                    for(int j1=j0; j1<S.size(); ++j1)
                    {
                        if(S[j1] == '1')
                            m1++;
                        else
                            m0++;
                        if(m1<m0)
                            break;
                        else if(m1==m0){
                            string s2 =S.substr(j0, j1-j0+1);
                            if(s2>s1){
                                string s0 = S.substr(0,i0);
                                string s3 = S.substr(j1+1);
                                result = s0+s2+s1+s3;
                                return true;
                            }
                            else
                                break;
                    
                        }
                    
                    }
                    
                }
            }
            
        }
        return false;
    }
        
};