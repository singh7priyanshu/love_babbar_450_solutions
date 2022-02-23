/*
find majority element

Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.
 

Example 1:

Input:
N = 3 
A[] = {1,2,3} 
Output:
-1
Explanation:
Since, each element in 
{1,2,3} appears only once so there 
is no majority element.
Example 2:

Input:
N = 5 
A[] = {3,1,3,3,2} 
Output:
3
Explanation:
Since, 3 is present more
than N/2 times, so it is 
the majority element.

Your Task:
The task is to complete the function majorityElement() which returns the majority element in the array. If no majority exists, return -1.
 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).
 

Constraints:
1 ≤ N ≤ 107
0 ≤ Ai ≤ 106

*/

#include<bits/stdc++.h>
using namespace std;


class Solution{
  public:
    int majorityElement(int a[], int size){
        int cand = findCandidate(a, size);
        if(isMajority(a, size, cand))return cand;
        else return -1;
    }
    
    bool isMajority(int a[], int size, int cand){
        int count = 0;
        for(int i = 0;i<size;i++){
            if(a[i]==cand)count++;
        }
        if(count>size/2)return 1;
        else return 0;
    }
    
    int findCandidate(int a[], int size){
        int maj_index = 0, count = 1;
        for(int i = 0;i<size;i++){
            if(a[maj_index]==a[i])count++;
            else count--;
            if(count == 0){
                maj_index = i;
                count = 1;
            }
        }
        return a[maj_index];
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        for(int i = 0;i<n;i++)cin>>arr[i];
        Solution ob;
        cout<<ob.majorityElement(arr, n)<<endl;
    }
    return 0;
}