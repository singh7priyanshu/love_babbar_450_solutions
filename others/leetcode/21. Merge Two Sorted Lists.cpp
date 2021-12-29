/*
21. Merge Two Sorted Lists

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.

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
    ListNode * insert(ListNode * head, int val){
        if(head == nullptr)return new ListNode(val);
        else{
            head -> next = insert(head->next,val);
            return head;
        }
    }
    int listSize(ListNode* head){
        if(!head)return 0;
        else return listSize(head->next)+1;
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = nullptr;
        int l1s = listSize(list1);
        int l2s = listSize(list2);
        while (l1s > 0 && l2s > 0){
            int v1 = list1 -> val;
            int v2 = list2 -> val;
            if(v1<=v2){
                l1s--;
                head  = insert(head,v1);
                list1 = list1 -> next;
            }else{
                l2s--;
                head = insert(head,v2);
                list2 = list2 -> next;
            }
        }
        while(l1s>0){
            int val1 = list1 -> val;
            l1s--;
            head = insert(head,val1);
            list1 = list1 -> next;
        }
        while(l2s>0){
            int val2 = list2 -> val;
            l2s--;
            head = insert(head,val2);
            list2 = list2 -> next;
        }
        return head;          
    }
};