//283
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for( int l=0, cur =0; cur<nums.size(); cur++)   // l= last Non Zero Found At
        {
            if(nums[cur]!=0)
                swap(nums[l++], nums[cur]);
        }       
    }
};