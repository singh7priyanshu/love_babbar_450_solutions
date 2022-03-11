/*
61. Rotate List

Given the head of a linked list, rotate the list to the 
right by k places.

          (1)------->(2)------>(3)----->(4)-------->(5)
 rotate 1 (5)------->(1)------>(2)----->(3)-------->(4)
 rotate 1 (4)------->(5)------>(1)----->(2)-------->(3)

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]


Example 2:

            (0)------>(1)------->(2)
 rotate 1   (2)------>(0)------->(1)
 rotate 2   (1)------>(2)------->(0)
 rotate 3   (0)------>(1)------->(2)
 rotate 4   (2)------>(0)------->(1)
 


Input: head = [0,1,2], k = 4
Output: [2,0,1]
 

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109
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
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;
        ListNode *temp = head;
        while(temp){
            n++;
            if(!temp->next) break;
            temp = temp->next;
        }
        if(n<=1) return head;
        k = k%n;
        if(k==0) return head;
        temp->next = head; //make list circular
        temp = head;
        for(int i=0; i<n-k-1; ++i) temp = temp->next;
        head = temp->next;
        temp->next = nullptr;
        return head;
    }
};