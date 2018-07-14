#139
class Solution {
public:
 /*
    int numDecodings(string s) {
        int n=s.size();
        if(!n || s[0] =='0')
            return 0;
        int f0=1,f1=1,f2,i;
        for(i=2;i<=n;++i)
        {
            f2=(int)(s[i-1]!='0')*f1 +
               (int)((s[i-2] =='1') || (s[i-1]=='2' && s[i-1]<'7'))*f0;
            f0=f1;
            f1=f2;    
         }
          return f1;
    }
*/
    
    int numDecodings(string s){
        int n=s.size();
        if(!n || s[0] =='0')
            return 0;
        int f[n+1]= {1,1}, i;
        for(i=2;i<=n;i++)
            f[i]=(int)(s[i-1]!='0')*f[i-1] + (int)((s[i-2]=='1')||(s[i-2]=='2' && s[i-1]<'7'))*f[i-2];
        return f[n];
    }
};