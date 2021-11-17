/*
Reverse Nodes in k-Group
 
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
Example 3:

Input: head = [1,2,3,4,5], k = 1
Output: [1,2,3,4,5]
Example 4:

Input: head = [1], k = 1
Output: [1]
 

Constraints:

The number of nodes in the list is in the range sz.
1 <= sz <= 5000
0 <= Node.val <= 100
1 <= k <= sz

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *current = head, *prev = NULL, *next = NULL, *tempcurr, *tempprev;
        
        // reverse k nodes
        int count = 0;
        while(current != NULL && count < k) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }
        
        // when k > the count of the remaining nodes 
        // then don't reverse the remaining nodes
        // but the above loop has already reversed it
        // so we will reverse that part again to
        // retain its original order
        if(k > count) {
            tempcurr = prev;
            tempprev = NULL;
            
            while(tempcurr != NULL) {
                next = tempcurr->next;
                tempcurr->next = tempprev;
                tempprev = tempcurr;
                tempcurr = next;
            }
            
            // tempprev is the head here
            return tempprev;
        }
        
        if(current != NULL) {
            head->next = reverseKGroup(current, k);
        }
        
        return prev;
    }
};

// Time complexity: O(N)
// Space complexity: O(1)