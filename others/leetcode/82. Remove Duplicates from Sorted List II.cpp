/*
82. Remove Duplicates from Sorted List II

Given the head of a sorted linked list, delete all nodes that have 
duplicate numbers, leaving only distinct numbers from the original 
list. Return the linked list sorted as well.

 

Example 1:

(1)------->(2)------->(3)-------->(3)--------(4)------->(4)-------->(5)
                                ||
                    (1)--------->(2)-------->(5)

Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]


Example 2:

(1)-------->(1)---------->(1)--------->(2)------------>(3)
                            ||
                    (2)----------->(3)


Input: head = [1,1,1,2,3]
Output: [2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)return 0;
        if(!head -> next)return head;
        int val = head ->val;
        ListNode *temp = head -> next;
        if(temp -> val != val){
            head -> next = deleteDuplicates(temp);
            return head;
        }
        else{
           while(temp && temp -> val == val){
                ListNode *p = temp;
                temp = temp->next;
                delete p;
            }
            return deleteDuplicates(temp);
        }
    }
};