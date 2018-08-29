//189

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
     int   n=nums.size();
        if(k<=0)
            return;
        int cntRotated=0, start=0, curr=0,temp=0;
        int numToBeRotated = nums[0];
            while(cntRotated < n)
            {
                do
                {
                    temp=nums[(curr+k)%n];
                    nums[(curr+k)%n]=numToBeRotated;
                    numToBeRotated=temp;
                    curr = (curr+k)%n;
                    cntRotated++;
                    
                }while(curr!=start);
            
             start++;
             curr=start;
             numToBeRotated=nums[curr];
           }
    }
};