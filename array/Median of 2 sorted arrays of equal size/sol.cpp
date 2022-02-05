/*
Median of 2 sorted arrays of equal size

Given an array arr[] of N integers, calculate the median
 

Example 1:

Input: N = 5
arr[] = 90 100 78 89 67
Output: 89
Explanation: After sorting the array 
middle element is the median 

Example 2:

Input: N = 4
arr[] = 56 67 30 79
Output: 61
Explanation: In case of even number of 
elements, average of two middle elements 
is the median.

 

Your Task:
You don't need to read or print anything. Your task is to complete the function 
find_median() which takes the array as input parameter and returns the floor value of the median.
 

Expected Time Complexity: O(n * log(n))
Expected Space Complexity: O(1)
 

Constraints:
1 <= Length of Array <= 100
1 <= Elements of Array <= 100

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int find_median(vector<int> v){
	    sort(v.begin(),v.end());
	    int ans = 0;
	    if(v.size() & 1)ans = v[v.size()/2];
	    else ans = (v[v.size()/2] + v[v.size()/2 - 1])/2;
	    return ans;
	}
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i = 0;i<n;i++)cin>>v[i];
        Solution ob;
        int ans = ob.find_median(v);    
        cout<<ans<<endl;
    }
    return 0;
}