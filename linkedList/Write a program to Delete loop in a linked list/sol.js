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

<script>

// Javascript program to detect and
// remove loop in linked list
var head;

class Node
{
	constructor(val)
	{
		this.data = val;
		this.next = null;
	}
}

// Function that detects loop in the list
function detectAndRemoveLoop(node)
{
	var slow = node, fast = node;
	while (slow != null &&
		fast != null &&
		fast.next != null)
	{
		slow = slow.next;
		fast = fast.next.next;

		// If slow and fast meet at same
		// point then loop is present
		if (slow == fast)
		{
			removeLoop(slow, node);
			return 1;
		}
	}
	return 0;
}

// Function to remove loop
function removeLoop(loop, head)
{
	var ptr1 = loop;
	var ptr2 = loop;

	// Count the number of nodes in loop
	var k = 1, i;
	
	while (ptr1.next != ptr2)
	{
		ptr1 = ptr1.next;
		k++;
	}

	// Fix one pointer to head
	ptr1 = head;

	// And the other pointer to
	// k nodes after head
	ptr2 = head;
	for(i = 0; i < k; i++)
	{
		ptr2 = ptr2.next;
	}

	/* Move both pointers at the same pace,
	they will meet at loop starting node */
	while (ptr2 != ptr1)
	{
		ptr1 = ptr1.next;
		ptr2 = ptr2.next;
	}

	// Get pointer to the last node
	while (ptr2.next != ptr1)
	{
		ptr2 = ptr2.next;
	}

	/* Set the next node of the loop ending node
	to fix the loop */
	ptr2.next = null;
}

// Function to print the linked list
function printList(node)
{
	while (node != null)
	{
		document.write(node.data + " ");
		node = node.next;
	}
}

// Driver code
head = new Node(50);
head.next = new Node(20);
head.next.next = new Node(15);
head.next.next.next = new Node(4);
head.next.next.next.next = new Node(10);

// Creating a loop for testing
head.next.next.next.next.next = head.next.next;
detectAndRemoveLoop(head);
document.write("Linked List after removing loop : ");
printList(head);



</script>



/*

Output:

Linked List after removing loop 
50 20 15 4 10 
Method 4 Hashing: Hash the address of the linked list nodes 
We can hash the addresses of the linked list nodes in an unordered map and just 
check if the element already exists in the map. If it exists, we have reached a node 
which already exists by a cycle, hence we need to make the last node’s next pointer NULL.

*/

<script>
// javascript program to detect and remove loop in a linked list class LinkedList {

	/* Linked list Node */
	class Node {
			constructor(val) {
				this.data = val;
				this.next = null;
			}
		}
	var head; // head of list

	/* Inserts a new Node at front of the list. */
	function push(new_data) {
		/*
		* 1 & 2: Allocate the Node & Put in the data
		*/
var new_node = new Node(new_data);

		/* 3. Make next of new Node as head */
		new_node.next = head;

		/* 4. Move the head to povar to new Node */
		head = new_node;
		return head;
	}

	// Function to prvar the linked list
	function printList(node) {
		while (node != null) {
			document.write(node.data + " ");
			node = node.next;
		}
	}

	// Returns true if the loop is removed from the linked
	// list else returns false.
	function removeLoop(h)
	{
	
		var s = new Set();
		var prev = null;
		while (h != null)
		{
		
			// If we have already has this node
			// in hashmap it means their is a cycle and we
			// need to remove this cycle so set the next of
			// the previous pointer with null.

			if (s.has(h)) {
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
		head = push(50);
		head.next = push(20);
		head.next.next=push(4);
		head.next.next.next=push(15);
		head.next.next.next.next=push(10);

		/* Create loop for testing */
		head.next.next.next.next.next = head.next.next;

		if (removeLoop(head)) {
			document.write("Linked List after removing loop<br/>");
			printList(head);
		} else
			document.write("No Loop found");


</script>


/*

Output
Linked List after removing loop 
50 20 15 4 10 

*/

