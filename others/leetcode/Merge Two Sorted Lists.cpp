/*
Merge Two Sorted Lists

Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.

 

Example 1:


Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: l1 = [], l2 = []
Output: []
Example 3:

Input: l1 = [], l2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both l1 and l2 are sorted in non-decreasing order.


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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *r = new ListNode(0);
        ListNode *t1 = l1;
        ListNode *t2 = l2;
        ListNode *result = r;
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        while(t1!=NULL && t2!=NULL){
            if(t1->val<=t2->val) {
                result->next = t1;
                t1 = t1->next;
                result = result->next;
                }
            
            else{
                result->next = t2;
                t2 = t2->next;
                result = result->next;
            } 
        }
		//below loops to check if any element remains in either of the list
        while(t2!=NULL){
            result->next = t2;
            t2 = t2->next;
            result = result->next;
        }
        while(t1!=NULL){
            result->next = t1;
            t1 = t1->next;
            result = result->next;
        }

        return r->next;
    }
};
