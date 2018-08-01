//26

public:
    int removeDuplicates(vector<int>& nums) {
        
/*       int count=0, length=0;
        int l= nums.size()-1;
        for(int i=0; i<nums.size();i++)
        {
            if(nums[i]==nums[i++])
            { count++;
             nums[l] = push_back(i);
            }
            
                
        }
        length = nums.size() - count;
        return nums;
*/
        
        int count=0;
        int n=nums.size();
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
                count++;
            else
                nums[i-count]=nums[i];
        }
        return (nums.size())-count;
    }
    
};