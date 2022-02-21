/*
1288. Remove Covered Intervals

Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), 
remove all intervals that are covered by another interval in the list.

The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.

Return the number of remaining intervals.

 

Example 1:

Input: intervals = [[1,4],[3,6],[2,8]]
Output: 2
Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.
Example 2:

Input: intervals = [[1,4],[2,3]]
Output: 1
 

Constraints:

1 <= intervals.length <= 1000
intervals[i].length == 2
0 <= li <= ri <= 105
All the given intervals are unique.

*/

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // sorting the intervals(vector)
        sort(intervals.begin(),intervals.end());        
        int x1 = intervals[0][0];
        int x2 = intervals[0][1];
		 int res = 1;  //one for x1 and x2;
		// ifa[i][0] && a[i][1] both greater than a[i-1][0] && a[i-1][1]
		// increase the cnt.
        for(int i= 1; i<intervals.size(); ++i){
            if(intervals[i][0] > x1 && intervals[i][1] > x2)res++;
    		// updating x1 & x2 with next intervals
			//as we are comparing from upcoming ones.
            if(intervals[i][1] > x2){
                x1 = intervals[i][0];
                x2 = intervals [i][1];
            }
        }
        return res;
    }
}; 