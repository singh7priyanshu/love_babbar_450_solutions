/*
740. Delete and Earn

You are given an integer array nums. You want to maximize 
the number of points you get by performing the following 
operation any number of times:

Pick any nums[i] and delete it to earn nums[i] points. 
Afterwards, you must delete every element equal to nums[i] - 1 and 
every element equal to nums[i] + 1.
Return the maximum number of points you can earn by applying 
the above operation some number of times.

 

Example 1:

Input: nums = [3,4,2]
Output: 6
Explanation: You can perform the following operations:
- Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2].
- Delete 2 to earn 2 points. nums = [].
You earn a total of 6 points.

Example 2:

Input: nums = [2,2,3,3,3,4]
Output: 9
Explanation: You can perform the following operations:
- Delete a 3 to earn 3 points. All 2's and 4's are also deleted. nums = [3,3].
- Delete a 3 again to earn 3 points. nums = [3].
- Delete a 3 once more to earn 3 points. nums = [].
You earn a total of 9 points.
 

Constraints:

1 <= nums.length <= 2 * 104
1 <= nums[i] <= 104

*/

class Solution {
public:
    int t[20001];
    int solve(vector<int> &arr, int i){
        if(i >= arr.size())return 0;
        if(t[i] != -1)return t[i];
        int currValue = arr[i];  
        int currSum = arr[i]; 
        int index = i + 1; 
        while(index < arr.size() && arr[index] == currValue){
            currSum += arr[i];
            index++;
        }
        while(index < arr.size() && arr[index] == currValue + 1)index++;
        return t[i] = max(currSum + solve(arr, index), solve(arr, i + 1));
    }
    int deleteAndEarn(vector<int>& arr) {
        int n = arr.size(); 
        memset(t, -1, sizeof(t));
        sort(arr.begin(), arr.end());
        return solve(arr, 0);
    }
};