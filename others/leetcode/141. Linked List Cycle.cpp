/*
141. Linked List Cycle

Given head, the head of a linked list, determine if the 
linked list has a cycle in it.

There is a cycle in a linked list if there is some node 
in the list that can be reached again by continuously 
following the next pointer. Internally, pos is used to denote 
the index of the node that tail's next pointer is connected 
to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, 
    return false.


Example 1:

(3)----(2)----(0)-----(-4)
        ^               |
        |_______________|

Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the 
tail connects to the 1st node (0-indexed).

Example 2:

(1)----->(2)
 ^        |
 |________|


Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where 
the tail connects to the 0th node.

Example 3:

(1)

Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)return false;
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast != NULL && fast ->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
                return true;
        }
        return false;
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

