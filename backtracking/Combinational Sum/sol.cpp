/*
Combinational Sum

Given an array of integers and a sum B, find all unique 
combinations in the array where the sum is equal to B. 
The same number may be chosen from the array any number 
of times to make B.

Note:
        1. All numbers will be positive integers.
        2. Elements in a combination (a1, a2, …, ak) must 
            be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
        3. The combinations themselves must be sorted in ascending order.


Example 1:

Input:
N = 4
arr[] = {7,2,6,5}
B = 16
Output:
(2 2 2 2 2 2 2 2)
(2 2 2 2 2 6)
(2 2 2 5 5)
(2 2 5 7)
(2 2 6 6)
(2 7 7)
(5 5 6)
Example 2:

Input:
N = 11
arr[] = {6,5,7,1,8,2,9,9,7,7,9}
B = 6
Output:
(1 1 1 1 1 1)
(1 1 1 1 2)
(1 1 2 2)
(1 5)
(2 2 2)
(6)

Your Task:
Your task is to complete the function combinationSum() 
which takes the array A and a sum B as inputs and 
returns a list of list denoting the required combinations 
in the order specified in the problem description. 
The printing is done by the driver's code. If no set can 
be formed with the given set, then  "Empty" (without quotes) is printed.


Expected Time Complexity: O(X2 * 2N), where X is average 
of summation B/arri for every number in the array.
Expected Auxiliary Space: O(X * 2N)


Constraints:
1 <= N <= 30
1 <= A[i] <= 20
1 <= B <= 10
*/

#include<bits/stdc++.h>
using namespace std;

class Solution  {
  public:
    void combinationSumUtil(vector<int> &A, int sum, 
        vector<vector<int>>&result, vector<int>current, int pos){
        if(sum==0){ 
            result.push_back(current);
            return;
        }
        if(sum<0 || pos>=A.size()) return; 
        current.push_back(A[pos]); 
        combinationSumUtil(A, sum-A[pos], result,  current, pos );
        current.pop_back(); 
        combinationSumUtil(A, sum, result,  current, pos+1 ); 
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B){
        sort(A.begin(),A.end());
        vector<vector<int> > result;
        vector<int> current, C;
        int i,j;
        for(i=0;i<A.size();i++){
            j=i+1;
            while(j<A.size()&&A[i]==A[j])j++;
            C.push_back(A[i]);
            i=j-1;
        }
        combinationSumUtil(C, B, result, current,0);
        return result;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>A;
        for(int i = 0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>>result = ob.combinationSum(A, sum);
        if(result.size() == 0)cout<<"Empty";
        for(int i = 0;i<result.size();i++){
            cout<<'(';
            for(int j = 0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)cout<<" ";
            }
            cout<<")";
        }
        cout<<endl;
    }
}