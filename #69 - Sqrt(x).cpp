//69

class Solution {
public:
    int mySqrt(int x) {
        
    /*    long i=0, res=0;
        if(i<2)
            return x;
        for(i=1; i<=x/2; i++)
        {
            
            
            if(i*i == x)
                res =i;
            else if(i*i < x  && (i+1)*(i+1) >x)
            {  res = i;
                break;
            }
                    
        }
        return res;
        
    */
        
        int low=0,high=x, mid;
        if(x<2) return x;
        while(low<high)
        {
            mid=(low+high)/2;
            if(x/mid >= mid) low=mid+1;
            else high=mid;
        }
        return high-1;
    }
};