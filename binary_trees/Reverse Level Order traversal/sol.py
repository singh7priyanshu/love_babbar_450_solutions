"""
Reverse Level Order Traversal

METHOD 1 (Recursive function to print a given level) 
We can easily modify the method 1 of the normal level order traversal. 
In method 1, we have a method printGivenLevel() which prints a given level number. 
The only thing we need to change is, instead of calling printGivenLevel() from the first 
level to the last level, we call it from the last level to the first level. 

"""

# A recursive Python program to print REVERSE level order traversal

# A binary tree node
class Node:

	# Constructor to create a new node
	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None

# Function to print reverse level order traversal
def reverseLevelOrder(root):
	h = height(root)
	for i in reversed(range(1, h+1)):
		printGivenLevel(root,i)

# Print nodes at a given level
def printGivenLevel(root, level):

	if root is None:
		return
	if level ==1 :
		print root.data,

	elif level>1:
		printGivenLevel(root.left, level-1)
		printGivenLevel(root.right, level-1)

# Compute the height of a tree-- the number of
# nodes along the longest path from the root node
# down to the farthest leaf node
def height(node):
	if node is None:
		return 0
	else:

		# Compute the height of each subtree
		lheight = height(node.left)
		rheight = height(node.right)

		# Use the larger one
		if lheight > rheight :
			return lheight + 1
		else:
			return rheight + 1

# Driver program to test above function
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)

print "Level Order traversal of binary tree is"
reverseLevelOrder(root)


"""

Output: 

Level Order traversal of binary tree is
4 5 2 3 1
Time Complexity: The worst-case time complexity of this method is O(n^2). 
For a skewed tree, printGivenLevel() takes O(n) time where n is the number of nodes 
in the skewed tree. 
So time complexity of printLevelOrder() is O(n) + O(n-1) + O(n-2) + .. + O(1) which is O(n^2).


METHOD 2 (Using Queue and Stack) 
The method 2 of normal level order traversal can also be easily modified to print level order 
traversal in reverse order. The idea is to use a deque(double-ended queue) 
to get the reverse level order. A deque allows insertion and deletion at both the ends. 
If we do normal level order traversal and instead of printing a node, push the node to a 
stack and then print the contents of the deque, we get “5 4 3 2 1” for the above example tree, 
but the output should be “4 5 2 3 1”. So to get the correct sequence (left to right at every level), 
we process children of a node in reverse order, we first push the right subtree to the deque, 
then process the left subtree.

"""


# Python program to print REVERSE level order traversal using
# stack and queue

from collections import deque
# A binary tree node
class Node:

	# Constructor to create a new node
	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None


# Given a binary tree, print its nodes in reverse level order


def reverseLevelOrder(root):
# we can use a double ended queue which provides O(1) insert at the beginning
# using the appendleft method
# we do the regular level order traversal but instead of processing the
# left child first we process the right child first and the we process the left child
# of the current Node
# we can do this One pass reduce the space usage not in terms of complexity but intuitively

	q = deque()
	q.append(root)
	ans = deque()
	while q:
		node = q.popleft()
		if node is None:
			continue
		
		ans.appendleft(node.data)
		
		if node.right:
			q.append(node.right)
			
		if node.left:
			q.append(node.left)
			
	return ans

# Driver program to test above function
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
root.right.left = Node(6)
root.right.right = Node(7)

print "Level Order traversal of binary tree is"
reverseLevelOrder(root)

"""

Output: 

Level Order traversal of binary tree is
4 5 6 7 2 3 1
Time Complexity: O(n) where n is the number of nodes in the binary tree. 

"""