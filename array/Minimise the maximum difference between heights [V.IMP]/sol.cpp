/*
Minimize the Heights II
Given an array arr[] denoting heights of N towers and a positive integer K, you have to modify the height of each tower either by increasing or decreasing them by K only once. After modifying, height should be a non-negative integer. 
Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower.

A slight modification of the problem can be found here.


Example 1:

Input:
K = 2, N = 4
Arr[] = {1, 5, 8, 10}
Output:
5
Explanation:
The array can be modified as 
{3, 3, 6, 8}. The difference between 
the largest and the smallest is 8-3 = 5.

*/

	#include<bits/stdc++.h>
	using namespace std;

	class Solution {
  		public:
   	 		int getMinDiff(int arr[], int n, int k) {
        			// code here
        			vector<pair<int, int>> v;
        			vector<int> taken(n);

        			// we will store all possible heights in a vector
        			for (int i = 0; i < n; i++) {
            				if (arr[i] - k >= 0) {
                				v.push_back({arr[i] - k, i});
            				}
           	 			v.push_back({arr[i] + k, i});
        			}
        			sort(v.begin(), v.end());
        			int elements_in_range = 0;
        			int left = 0;
        			int right = 0;

        			// By two pointer we will traverse v and whenever we will get a range
        			// in which all towers are included, we will update the answer.
        			while (elements_in_range < n && right < v.size()) {
            				if (taken[v[right].second] == 0) {
                				elements_in_range++;
            				}
            				taken[v[right].second]++;
            				right++;
        			}
        			int ans = v[right - 1].first - v[left].first;
        			while (right < v.size()) {
            				if (taken[v[left].second] == 1) {
                				elements_in_range--;
            				}
            				taken[v[left].second]--;
            				left++;

            				while (elements_in_range < n && right < v.size()) {
                				if (taken[v[right].second] == 0) {
                    					elements_in_range++;
                				}
                				taken[v[right].second]++;
                				right++;
            				}

            				if (elements_in_range == n) {
                				ans = min(ans, v[right - 1].first - v[left].first);
            				} else {
                				break;
            				}
        			}
        			return ans;
    			}
	};

	int main(){
    		int t;
    		cin>>t;
    		while(t--){
        		int n,k;
        		cin>>k>>n;
        		int arr[n];
        		for(int i=0; i<n; i++){
            			cin>>arr[i];
        		}
        		Solution ob;
        		auto ans = ob.getMinDiff(arr, n, k);
        		cout<<ans<<endl;
    		}
    		return 0;
	}