//282

class Solution {
public:
    
    void addOperators(vector<string>& result, string nums, string t, long long last, long long curval, int target )
    {
        if(nums.length() ==0)
        {
            if(curval == target)
                result.push_back(t);
            return;
        }
        
        for(int i=1; i<=nums.length(); i++)
        {
            
            string num = nums.substr(0,i);
            if(num.length() > 1 && num[0] =='0')
                return;
            
            string nextnum = nums.substr(i);
            
            if(t.length() >0)
            {
                addOperators(result, nextnum, t + "+" + num, stoll(num), curval + stoll(num), target);
                addOperators(result, nextnum, t + "-" + num, -stoll(num), curval - stoll(num), target);
                addOperators(result, nextnum, t + "*" + num, last * stoll(num), (curval-last) + (last * stoll(num)), target );
            }
            else
                addOperators(result, nextnum, num, stoll(num), stoll(num), target);
        }
    }
    
    vector<string> addOperators(string num, int target) {
    
        vector<string> result;
        addOperators(result, num, "", 0, 0, target);
        return result;
        
    }
};