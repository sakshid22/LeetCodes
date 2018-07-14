//213
class Solution {
public:
   
    
int rob_line (vector <int> &nums, int start, int end)
{
int odd_sum =0;
int even_sum =0;
	for(int i=start; i<end; i++)
	{
		if(i%2)
		odd_sum = max(even_sum, odd_sum + nums[i]);
		else
		even_sum = max(odd_sum, even_sum+ nums[i]);
	}
return max(odd_sum, even_sum);
}
int rob(vector <int>& nums)
{
	if(nums.size()==0)
	return 0;
	else if(nums.size()==1)
	return nums[0];
	else
	return max (rob_line(nums,0,nums.size()-1) ,rob_line(nums,1,nums.size()));
}


};