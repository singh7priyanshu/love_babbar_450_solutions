/*
Find the Duplicate Number
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.

Let's take an example where the array is not ordered, the duplicate is repeated more than once. E.g., the array a = [ 2, 7, 4, 5, 1, 6, 4, 3, 8, 4 ].
Since we could use O(1) extra space, the indices of the array becomes more important for us. Given the indices, this problem becomes finding the indices which are targeting the same value. Note that, the indices are from 0 to n, and the values are from 1 to n. We could consider both the indices and values are nodes in one linked list, and the array (or the index-value pair) represents the connections between the nodes. Thus the array can be converted into a linked list.

Given the linked list, it is not hard to notice that, the duplicates value in array now becomes a loop in the linked list. So, to find if there is a loop (and also the circle strat node), we could use slow and fast pointers which we have seen before:

Loop detection: If the fast pointer catch up the slow pointer at the same node, there must be a loop.
Find the loop start node: The distance from head node to the loop start node, and the distance from catchup node to the loop start node, are the same.
So, the last question is how to determine the start point of the linked list. We could use the 1st element, since the index of 1st element in array is always 0, and there is no 0 in the value (it starts from 1). So it is impossible that 1st is in the loop.

*/

	class Solution {
	public:
    		int findDuplicate(vector<int>& nums) {
        		if (nums.size() > 1){
              			int slow = nums[0];
              			int fast = nums[nums[0]];
              			while (slow != fast){
                  			slow = nums[slow];
                  			fast = nums[nums[fast]];
              			}

            		fast = 0;
            		while (fast != slow){
                  		fast = nums[fast];
                  		slow = nums[slow];
            		}
            		return slow;
        	}
        	return -1;
	};