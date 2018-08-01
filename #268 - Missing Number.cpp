//268
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n=nums.size(), sum=0, a;
        for( int i=0;i<nums.size ();i++)
        {
            sum +=nums[i];
            
        }
        a= (n*(n+1))/2;
        return a-sum;
    }
};