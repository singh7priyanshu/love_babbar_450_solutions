/*
Swap Nodes in Pairs

Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

 

Example 1:

1->2->3->4
    |
2->1->4->3

Input: head = [1,2,3,4]
Output: [2,1,4,3]
Example 2:

Input: head = []
Output: []
Example 3:

Input: head = [1]
Output: [1]
 

Constraints:

The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100

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
class Solution  {
public:
  ListNode* swapPairs(ListNode* head)  {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* cur = head;
    ListNode* pre = dummy;
    while(cur && cur->next) {
      ListNode* t = cur->next->next;
      pre->next = cur->next;
      cur->next->next = cur;
      cur->next = t;
      pre = cur;
      cur = t;
    }
    return dummy->next;
  }
};

