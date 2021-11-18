"""
Write a Program to reverse the Linked List. (Both Iterative and recursive)

Given pointer to the head node of a linked list, the task is to reverse the linked list. 
We need to reverse the list by changing the links between nodes.

Examples: 
Input: Head of following linked list 
1->2->3->4->NULL 
Output: Linked list should be changed to, 
4->3->2->1->NULL

Input: Head of following linked list 
1->2->3->4->5->NULL 
Output: Linked list should be changed to, 
5->4->3->2->1->NULL
Input: NULL 
Output: NULL

Input: 1->NULL 
Output: 1->NULL 

Iterative Method 

1. Initialize three pointers prev as NULL, curr as head and next as NULL.
2. Iterate through the linked list. In loop, do following. 
// Before changing next of current, 
// store next node 
next = curr->next
// Now change next of current 
// This is where actual reversing happens 
curr->next = prev 
// Move prev and curr one step forward 
prev = curr 
curr = next

"""
# Python program to reverse a linked list
# Time Complexity : O(n)
# Space Complexity : O(1)

# Node class


class Node:

	# Constructor to initialize the node object
	def __init__(self, data):
		self.data = data
		self.next = None


class LinkedList:

	# Function to initialize head
	def __init__(self):
		self.head = None

	# Function to reverse the linked list
	def reverse(self):
		prev = None
		current = self.head
		while(current is not None):
			next = current.next
			current.next = prev
			prev = current
			current = next
		self.head = prev

	# Function to insert a new node at the beginning
	def push(self, new_data):
		new_node = Node(new_data)
		new_node.next = self.head
		self.head = new_node

	# Utility function to print the linked LinkedList
	def printList(self):
		temp = self.head
		while(temp):
			print temp.data,
			temp = temp.next


# Driver code
llist = LinkedList()
llist.push(20)
llist.push(4)
llist.push(15)
llist.push(85)

print "Given Linked List"
llist.printList()
llist.reverse()
print "\nReversed Linked List"
llist.printList()

"""
Output: 

Given linked list
85 15 4 20 
Reversed Linked list 
20 4 15 85
Time Complexity: O(n) 
Space Complexity: O(1)
Recursive Method: 

   1) Divide the list in two parts - first node and 
      rest of the linked list.
   2) Call reverse for the rest of the linked list.
   3) Link rest to first.
   4) Fix head pointer




Python3 program to reverse linked list
using recursive method
"""

# Linked List Node
class Node:
	def __init__(self, data):
		self.data = data
		self.next = None

# Create and Handle list operations
class LinkedList:
	def __init__(self):
		self.head = None # Head of list

	# Method to reverse the list
	def reverse(self, head):

		# If head is empty or has reached the list end
		if head is None or head.next is None:
			return head

		# Reverse the rest list
		rest = self.reverse(head.next)

		# Put first element at the end
		head.next.next = head
		head.next = None

		# Fix the header pointer
		return rest

	# Returns the linked list in display format
	def __str__(self):
		linkedListStr = ""
		temp = self.head
		while temp:
			linkedListStr = (linkedListStr +
							str(temp.data) + " ")
			temp = temp.next
		return linkedListStr

	# Pushes new data to the head of the list
	def push(self, data):
		temp = Node(data)
		temp.next = self.head
		self.head = temp

# Driver code
linkedList = LinkedList()
linkedList.push(20)
linkedList.push(4)
linkedList.push(15)
linkedList.push(85)

print("Given linked list")
print(linkedList)

linkedList.head = linkedList.reverse(linkedList.head)

print("Reversed linked list")
print(linkedList)

"""
Output: 

Given linked list
85 15 4 20 
Reversed Linked list
20 4 15 85
Time Complexity: O(n) 
Space Complexity: O(1)

A Simpler and Tail Recursive Method 

Below is the implementation of this method. 
"""

# Simple and tail recursive Python program to
# reverse a linked list

# Node class


class Node:

	# Constructor to initialize the node object
	def __init__(self, data):
		self.data = data
		self.next = None


class LinkedList:

	# Function to initialize head
	def __init__(self):
		self.head = None

	def reverseUtil(self, curr, prev):

		# If last node mark it head
		if curr.next is None:
			self.head = curr

			# Update next to prev node
			curr.next = prev
			return

		# Save curr.next node for recursive call
		next = curr.next

		# And update next
		curr.next = prev

		self.reverseUtil(next, curr)

	# This function mainly calls reverseUtil()
	# with previous as None

	def reverse(self):
		if self.head is None:
			return
		self.reverseUtil(self.head, None)

	# Function to insert a new node at the beginning

	def push(self, new_data):
		new_node = Node(new_data)
		new_node.next = self.head
		self.head = new_node

	# Utility function to print the linked LinkedList
	def printList(self):
		temp = self.head
		while(temp):
			print temp.data,
			temp = temp.next


# Driver code
llist = LinkedList()
llist.push(8)
llist.push(7)
llist.push(6)
llist.push(5)
llist.push(4)
llist.push(3)
llist.push(2)
llist.push(1)

print "Given linked list"
llist.printList()

llist.reverse()

print "\nReverse linked list"
llist.printList()

"""
Output
Given linked list
1 2 3 4 5 6 7 8 

Reversed linked list
8 7 6 5 4 3 2 1
Using Stack:

Store the nodes(values and address) in the stack until all the values are entered.
Once all entries are done, Update the Head pointer to the last location(i.e the last value).
Start popping the nodes(value and address) and store them in the same order until the stack is empty.
Update the next pointer of last Node in the stack by NULL.
Below is the implementation of the above approach:
"""

# Python code for the above approach

# Definition for singly-linked list.
class ListNode:
	def __init__(self, val=0, next=None):
		self.val = val
		self.next = next


class Solution:

	# Program to reverse the linked list
	# using stack
	def reverseLLUsingStack(self, head):
		
		# Initialise the variables
		stack, temp = [], head
		
		while temp:
			stack.append(temp)
			temp = temp.next

		head = temp = stack.pop()
		
		# Untill stack is not
		# empty
		while len(stack) > 0:
			elem = stack.pop()
			temp.next = elem
			temp = elem

		elem.next = None
		return head

# Driver Code
if __name__ == "__main__":
	head = ListNode(1, ListNode(2, ListNode(3,
						ListNode(4, ListNode(5)))))
	obj = Solution()
	head = obj.reverseLLUsingStack(head)
	while head:
		print(head.val, end=' ')
		head = head.next

"""
Output
Given linked list
1 2 3 4 
Reversed linked list
4 3 2 1 
"""

