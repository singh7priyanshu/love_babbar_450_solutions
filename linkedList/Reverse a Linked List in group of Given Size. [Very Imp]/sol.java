/*
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
*/



import java.util.*:
import java.lang.*;

class Node{
    int data;
    Node next;
    Node (int key){
        data = key;
        next = null;
    }
}

class ReverseInSize{
    static Node head;
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t-- > 0){
            int n = sc.nextInt();
            int a1 = sc.nextInt();
            Node head = new Node(a1);
            Node tail = head;
            for(int i =1;i<n;i++){
                int a = sc.nextInt();
                // addToTheLast(new Node(a));
                tail.next = new Node(a);
                tail = tail.next;
            }
            int k = sc.nextInt();
            Solution ob = new Solution();
            Node res = ob.reverse(head,k);
            printList(res);
            System.out.println();
        }
    }

    public static void printList(Node node){
        while(node!=null){
            System.out.print(node.data+" ");
            node = node.next;
        }
    }
}



/*node class of the linked list

class Node
{
    int data;
    Node next;
    Node(int key)
    {
        data = key;
        next = null;
    }
}

*/

class Solution
{
    public static Node reverse(Node node, int k)
    {
        Node curr = node, prev = null, next = null;
        int count = 0;
        
        while(curr != null && count < k)
        // reversing k elements :
        {
            next = curr.next;                 // marking next node
		    curr.next = prev;                 // reversing link
		    prev = curr;                      // updating prev
		    curr = next;                      // updating current
		    count++;
        }
        
        if (next != null)         // checking if there are nodes ahead
            node.next = reverse(next, k);     // reversing those recursively 
        
        return prev;
    }
}