/*
347. Top K Frequent Elements

Given an integer array nums and an integer k, 
return the k most frequent elements. You may 
return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
 

Follow up: Your algorithm's time complexity must be better 
than O(n log n), where n is the array's size.
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for(int x : nums)freqMap[x]++;
        auto comp = [&freqMap](auto& lhs, auto&rhs) {
              return freqMap[lhs] > freqMap[rhs];
        };
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        /*
        First define the lambda object, then pass it to the 
        template's type using decltype and also pass it directly 
        to the constructor.

auto comp = []( adjist a, adjlist b ) { return a.second > b.second; };
priority_queue< adjlist_edge , vector<adjlist_edge>, decltype( comp ) >
     adjlist_pq( comp );
     */
        for(auto& thing : freqMap) {
            pq.push(thing.first);
            if(pq.size() > k)pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};