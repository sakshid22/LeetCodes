//167

class Solution {
public:
 
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        unordered_map <int,int> map;
            for(int i=numbers.size()-1 ; i>=0; i--)
            {
                if(map.find(target - numbers[i]) != map.end())
                {
                    return { i+1, map[target - numbers[i]] + 1 };
                }
                map[numbers[i]] =i;
            }
        return {};
    }
    
    
    
    /*
    
    vector<int> twoSum(vector<int>& numbers, int target) {
     
        int l=0;
        int r= numbers.size() -1;
        while(l<r)
        {
            if(numbers[l] + numbers[r] == target)
            {
               break;
            }
            else if (numbers[l] + numbers[r] >target)
                r--;
            else
                r++;
        }
        return vector<int>({l+1,r+1});
    }
    
    */
};