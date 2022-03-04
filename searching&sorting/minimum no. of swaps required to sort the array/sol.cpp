/*
minimum no. of swaps required to sort the array

Given an array of n distinct elements. Find the minimum number of swaps 
required to sort the array in strictly increasing order.


Example 1:

Input:
nums = {2, 8, 5, 4}
Output:
1
Explaination:
swap 8 with 4.
Example 2:

Input:
nums = {10, 19, 6, 3, 5}
Output:
2
Explaination:
swap 10 with 3 and swap 19 with 5.

Your Task:
You do not need to read input or print anything. Your task is to complete the 
function minSwaps() which takes the nums as input parameter and returns an integer 
denoting the minimum number of swaps required to sort the array. If the array is 
already sorted, return 0. 


Expected Time Complexity: O(nlogn)
Expected Auxiliary Space: O(n)


Constraints:
1 ≤ n ≤ 105
1 ≤ numsi ≤ 106

*/

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
	int minSwaps(vector<int>&nums){
	    int n = nums.size();
	    vector<pair<int, int>>cur(n);
	    for(int i = 0;i<n;i++){
	        cur[i].first = nums[i];
	        cur[i].second = i;
	    }
	    sort(cur.begin(), cur.end());
	    vector<bool>vis(n, false);
	    int ans = 0;
	    for(int i = 0;i<n;i++){
	        if(vis[i] || cur[i].second == i)continue;
	        int cycle_size = 0;
	        int j = i;
	        while(!vis[j]){
	            vis[j] = true;
	            j = cur[j].second;
	            cycle_size++;
	        }
	        ans += (cycle_size>1)? cycle_size-1 : 0;
	    }
	    return ans;
	}
};

int main(){
    int tc; cin>>tc;
    while(tc--){
        int n; cin>>n;
        vector<int>nums(n);
        for(int i = 0;i<n;i++)cin>>nums[i];
        Solution ob;
        int ans = ob.minSwaps(nums);
        cout<<ans<<endl;
    }
    return 0;
}

/*
// C++ program to demonstrate sorting in
// vector of pair according to 1st element
// of pair
#include<bits/stdc++.h>
using namespace std;

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){
    return (a.second < b.second);
}
  
int main(){
	vector< pair <int,int> > vect;
	int arr[] = {10, 20, 5, 40 };
	int arr1[] = {30, 60, 20, 50};
	int n = sizeof(arr)/sizeof(arr[0]);
	for (int i=0; i<n; i++)vect.push_back( make_pair(arr[i],arr1[i]) );
	cout << "The vector before sort operation is:\n" ;
	for (int i=0; i<n; i++)cout << vect[i].first << " "<< vect[i].second << endl;
		OUTPUT
		The vector before applying sort operation is:
			10 30
			20 60
			5 20
			40 50
	sort(vect.begin(), vect.end());
	cout << "The vector after sort operation is:\n" ;
	for (int i=0; i<n; i++)cout << vect[i].first << " "<< vect[i].second << endl;
		OUTPUT
		The vector after applying sort operation is:
			5 20
			10 30
			20 60	
			40 50
	sort(vect.begin(), vect.end(), sortbysec);
	cout << "The vector after sort operation is:\n" ;
    	for (int i=0; i<n; i++)cout << vect[i].first << " "<< vect[i].second << endl;
    		OUTPUT
		The vector after applying sort operation is:
			5 20
			10 30
			40 50	
			20 60
	return 0;
}
