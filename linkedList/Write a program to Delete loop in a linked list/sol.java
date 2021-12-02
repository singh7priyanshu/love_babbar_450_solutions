/*
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


*/

// Java program to detect and remove loop in linked list

class LinkedList {

	static Node head;

	static class Node {

		int data;
		Node next;

		Node(int d)
		{
			data = d;
			next = null;
		}
	}

	// Function that detects loop in the list
	int detectAndRemoveLoop(Node node)
	{
		Node slow = node, fast = node;
		while (slow != null && fast != null && fast.next != null) {
			slow = slow.next;
			fast = fast.next.next;

			// If slow and fast meet at same point then loop is present
			if (slow == fast) {
				removeLoop(slow, node);
				return 1;
			}
		}
		return 0;
	}

	// Function to remove loop
	void removeLoop(Node loop, Node head)
	{
		Node ptr1 = loop;
		Node ptr2 = loop;

		// Count the number of nodes in loop
		int k = 1, i;
		while (ptr1.next != ptr2) {
			ptr1 = ptr1.next;
			k++;
		}

		// Fix one pointer to head
		ptr1 = head;

		// And the other pointer to k nodes after head
		ptr2 = head;
		for (i = 0; i < k; i++) {
			ptr2 = ptr2.next;
		}

		/* Move both pointers at the same pace,
		they will meet at loop starting node */
		while (ptr2 != ptr1) {
			ptr1 = ptr1.next;
			ptr2 = ptr2.next;
		}

		// Get pointer to the last node
		while (ptr2.next != ptr1) {
			ptr2 = ptr2.next;
		}

		/* Set the next node of the loop ending node
		to fix the loop */
		ptr2.next = null;
	}

	// Function to print the linked list
	void printList(Node node)
	{
		while (node != null) {
			System.out.print(node.data + " ");
			node = node.next;
		}
	}

	// Driver program to test above functions
	public static void main(String[] args)
	{
		LinkedList list = new LinkedList();
		list.head = new Node(50);
		list.head.next = new Node(20);
		list.head.next.next = new Node(15);
		list.head.next.next.next = new Node(4);
		list.head.next.next.next.next = new Node(10);

		// Creating a loop for testing
		head.next.next.next.next.next = head.next.next;
		list.detectAndRemoveLoop(head);
		System.out.println("Linked List after removing loop : ");
		list.printList(head);
	}
}

/*

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

*/


// Java program to detect
// and remove loop in linked list

class LinkedList {

	static Node head;

	static class Node {

		int data;
		Node next;

		Node(int d)
		{
			data = d;
			next = null;
		}
	}

	// Function that detects loop in the list
	void detectAndRemoveLoop(Node node)
	{

		// If list is empty or has only one node
		// without loop
		if (node == null || node.next == null)
			return;

		Node slow = node, fast = node;

		// Move slow and fast 1 and 2 steps
		// ahead respectively.
		slow = slow.next;
		fast = fast.next.next;

		// Search for loop using slow and fast pointers
		while (fast != null && fast.next != null) {
			if (slow == fast)
				break;

			slow = slow.next;
			fast = fast.next.next;
		}

		/* If loop exists */
		if (slow == fast) {
			slow = node;
			if (slow != fast) {
				while (slow.next != fast.next) {
					slow = slow.next;
					fast = fast.next;
				}
				/* since fast->next is the looping point */
				fast.next = null; /* remove loop */
			}
			/* This case is added if fast and slow pointer meet at first position. */
			else {
				while(fast.next != slow) {
					fast = fast.next;
				}
				fast.next = null;
			}
		}
	}

	// Function to print the linked list
	void printList(Node node)
	{
		while (node != null) {
			System.out.print(node.data + " ");
			node = node.next;
		}
	}

	// Driver code
	public static void main(String[] args)
	{
		LinkedList list = new LinkedList();
		list.head = new Node(50);
		list.head.next = new Node(20);
		list.head.next.next = new Node(15);
		list.head.next.next.next = new Node(4);
		list.head.next.next.next.next = new Node(10);

		// Creating a loop for testing
		head.next.next.next.next.next = head.next.next;
		list.detectAndRemoveLoop(head);
		System.out.println("Linked List after removing loop : ");
		list.printList(head);
	}
}


/*

Output:

Linked List after removing loop 
50 20 15 4 10 
Method 4 Hashing: Hash the address of the linked list nodes 
We can hash the addresses of the linked list nodes in an unordered map and just 
check if the element already exists in the map. If it exists, we have reached a node 
which already exists by a cycle, hence we need to make the last node’s next pointer NULL.

*/

// Java program to detect and remove loop in a linked list
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

	// Function to print the linked list
	void printList(Node node)
	{
		while (node != null) {
			System.out.print(node.data + " ");
			node = node.next;
		}
	}

	// Returns true if the loop is removed from the linked
	// list else returns false.
	static boolean removeLoop(Node h)
	{
		HashSet<Node> s = new HashSet<Node>();
		Node prev = null;
		while (h != null) {
			// If we have already has this node
			// in hashmap it means their is a cycle and we
			// need to remove this cycle so set the next of
			// the previous pointer with null.

			if (s.contains(h)) {
				prev.next = null;
				return true;
			}

			// If we are seeing the node for
			// the first time, insert it in hash
			else {
				s.add(h);
				prev = h;
				h = h.next;
			}
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

		if (removeLoop(head)) {
			System.out.println("Linked List after removing loop");
			llist.printList(head);
		}
		else
			System.out.println("No Loop found");
	}
}

/*

Output
Linked List after removing loop 
50 20 15 4 10 

*/