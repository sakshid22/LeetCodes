class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        for(int i=0; i<A.size(); i++)
            if(B[0]==A[i] && check(A,B,i)!=-1)
                return check(A,B,i);
        return -1;
    }
    
    
private:
    int check (string &A, string &B, int k)  {
        int m=A.size(), count =1;
        for(int i=0; i<B.size(); i++,k++)
        {
            if(k==m)
            {
                k=0;
                count++;
            }
            if (B[i]!=A[k])
                return -1; 
        }
       return count;
    }
};