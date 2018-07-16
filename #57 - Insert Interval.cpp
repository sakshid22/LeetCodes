//57

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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
       
    
vector<Interval> res;
int n =intervals.size();
    for(int i=0; i<n;i++)
    {
        if(intervals[i].end < newInterval.start)
        res.push_back(intervals[i]);
        else
        if( newInterval.end< intervals[i].start)
        {
        res.push_back(newInterval);
            for(int j=i;j<n;j++)
            res.push_back(intervals[j]);
        return res;
        }
        else
        newInterval = Merge(intervals[i], newInterval);
    }
res.push_back(newInterval);
return res;
}

private:
Interval Merge(Interval &interval1, Interval &interval2 )
{
int start = min(interval1.start, interval2.start);
int end = max(interval1.end, interval2.end);
return Interval(start, end);      
}

};
	