//327

class Solution {

    
    private:
    vector <long long int> merge(vector<long long int>& nums, int start, int mid, int end  )
    {
        int i =start;
        int j = mid+1;
        vector<long long int> result;
            while(true)
            {
                if(i ==mid+1)
                {
                    while(j<=end)
                    {
                        result.push_back(nums[j]);
                        j++;
                    }
                    break;
                }
                else if(j==end+1)
                {
                    while(i<=mid)
                    {
                        result.push_back(nums[i]);
                        i++;
                    }
                    break;
                }
                else
                {
                    if(nums[i] < nums[j])
                    {
                        result.push_back(nums[i]);
                        i++;
                    }
                    else
                    {
                        result.push_back(nums[j]);
                        j++;
                    }
                }
            }
        return result;
    }
    
    int mergesort(vector <long long int>& sums, int start, int end, int lower, int upper)
    {
        if(start>end)
            return 0;
        else if(start == end)
        {
            if(sums[start] >=lower && sums[end] <= upper)
                return 1;
            else
                return 0;
        }
    int mid=(start+end)/2;
        int result = mergesort(sums, start, mid, lower, upper) + mergesort( sums, mid+1, end, lower, upper);
        int i, j, k;
            for(i=start, j=k=mid+1; i<= mid ; i++)
            {
                while(j<=end && (sums[j] - sums[i]) < lower ) ++j;
                while(k<=end && (sums[k] - sums[i] <= upper) ) ++k;
                result = result + (k-j);
            }
        vector <long long int>temp = merge(sums, start, mid, end);
        for(i=start ; i<=end; i++)
        {
            sums[i] = temp[i-start];
            
        }
        return result;
    }

public:
   
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        
    int n=nums.size();
        int i;
        if(n==0)
            return 0;
        vector <long long int> sums(n,0);
        sums[0] = nums[0];
            for(i=1; i<n; i++)
                sums[i] = sums[i-1] + nums[i];
        return mergesort(sums, 0, n-1, lower, upper);
    }
};