"""
Detect and Remove Loop in a Linked List

Method 1 (Check one by one) We know that Floyd’s Cycle detection algorithm terminates 
when fast and slow pointers meet at a common point. We also know that this common point
is one of the loop nodes (2 or 3 or 4 or 5 in the above diagram). 
Store the address of this in a pointer variable say ptr2. 
After that start from the head of the Linked List and check for nodes one by one if they 
are reachable from ptr2. Whenever we find a node that is reachable, 
we know that this node is the starting node of the loop in Linked List and we can get the 
pointer to the previous of this node.

Output:

Linked List after removing loop 
50 20 15 4 10 
Method 2 (Better Solution)  

This method is also dependent on Floyd’s Cycle detection algorithm.
Detect Loop using Floyd’s Cycle detection algorithm and get the pointer to a loop node.
Count the number of nodes in loop. Let the count be k.
Fix one pointer to the head and another to a kth node from the head.
Move both pointers at the same pace, they will meet at loop starting node.
Get a pointer to the last node of the loop and make next of it as NULL.

"""

# Python program to detect and remove loop in linked list

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

	def detectAndRemoveLoop(self):
		slow_p = fast_p = self.head
		
		while(slow_p and fast_p and fast_p.next):
			slow_p = slow_p.next
			fast_p = fast_p.next.next

			# If slow_p and fast_p meet at some point then
			# there is a loop
			if slow_p == fast_p:
				self.removeLoop(slow_p)
		
				# Return 1 to indicate that loop is found
				return 1
		
		# Return 0 to indicate that there is no loop
		return 0

	# Function to remove loop
	# loop_node --> pointer to one of the loop nodes
	# head --> Pointer to the start node of the linked list
	def removeLoop(self, loop_node):
		ptr1 = loop_node
		ptr2 = loop_node
		
		# Count the number of nodes in loop
		k = 1
		while(ptr1.next != ptr2):
			ptr1 = ptr1.next
			k += 1

		# Fix one pointer to head
		ptr1 = self.head
		
		# And the other pointer to k nodes after head
		ptr2 = self.head
		for i in range(k):
			ptr2 = ptr2.next

		# Move both pointers at the same place
		# they will meet at loop starting node
		while(ptr2 != ptr1):
			ptr1 = ptr1.next
			ptr2 = ptr2.next

		# Get pointer to the last node
		while(ptr2.next != ptr1):
			ptr2 = ptr2.next

		# Set the next node of the loop ending node
		# to fix the loop
		ptr2.next = None

	# Function to insert a new node at the beginning
	def push(self, new_data):
		new_node = Node(new_data)
		new_node.next = self.head
		self.head = new_node

	# Utility function to print the linked LinkedList
	def printList(self):
		temp = self.head
		while(temp):
			print(temp.data, end = ' ')
			temp = temp.next


# Driver program
llist = LinkedList()
llist.push(10)
llist.push(4)
llist.push(15)
llist.push(20)
llist.push(50)

# Create a loop for testing
llist.head.next.next.next.next.next = llist.head.next.next

llist.detectAndRemoveLoop()

print("Linked List after removing loop")
llist.printList()

"""

Output: 

Linked List after removing loop 
50 20 15 4 10 
Method 3 (Optimized Method 2: Without Counting Nodes in Loop) 
We do not need to count number of nodes in Loop. After detecting the loop, 
if we start slow pointer from head and move both slow and fast pointers at same 
speed until fast don’t meet, they would meet at the beginning of the loop.

How does this work? 
Let slow and fast meet at some point after Floyd’s Cycle finding algorithm.



Distance traveled by fast pointer = 2 * (Distance traveled 
                                         by slow pointer)

(m + n*x + k) = 2*(m + n*y + k)

Note that before meeting the point shown above, fast
was moving at twice speed.

x -->  Number of complete cyclic rounds made by 
       fast pointer before they meet first time

y -->  Number of complete cyclic rounds made by 
       slow pointer before they meet first time
From above equation, we can conclude below 

    m + k = (x-2y)*n

Which means m+k is a multiple of n. 
Thus we can write, m + k = i*n or m = i*n - k.
Hence, distance moved by slow pointer: m, is equal to distance moved by fast pointer:
i*n - k or (i-1)*n + n - k (cover the loop completely i-1 times and start from n-k).
So if we start moving both pointers again at same speed such that one pointer (say slow)
begins from head node of linked list and other pointer (say fast) begins from meeting point. 
When slow pointer reaches beginning of loop (has made m steps), fast pointer would have made 
also moved m steps as they are now moving same pace. Since m+k is a multiple of n and fast 
starts from k, they would meet at the beginning. Can they meet before also? No because slow 
pointer enters the cycle first time after m steps. 

"""

# Python program to detect and remove loop

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

	# Function to insert a new node at the beginning
	def push(self, new_data):
		new_node = Node(new_data)
		new_node.next = self.head
		self.head = new_node

	def detectAndRemoveLoop(self):
	if self.head is None:
		return
	if self.head.next is None:
		return
	slow_p = self.head
	fast_p = self.head
		
	while(slow_p and fast_p and fast_p.next):
		slow_p = slow_p.next
		fast_p = fast_p.next.next

		# If slow_p and fast_p meet at some point then
		# there is a loop
		if slow_p == fast_p:
			slow_p = self.head
			# Finding the beginning of the loop
			while (slow_p.next != fast_p.next):
			slow_p = slow_p.next
			fast_p = fast_p.next

				# Sinc fast.next is the looping point
			fast_p.next = None # Remove loop

	# Utility function to print the linked LinkedList

	def printList(self):
		temp = self.head
		while(temp):
			print(temp.data, end = ' ')
			temp = temp.next


# Driver program
llist = LinkedList()
llist.head = Node(50)
llist.head.next = Node(20)
llist.head.next.next = Node(15)
llist.head.next.next.next = Node(4)
llist.head.next.next.next.next = Node(10)

# Create a loop for testing
llist.head.next.next.next.next.next = llist.head.next.next

llist.detectAndRemoveLoop()

print("Linked List after removing loop")
llist.printList()


"""


Output
Linked List after removing loop 
50 20 15 4 10 


"""