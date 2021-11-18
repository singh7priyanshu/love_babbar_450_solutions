"""
Activity Selection Problem

N meetings in one room

There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) 
where start[i] is start time of meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when 
only one meeting can be held in the meeting room at a particular time?

Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.


Example 1:

Input:
N = 6
start[] = {1,3,0,5,8,5}
end[] =  {2,4,6,7,9,9}
Output: 
4
Explanation:
Maximum four meetings can be held with
given start and end timings.
The meetings are - (1, 2),(3, 4), (5,7) and (8,9)
Example 2:

Input:
N = 3
start[] = {10, 12, 20}
end[] = {20, 25, 30}
Output: 
1
Explanation:
Only one meetings can be held
with given start and end timings.

Your Task :
You don't need to read inputs or print anything. Complete the function maxMeetings() that 
takes two arrays start[] and end[] along with their size N as input parameters and returns 
the maximum number of meetings that can be held in the meeting room.


Expected Time Complexity : O(N*LogN)
Expected Auxilliary Space : O(N)


Constraints:
1 ≤ N ≤ 105
0 ≤ start[i] < end[i] ≤ 105
"""


from functools import cmp_to_key

class Solution:  
    
    #comparator function used in sorting the list of pairs 
    #according to increasing order of the finish time.
    def compare(self,a,b) :
        if a[0][1]!=b[0][1] :
            return a[0][1]-b[0][1]
        
        return a[1]-b[1]
    
    
    #Function to find the maximum number of meetings that can
    #be performed in a meeting room.
    def maximumMeetings(self,n,start,end):
        
        x = []
        
        #pushing the pair of starting and finish time and their 
        #index as pair in another list.
        for i in range(n):
            x.append([[start[i],end[i]],i+1])
        
        #sorting the list.
        x = sorted(x, key=cmp_to_key(self.compare))
        last = 0
        res = 0
        
        for i in range(n) :
            
            #if the start time of this meeting is greater than or equal
            #to the finish time of previously selected meeting then 
            #we increment the counter and update last.
            if x[i][0][0] > last :
                res += 1
                last = x[i][0][1]
        
        #returning the counter.
        return res


import atexit
import io 
import sys

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        n=int(input())
        start=list(map(int,input().strip().split()))
        end=list(map(int,input().strip().split()))
        ob=Solution()
        print(ob.maximumMeetings(n,start,end))
        
