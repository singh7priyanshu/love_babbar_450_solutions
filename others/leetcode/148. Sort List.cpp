/*
148. Sort List

Given the head of a linked list, return the list after sorting it in ascending order.

Example 1:

4--->2-->1--3
       |
1---2---3---4


Input: head = [4,2,1,3]
Output: [1,2,3,4]


Example 2:

(-1)---5---3---4---0
          |
(-1)---0----3---4---5


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105

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
    ListNode* sortList(ListNode* head) {
        //If List Contain a Single or 0 Node
        if(head == NULL || head ->next == NULL)
            return head;
        ListNode *temp = NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        // 2 pointer appraoach / turtle-hare Algorithm (Finding the middle element)
        while(fast !=  NULL && fast -> next != NULL){
            temp = slow;
            slow = slow->next;          //slow increment by 1
            fast = fast ->next ->next;  //fast incremented by 2
        }   
        temp -> next = NULL;            //end of first left half
        ListNode* l1 = sortList(head);    //left half recursive call
        ListNode* l2 = sortList(slow);    //right half recursive call
        
        return mergelist(l1, l2);         //mergelist Function call        
    } 
    //MergeSort Function O(n*logn)
    ListNode* mergelist(ListNode *l1, ListNode *l2){
        ListNode *ptr = new ListNode(0);
        ListNode *curr = ptr;
        while(l1 != NULL && l2 != NULL){
            if(l1->val <= l2->val){
                curr -> next = l1;
                l1 = l1 -> next;
            }
            else{
                curr -> next = l2;
                l2 = l2 -> next;
            }
        curr = curr ->next;
        }
        //for unqual length linked list
        if(l1 != NULL){
            curr -> next = l1;
            l1 = l1->next;
        }
        if(l2 != NULL){
            curr -> next = l2;
            l2 = l2 ->next;
        }
        return ptr->next;
    }
};

/*
In order to detect cycles in any given singly linked list, we must set two pointers 
that traverse the data structure at different speeds. If they meet, we can determine 
that the list was circular. Then if we set the first pointer back to the head and slow 
them both down to the same speed, the next time they will meet will be the point where 
the node started pointing backward. The pseudo-code is as follows:

1. Initialize two pointers (tortoise and hare) that both point to the head of the linked list
2. Loop as long as the hare does not reach null
3. Set tortoise to next node
4. Set hare to next, next node
5. If they are at the same node, reset the tortoise back to the head.
6. Have both tortoise and hare both move one node at a time until they meet again
7. Return the node in which they meet
8. Else, if the hare reaches null, then return null

Big O
The time complexity of this algorithm is linear: O(n).
The space complexity of this algorithm is constant: O(1).
*/
