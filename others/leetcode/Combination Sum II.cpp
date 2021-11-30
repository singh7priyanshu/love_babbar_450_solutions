/*
Combination Sum II

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30

*/

class Solution {
    public:
        int m, sum = 0;
        vector<int>arr;
        vector<int>t;
        vector<vector<int>> x;

void ql(int j){
    for (int i = j; i < arr.size(); i++){
        if (i > j && arr[i] == arr[i - 1])
            continue;

        int c = arr[i];
        t.push_back(c);
        sum += c;
        if (sum >= m){
            if (sum == m)
                x.push_back(t);
            t.pop_back();
            sum -= c;
            break;
        }
        else ql(i + 1);

        t.pop_back();
        sum -= c;
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target){
    arr = candidates;
    m = target;
    sort(arr.begin(), arr.end());
    ql(0);
    return x;
    }
};

