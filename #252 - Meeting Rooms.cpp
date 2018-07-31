//252

class Solution
{
public:
	bool CanAttendMeetings (vector <interval> &intervals )
	{
	sort(intervals.begin(), intervals.end(),);
		for(int i=0; i<intervals.size()-1; i++)
		{
			if(overalp(interval[i], intervals[i++])  )
				return false;
		}
	return true;
	
	}
private:
	bool overlap(interval &interval1 , interval &interval2)
	{
	return interval1.end > interval2.start ;
	}

};