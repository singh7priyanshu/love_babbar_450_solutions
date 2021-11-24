"""
Given a linked list of size N. 
The task is to reverse every k nodes 
(where k is an input to the function) in the linked list. 
If the number of nodes is not a multiple of k then left-out nodes, in the end, 
should be considered as a group and must be reversed (See Example 2 for clarification).

Example 1:

Input:
LinkedList: 1->2->2->4->5->6->7->8
K = 4
Output: 4 2 2 1 8 7 6 5 
Explanation: 
The first 4 elements 1,2,2,4 are reversed first 
and then the next 4 elements 5,6,7,8. Hence, the 
resultant linked list is 4->2->2->1->8->7->6->5.
Example 2:

Input:
LinkedList: 1->2->3->4->5
K = 3
Output: 3 2 1 5 4 
Explanation: 
The first 3 elements are 1,2,3 are reversed 
first and then elements 4,5 are reversed.Hence, 
the resultant linked list is 3->2->1->5->4.
Your Task:
You don't need to read input or print anything. Your task is to complete the function reverse() which should reverse the linked list in group of size k and return the head of the modified linked list.

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(1)

Constraints:
1 <= N <= 104
1 <= k <= N

"""



"""Return reference of new head of the reverse linked list
  The input list will have at least one element
  Node is defined as

class Node:
    def __init__(self, data):
		self.data = data
		self.next = None
  This is method only submission.
  You only need to complete the method.
"""
class Solution:
    def reverse(self, head, k):
        current = head
        next = None
        prev = None
        count = 0
        
        while (current is not None and count < k):
            # reversing k elements
            next = current.next              # storing value of next node
            current.next = prev              # reversing link
            prev = current                   # updating prev
            current = next                   # updating current
            count += 1
        
        if next is not None:    # checking if there are more nodes ahead
            head.next = self.reverse(next, k)     # reversing those recursively
        
        return prev


class Node:
    def __init__(self,data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
        # self.tail

    def push(self, new_data):
        new_node = Node(new_data)
        new_node.next = self.head
        self.head = new_node

    def printList(self):
        temp = self.head
        while(temp):
            print(temp.data,end=" ")
            # arr.append(str(temp.data))
            temp = temp.next
        print()

if __name__ == '__main__':
    t = int(input())
    while(t>0):
        llist = LinkedList()
        n = input()
        values = list(map(int,input().split()))
        for i in reversed(values):
            llist.push(i)
        k = int(input())
        new_head = LinkedList()
        ob = Solution()
        new_head = ob.reverse(llist.head,k)
        llist.head = new_head
        llist.printList()
        t -= 1
