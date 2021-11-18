/*
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

*/

<script>

// JavaScript program for reversing the linked list

var head;

	class Node {
		constructor(val) {
			this.data = val;
			this.next = null;
		}
	}

	/* Function to reverse the linked list */
	function reverse(node) {
	var prev = null;
	var current = node;
	var next = null;
		while (current != null) {
			next = current.next;
			current.next = prev;
			prev = current;
			current = next;
		}
		node = prev;
		return node;
	}

	// prints content of var linked list
	function printList(node) {
		while (node != null) {
			document.write(node.data + " ");
			node = node.next;
		}
	}

	// Driver Code
	
		head = new Node(85);
		head.next = new Node(15);
		head.next.next = new Node(4);
		head.next.next.next = new Node(20);

		document.write("Given Linked list<br/>");
		printList(head);
		head = reverse(head);
		document.write("<br/>");
		document.write("Reversed linked list<br/> ");
		printList(head);

</script>

/*
Output: 

Given linked list
85 15 4 20 
Reversed Linked list 
20 4 15 85
Time Complexity: O(n) 
Space Complexity: O(1)
*/
