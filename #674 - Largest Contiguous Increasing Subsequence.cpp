//674

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
      
        int temp=0, res=1;
        if(nums.size()==0) return 0;
        for(int i=0; i<nums.size(); i++)
        {
            temp++;
            if(i<nums.size() -1 && nums[i] >= nums[i+1])
            {
                res = max(res,temp);
                temp =0;
            }
        }
        return max(res,temp);
    }
};