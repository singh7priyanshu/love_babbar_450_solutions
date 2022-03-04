/*
Job Scheduling Algo

Given N jobs where every job is represented by following three elements of it.

Start Time
Finish Time
Profit or Value Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
Example: 

Input: Number of Jobs n = 4
       Job Details {Start Time, Finish Time, Profit}
       Job 1:  {1, 2, 50} 
       Job 2:  {3, 5, 20}
       Job 3:  {6, 19, 100}
       Job 4:  {2, 100, 200}
Output: The maximum profit is 250.
We can get the maximum profit by scheduling jobs 1 and 4.
Note that there is longer schedules possible Jobs 1, 2 and 3 
but the profit with this schedule is 20+50+100 which is less than 250.  

The above problem can be solved using following recursive solution. 
 

1) First sort jobs according to finish time.
2) Now apply following recursive process. 
   // Here arr[] is array of n jobs
   findMaximumProfit(arr[], n)
   {
     a) if (n == 1) return arr[0];
     b) Return the maximum of following two profits.
         (i) Maximum profit by excluding current job, i.e., 
             findMaximumProfit(arr, n-1)
         (ii) Maximum profit by including the current job            
   }

How to find the profit including current job?
The idea is to find the latest job before the current job (in 
sorted array) that doesn't conflict with current job 'arr[n-1]'. 
Once we find such a job, we recur for all jobs till that job and
add profit of current job to result.
In the above example, "job 1" is the latest non-conflicting
for "job 4" and "job 2" is the latest non-conflicting for "job 3".

The implementations discussed in above post uses linear search to find 
the previous non-conflicting job. In this post, Binary Search based 
solution is discussed. The time complexity of Binary Search based 
solution is O(n Log n).
The algorithm is: 
 

Sort the jobs by non-decreasing finish times.
For each i from 1 to n, determine the maximum value of the schedule 
from the subsequence of jobs[0..i].
Do this by comparing the inclusion of job[i] to the schedule to 
the exclusion of job[i] to the schedule, and then taking the max.

To find the profit with inclusion of job[i]. we need to find the 
latest job that doesn’t conflict with job[i]. 
The idea is to use Binary Search to find the latest non-conflicting job.
 
*/

// C++ program for weighted job scheduling using Dynamic 
// Programming and Binary Search
#include <iostream>
#include <algorithm>
using namespace std;
   
// A job has start time, finish time and profit.
struct Job
{
    int start, finish, profit;
};
   
// A utility function that is used for sorting events
// according to finish time
bool myfunction(Job s1, Job s2)
{
    return (s1.finish < s2.finish);
}
   
// A Binary Search based function to find the latest job
// (before current job) that doesn't conflict with current
// job.  "index" is index of the current job.  This function
// returns -1 if all jobs before index conflict with it.
// The array jobs[] is sorted in increasing order of finish
// time.
int binarySearch(Job jobs[], int index)
{
    // Initialize 'lo' and 'hi' for Binary Search
    int lo = 0, hi = index - 1;
   
    // Perform binary Search iteratively
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (jobs[mid].finish <= jobs[index].start)
        {
            if (jobs[mid + 1].finish <= jobs[index].start)
                lo = mid + 1;
            else
                return mid;
        }
        else
            hi = mid - 1;
    }
   
    return -1;
}
   
// The main function that returns the maximum possible
// profit from given array of jobs
int findMaxProfit(Job arr[], int n)
{
    // Sort jobs according to finish time
    sort(arr, arr+n, myfunction);
   
    // Create an array to store solutions of subproblems.  table[i]
    // stores the profit for jobs till arr[i] (including arr[i])
    int *table = new int[n];
    table[0] = arr[0].profit;
   
    // Fill entries in table[] using recursive property
    for (int i=1; i<n; i++)
    {
        // Find profit including the current job
        int inclProf = arr[i].profit;
        int l = binarySearch(arr, i);
        if (l != -1)
            inclProf += table[l];
   
        // Store maximum of including and excluding
        table[i] = max(inclProf, table[i-1]);
    }
   
    // Store result and free dynamic memory allocated for table[]
    int result = table[n-1];
    delete[] table;
    
    return result;
}
   
// Driver program
int main()
{
    Job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Optimal profit is " << findMaxProfit(arr, n);
    return 0;
}

/*
Output:

Optimal profit is 250

*/