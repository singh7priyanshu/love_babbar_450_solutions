/*
Merge Intervals

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104

*/

function merge(intervals) {
    if (!intervals.length) return intervals
    intervals.sort((a, b) => a[0] !== b[0] ? a[0] - b[0] : a[1] - b[1])
    var prev = intervals[0]
    var res = [prev]
    for (var curr of intervals) {
      if (curr[0] <= prev[1]) {
        prev[1] = Math.max(prev[1], curr[1])
      } else {
        res.push(curr)
        prev = curr
      }
    }
    return res
  }
