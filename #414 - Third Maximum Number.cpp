/414

class Solution {
public:

    
    int thirdMax(vector<int>& nums) {
     
        long long a,b,c ;
        a=b=c= LLONG_MIN;
        for(auto num:nums)
        {
            if(num<=c || num ==b || num==a)
                continue;
            c=num;
            if(c>b) swap(b,c);
            if(b>a) swap(a,b);
            
        }
        return c == LLONG_MIN ? a:c ;
    }
    
    /*
    
    int thirdMax(vector <int> &nums)
    {
        int first = INT_MIN, second = INT_MIN, third = INT_MIN;
        unordered_set <int> dict;
        for(int i: nums)
        {
            dict.insert(i);
            if(i==first || i==second || i==third)
                continue;
            if(i>first)
            {
                third = second;
                second = first;
                first=i;
            }
            else if(i>second)
            {
                third = second;
                second =i;
            }
            else if(i>=third)
            {
                third =i;
            }
        }
        return dict.size() >= 3?third:first;        
    }
    
    */
};