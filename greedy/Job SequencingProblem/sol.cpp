/*
Job SequencingProblem

Given a set of N jobs where each jobi has a 
deadline and profit associated with it.

Each job takes 1 unit of time to complete and only 
one job can be scheduled at a time. We earn the profit 
associated with job if and only if the job is completed 
by its deadline.

Find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) 
associated with that Job.


Example 1:

Input:
N = 4
Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output:
2 60
Explanation:
Job1 and Job3 can be done with
maximum profit of 60 (20+40).
Example 2:

Input:
N = 5
Jobs = {(1,2,100),(2,1,19),(3,2,27),
        (4,1,25),(5,1,15)}
Output:
2 127
Explanation:
2 jobs can be done with
maximum profit of 127 (100+27).

Your Task :
You don't need to read input or print anything. 
Your task is to complete the function JobScheduling() 
which takes an integer N and an array of 
Jobs(Job id, Deadline, Profit) as input and returns the 
count of jobs and maximum profit.


Expected Time Complexity: O(NlogN)
Expected Auxilliary Space: O(N)


Constraints:
1 <= N <= 105
1 <= Deadline <= 100
1 <= Profit <= 500
*/

#include<bits/stdc++.h>
using namespace std;

struct Job{
    int id, dead, profit;
};


class Solution {
    public:
    static bool comparison(Job a, Job b) { 
        return (a.profit > b.profit); 
    } 

    vector<int> JobScheduling(Job arr[], int n){ 
        int res = 0, count = 0;
        sort(arr, arr+n, comparison); 
        int result[n];
        bool slot[n]; 
        for (int i=0; i<n; i++)slot[i] = false;  
        for (int i=0; i<n; i++){ 
            for (int j=min(n, arr[i].dead)-1; j>=0; j--) { 
                if (slot[j]==false){ 
                    result[j] = i;  
                    slot[j] = true; 
                    break; 
                } 
            } 
        } 
        for (int i=0; i<n; i++){ 
            if (slot[i]){
                count++;
                res += arr[result[i]].profit;
            }
        }
        vector<int> ans;
        ans.push_back(count);
        ans.push_back(res);
        return ans; 
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        Job arr[n];
        for(int i = 0;i<n;i++){
            int x, y, z; cin>>x>>y>>z;
            arr[i].id = x;
            arr[i].dead  = y;
            arr[i].profit = z;
        }
        Solution ob;
        vector<int>ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}