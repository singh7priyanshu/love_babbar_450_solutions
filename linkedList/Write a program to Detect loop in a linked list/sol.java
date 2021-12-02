/*
Detect loop in a linked list

Given a linked list, check if the linked list has loop or not. 

Solution 1: Hashing Approach:

Traverse the list one by one and keep putting the node addresses in a Hash Table.
At any point, if NULL is reached then return false, and if the next of the current 
nodes points to any of the previously stored nodes in  Hash then return true.
 
*/

// Java program to detect loop in a linked list
import java.util.*;

public class LinkedList {

	static Node head; // head of list

	/* Linked list Node*/
	static class Node {
		int data;
		Node next;
		Node(int d)
		{
			data = d;
			next = null;
		}
	}

	/* Inserts a new Node at front of the list. */
	static public void push(int new_data)
	{
		/* 1 & 2: Allocate the Node &
				Put in the data*/
		Node new_node = new Node(new_data);

		/* 3. Make next of new Node as head */
		new_node.next = head;

		/* 4. Move the head to point to new Node */
		head = new_node;
	}

	// Returns true if there is a loop in linked
	// list else returns false.
	static boolean detectLoop(Node h)
	{
		HashSet<Node> s = new HashSet<Node>();
		while (h != null) {
			// If we have already has this node
			// in hashmap it means their is a cycle
			// (Because you we encountering the
			// node second time).
			if (s.contains(h))
				return true;

			// If we are seeing the node for
			// the first time, insert it in hash
			s.add(h);

			h = h.next;
		}

		return false;
	}

	/* Driver program to test above function */
	public static void main(String[] args)
	{
		LinkedList llist = new LinkedList();

		llist.push(20);
		llist.push(4);
		llist.push(15);
		llist.push(10);

		/*Create loop for testing */
		llist.head.next.next.next.next = llist.head;

		if (detectLoop(head))
			System.out.println("Loop found");
		else
			System.out.println("No Loop");
	}
}


/*
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
*/

// Java program to detect loop in a linked list
import java.util.*;

class GFG{

// Link list node
static class Node
{
	int data;
	Node next;
	int flag;
};

static Node push(Node head_ref, int new_data)
{
	
	// Allocate node
	Node new_node = new Node();

	// Put in the data
	new_node.data = new_data;

	new_node.flag = 0;

	// Link the old list off the new node
	new_node.next = head_ref;

	// Move the head to point to the new node
	head_ref = new_node;
	return head_ref;
}

// Returns true if there is a loop in linked
// list else returns false.
static boolean detectLoop(Node h)
{
	while (h != null)
	{
		
		// If this node is already traverse
		// it means there is a cycle
		// (Because you we encountering the
		// node for the second time).
		if (h.flag == 1)
			return true;

		// If we are seeing the node for
		// the first time, mark its flag as 1
		h.flag = 1;

		h = h.next;
	}
	return false;
}

// Driver code
public static void main(String[] args)
{
	
	// Start with the empty list
	Node head = null;

	head = push(head, 20);
	head = push(head, 4);
	head = push(head, 15);
	head = push(head, 10);

	// Create a loop for testing
	head.next.next.next.next = head;

	if (detectLoop(head))
		System.out.print("Loop found");
	else
		System.out.print("No Loop");
}
}

/*

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
*/

// Java program to detect loop in a linked list
class LinkedList {
	Node head; // head of list

	/* Linked list Node*/
	class Node {
		int data;
		Node next;
		Node(int d)
		{
			data = d;
			next = null;
		}
	}

	/* Inserts a new Node at front of the list. */
	public void push(int new_data)
	{
		/* 1 & 2: Allocate the Node &
				Put in the data*/
		Node new_node = new Node(new_data);

		/* 3. Make next of new Node as head */
		new_node.next = head;

		/* 4. Move the head to point to new Node */
		head = new_node;
	}

	void detectLoop()
	{
		Node slow_p = head, fast_p = head;
		int flag = 0;
		while (slow_p != null && fast_p != null
			&& fast_p.next != null) {
			slow_p = slow_p.next;
			fast_p = fast_p.next.next;
			if (slow_p == fast_p) {
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			System.out.println("Loop found");
		else
			System.out.println("Loop not found");
	}

	/* Driver program to test above functions */
	public static void main(String args[])
	{
		LinkedList llist = new LinkedList();

		llist.push(20);
		llist.push(4);
		llist.push(15);
		llist.push(10);

		/*Create loop for testing */
		llist.head.next.next.next.next = llist.head;

		llist.detectLoop();
	}
}


/*
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

*/


// Java program to return first node of loop
class GFG {

	static class Node {
		int key;
		Node next;
	};

	static Node newNode(int key)
	{
		Node temp = new Node();
		temp.key = key;
		temp.next = null;
		return temp;
	}

	// A utility function to print a linked list
	static void printList(Node head)
	{
		while (head != null) {
			System.out.print(head.key + " ");
			head = head.next;
		}
		System.out.println();
	}

	// Function to detect first node of loop
	// in a linked list that may contain loop
	static boolean detectLoop(Node head)
	{

		// Create a temporary node
		Node temp = new Node();
		while (head != null) {

			// This condition is for the case
			// when there is no loop
			if (head.next == null) {
				return false;
			}

			// Check if next is already
			// pointing to temp
			if (head.next == temp) {
				return true;
			}

			// Store the pointer to the next node
			// in order to get to it in the next step
			Node nex = head.next;

			// Make next point to temp
			head.next = temp;

			// Get to the next node in the list
			head = nex;
		}

		return false;
	}

	// Driver code
	public static void main(String args[])
	{
		Node head = newNode(1);
		head.next = newNode(2);
		head.next.next = newNode(3);
		head.next.next.next = newNode(4);
		head.next.next.next.next = newNode(5);

		// Create a loop for testing(5 is pointing to 3) /
		head.next.next.next.next.next = head.next.next;

		boolean found = detectLoop(head);
		if (found)
			System.out.println("Loop Found");
		else
			System.out.println("No Loop");
	}
}

/*
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

*/


// Java program to return first node of loop
import java.util.*;
class GFG
{
static class Node
{
	int key;
	Node next;
};

static Node newNode(int key)
{
	Node temp = new Node();
	temp.key = key;
	temp.next = null;
	return temp;
}

// A utility function to print a linked list
static void printList(Node head)
{
	while (head != null)
	{
		System.out.print(head.key + " ");
		head = head.next;
	}
	System.out.println();
}

/*returns distance between first and last node every time
* last node moves forwards*/
static int distance(Node first, Node last)
{

	/*counts no of nodes between first and last*/
	int counter = 0;
	Node curr;
	curr = first;
	while (curr != last)
	{
		counter += 1;
		curr = curr.next;
	}
	return counter + 1;
}

// Function to detect first node of loop
// in a linked list that may contain loop
static boolean detectLoop(Node head)
{

	// Create a temporary node
	Node temp = new Node();
	Node first, last;

	/*first always points to head*/
	first = head;

	/*last pointer initially points to head*/
	last = head;

	/*current_length stores no of nodes between current
	* position of first and last*/
	int current_length = 0;

	/*current_length stores no of nodes between previous
	* position of first and last*/
	int prev_length = -1;
	while (current_length > prev_length && last != null)
	{
	
		// set prev_length to current length then update the
		// current length
		prev_length = current_length;
	
		// distance is calculated
		current_length = distance(first, last);
	
		// last node points the next node
		last = last.next;
	}
	
	if (last == null)
	{
		return false;
	}
	else
	{
		return true;
	}
}

/* Driver program to test above function*/
public static void main(String[] args)
{
	Node head = newNode(1);
	head.next = newNode(2);
	head.next.next = newNode(3);
	head.next.next.next = newNode(4);
	head.next.next.next.next = newNode(5);

	/* Create a loop for testing(5 is pointing to 3) */
	head.next.next.next.next.next = head.next.next;
	boolean found = detectLoop(head);
	if (found)
		System.out.print("Loop Found");
	else
		System.out.print("No Loop Found");
}
}

/*
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

*/


// Java program to return first node of loop
import java.util.*;

class LinkedList{
	
// Head of list
static Node head;

// Linked list Node
static class Node
{
	int data;
	Node next;
	
	Node(int d)
	{
		data = d;
		next = null;
	}
}

/* Inserts a new Node at front of the list. */
static public void push(int new_data)
{
	
	/* 1 & 2: Allocate the Node &
			Put in the data*/
	Node new_node = new Node(new_data);

	/* 3. Make next of new Node as head */
	new_node.next = head;

	/* 4. Move the head to point to new Node */
	head = new_node;
}

// Function to detect first node of loop
// in a linked list that may contain loop
static boolean detectLoop(Node h)
{
	
	// If the head is null we will return false
	if (head == null)
		return false;
	else
	{
		
		// Traversing the linked list
		// for detecting loop
		while (head != null)
		{
			
			// If loop found
			if (head.data == -1)
			{
				return true;
			}

			// Changing the data of visited node to any
			// value which is outside th given range
			// here it is supposed the given range is (1
			// <= Data on Node <= 10^3)
			else
			{
				head.data = -1;
				head = head.next;
			}
		}
		
		// If loop not found return false
		return false;
	}
}

// Driver Code
public static void main(String[] args)
{
	LinkedList llist = new LinkedList();

	llist.push(1);
	llist.push(2);
	llist.push(3);
	llist.push(4);
	llist.push(5);

	/* Create a loop for testing */
	llist.head.next.next.next.next.next = llist.head.next.next;
	
	if (detectLoop(llist.head))
		System.out.println("1");
	else
		System.out.println("0");
}
}

/*
Output
1
Time Complexity: O(N)

Auxiliary Space: O(1)

*/


