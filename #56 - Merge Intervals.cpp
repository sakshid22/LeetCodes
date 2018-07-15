//56

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {


    
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        
        vector<Interval> res;
        if(intervals.empty())
            return res;
        sort(intervals.begin(), intervals.end(),comp);
        Interval cur(intervals[0].start, intervals[0].end);
        for(int i=1, n=intervals.size(); i<n;i++)
        {
            if(isOverlap(cur,intervals[i]))
                cur = MergeTwo(cur,intervals[i]);
            else
            { res.push_back(cur);
                cur = intervals[i];
             }
        
        }
    res.push_back(cur);
    return res;
    }
    
    private:
    static bool comp( Interval  interval1, Interval interval2)
    {  if (interval1.start < interval2.start)           //cant directly return the values, error 'named return values no longer supported
            return 1;
     else return 0;
    }
    
    bool isOverlap( Interval interval1, Interval interval2)
    {    if( interval1.end >= interval2.start)
            return 1;
        else return 0;
    }    
    
    Interval MergeTwo(Interval interval1, Interval interval2)
    {
        int end = max(interval1.end, interval2.end);
            return Interval(interval1.start, end);
    }

};