"""
Detect loop in a linked list

Given a linked list, check if the linked list has loop or not. 

Solution 1: Hashing Approach:

Traverse the list one by one and keep putting the node addresses in a Hash Table.
At any point, if NULL is reached then return false, and if the next of the current 
nodes points to any of the previously stored nodes in  Hash then return true.
 
"""

# Python3 program to detect loop
# in the linked list

# Node class


class Node:

	# Constructor to initialize
	# the node object
	def __init__(self, data):
		self.data = data
		self.next = None


class LinkedList:

	# Function to initialize head
	def __init__(self):
		self.head = None

	# Function to insert a new
	# node at the beginning
	def push(self, new_data):
		new_node = Node(new_data)
		new_node.next = self.head
		self.head = new_node

	# Utility function to print it
	# the linked LinkedList
	def printList(self):
		temp = self.head
		while(temp):
			print(temp.data, end=" ")
			temp = temp.next

	def detectLoop(self):
		s = set()
		temp = self.head
		while (temp):

			# If we have already has
			# this node in hashmap it
			# means their is a cycle
			# (Because you we encountering
			# the node second time).
			if (temp in s):
				return True

			# If we are seeing the node for
			# the first time, insert it in hash
			s.add(temp)

			temp = temp.next

		return False


# Driver program for testing
llist = LinkedList()
llist.push(20)
llist.push(4)
llist.push(15)
llist.push(10)

# Create a loop for testing
llist.head.next.next.next.next = llist.head

if(llist.detectLoop()):
	print("Loop found")
else:
	print("No Loop ")


"""
Output
Loop found
Complexity Analysis:  

Time complexity: O(n). 
Only one traversal of the loop is needed.
Auxiliary Space: O(n). 
n is the space required to store the value in hashmap.
Solution 2: This problem can be solved without hashmap by modifying the linked list data structure. 
Approach: This solution requires modifications to the basic linked list data structure. 

Have a visited flag with each node.
Traverse the linked list and keep marking visited nodes.
If you see a visited node again then there is a loop. This solution works in O(n) 
but requires additional information with each node.
A variation of this solution that doesn’t require modification to basic data structure can 
be implemented using a hash, just store the addresses of visited nodes in a hash and if you see 
an address that already exists in hash then there is a loop.

"""

# Python3 program to detect loop in a linked list

''' Link list node '''
class Node:
	
	def __init__(self):
		self.data = 0
		self.next = None
		self.flag = 0
	
def push(head_ref, new_data):

	''' allocate node '''
	new_node = Node();

	''' put in the data '''
	new_node.data = new_data;

	new_node.flag = 0;

	''' link the old list off the new node '''
	new_node.next = (head_ref);

	''' move the head to point to the new node '''
	(head_ref) = new_node;
	return head_ref

# Returns true if there is a loop in linked list
# else returns false.
def detectLoop(h):

	while (h != None):
		# If this node is already traverse
		# it means there is a cycle
		# (Because you we encountering the
		# node for the second time).
		if (h.flag == 1):
			return True;

		# If we are seeing the node for
		# the first time, mark its flag as 1
		h.flag = 1;
		h = h.next;
	return False;

''' Driver program to test above function'''
if __name__=='__main__':
	
	''' Start with the empty list '''
	head = None;

	head = push(head, 20);
	head = push(head, 4);
	head = push(head, 15);
	head = push( head, 10)

	''' Create a loop for testing '''
	head.next.next.next.next = head;

	if (detectLoop(head)):
		print("Loop found")
	else:
		print("No Loop")


"""

Output
Loop found
Complexity Analysis:  

Time complexity:O(n). 
Only one traversal of the loop is needed.
Auxiliary Space:O(1). 
No extra space is needed.


Solution 3: Floyd’s Cycle-Finding Algorithm 
Approach: This is the fastest method and has been described below:  

Traverse linked list using two pointers.
Move one pointer(slow_p) by one and another pointer(fast_p) by two.
If these pointers meet at the same node then there is a loop. 
If pointers do not meet then linked list doesn’t have a loop.


Implementation of Floyd’s Cycle-Finding Algorithm:  
"""


# Python program to detect loop in the linked list

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

	# Utility function to print it the linked LinkedList
	def printList(self):
		temp = self.head
		while(temp):
			print temp.data,
			temp = temp.next

	def detectLoop(self):
		slow_p = self.head
		fast_p = self.head
		while(slow_p and fast_p and fast_p.next):
			slow_p = slow_p.next
			fast_p = fast_p.next.next
			if slow_p == fast_p:
				return


# Driver program for testing
llist = LinkedList()
llist.push(20)
llist.push(4)
llist.push(15)
llist.push(10)

# Create a loop for testing
llist.head.next.next.next.next = llist.head
if(llist.detectLoop()):
	print "Found Loop"
else:
	print "No Loop"


"""
Output
Loop found
Complexity Analysis:  

Time complexity: O(n). 
Only one traversal of the loop is needed.
Auxiliary Space:O(1). 
There is no space required.

Solution 4: Marking visited nodes without modifying the linked list data structure 
In this method, a temporary node is created. The next pointer of each node that is 
traversed is made to point to this temporary node. This way we are using the next pointer 
of a node as a flag to indicate whether the node has been traversed or not. 
Every node is checked to see if the next is pointing to a temporary node or not. 
In the case of the first node of the loop, the second time we traverse it this condition will be true, 
hence we find that loop exists. If we come across a node that points to null then the loop doesn’t exist.

Below is the implementation of the above approach:

"""


# Python3 program to return first node of loop

# A binary tree node has data, pointer to
# left child and a pointer to right child
# Helper function that allocates a new node
# with the given data and None left and
# right pointers


class newNode:
	def __init__(self, key):
		self.key = key
		self.left = None
		self.right = None

# A utility function to print a linked list


def printList(head):
	while (head != None):
		print(head.key, end=" ")
		head = head.next

	print()

# Function to detect first node of loop
# in a linked list that may contain loop


def detectLoop(head):

	# Create a temporary node
	temp = ""
	while (head != None):

		# This condition is for the case
		# when there is no loop
		if (head.next == None):
			return False

		# Check if next is already
		# pointing to temp
		if (head.next == temp):
			return True

		# Store the pointer to the next node
		# in order to get to it in the next step
		nex = head.next

		# Make next poto temp
		head.next = temp

		# Get to the next node in the list
		head = nex

	return False


# Driver Code
head = newNode(1)
head.next = newNode(2)
head.next.next = newNode(3)
head.next.next.next = newNode(4)
head.next.next.next.next = newNode(5)

# Create a loop for testing(5 is pointing to 3)
head.next.next.next.next.next = head.next.next

found = detectLoop(head)
if (found):
	print("Loop Found")
else:
	print("No Loop")

"""
output: 

Loop Found
Complexity Analysis:  

Time complexity: O(n). 
Only one traversal of the loop is needed.
Auxiliary Space: O(1). 
There is no space required.


Solution 5: Store length

In this method, two pointers are created, first (always points to head) and last. 
Each time the last pointer moves we calculate no of nodes in between first and last and 
check whether the current no of nodes > previous no of nodes, if yes we proceed by moving 
last pointer else it means we’ve reached the end of the loop, so we return output accordingly.

"""

# Python program to return first node of loop
class newNode:
	def __init__(self, key):
		self.key = key
		self.left = None
		self.right = None
		

# A utility function to print a linked list
def printList(head):

	while (head != None) :
		print(head.key, end=" ")
		head = head.next;
	
	print()


# returns distance between first and last node every time
# last node moves forwards
def distance(first, last):

	# counts no of nodes between first and last
	counter = 0

	curr = first

	while (curr != last):
		counter = counter + 1
		curr = curr.next
	

	return counter + 1


# Function to detect first node of loop
# in a linked list that may contain loop
def detectLoop(head):

	# Create a temporary node
	temp = ""

	# first always points to head
	first = head;
	# last pointer initially points to head
	last = head;

	# current_length stores no of nodes between current
	# position of first and last
	current_length = 0

	#current_length stores no of nodes between previous
	# position of first and last*/
	prev_length = -1

	while (current_length > prev_length and last != None) :
		# set prev_length to current length then update the
		# current length
		prev_length = current_length
		# distance is calculated
		current_length = distance(first, last)
		# last node points the next node
		last = last.next;
	
	
	if (last == None) :
		return False
	
	else :
		return True


# Driver program to test above function

head = newNode(1);
head.next = newNode(2);
head.next.next = newNode(3);
head.next.next.next = newNode(4);
head.next.next.next.next = newNode(5);

# Create a loop for testing(5 is pointing to 3)
head.next.next.next.next.next = head.next.next;

found = detectLoop(head)
if (found) :
	print("Loop Found")
else :
	print("No Loop Found")

"""
Output
Loop Found
 Complexity Analysis:  

Time complexity: O(n2)
Auxiliary Space: O(1)

Another Approach:
This is the simplest approach of the given problem, the only thing we have to do 
is to assign a new value to each data of node in the linked list which is not in the range given.
Example suppose (1 <= Data on Node <= 10^3) then after visiting node assign the 
data as -1 as it is out of the given range.
Follow the code given below for a better understanding:

"""

# Python program to return first node of loop
class Node:
	def __init__(self,d):
		self.data = d
		self.next = None

head = None
def push(new_data):
	global head
	new_node = Node(new_data)
	new_node.next = head
	head=new_node

def detectLoop(h):
	global head
	
	if (head == None):
		return False
	else:
		
		while (head != None):
			if (head.data == -1):
				return True
			else:
				head.data = -1
				head = head.next
		
		return False

push(1);
push(2);
push(3);
push(4);
push(5);

head.next.next.next.next.next = head.next.next

if (detectLoop(head)):
	print("1")
else:
	print("0")
	

"""
Output
1
Time Complexity: O(N)

Auxiliary Space: O(1)

"""




