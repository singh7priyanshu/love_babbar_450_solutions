/*
Implementation of Stack

Following example shows how to implement stack by creating user defined push() 
method for entering elements and pop() method for retrieving elements from the stack.
*/


import java.util.*;

public class Demo {
   static void showpush(Stack stack1, int a) {
      stack1.push(new Integer(a));
      System.out.println("push(" + a + ")");
      System.out.println("stack: " + stack1);
   } 
   static void showpop(Stack stack1) {
      Integer a = (Integer) stack1.pop();
      System.out.println(a);
      System.out.println("stack: " + stack1);
   } 
   public static void main(String args[]) {
      Stack stack1 = new Stack();
      System.out.println("stack: " + stack1);
      showpush(stack1, 40);
      showpush(stack1, 50);
      showpush(stack1, 60);
      showpop(stack1);
      showpop(stack1);
      showpop(stack1);
      try {
         showpop(stack1);
      } catch (EmptyStackException e) {
         System.out.println("it Is Empty Stack");
      } 
   }
}


/*

The above code sample will produce the following result.

stack: []
push(40)
stack: [40]
push(50)
stack: [40, 50]
push(60)
stack: [40, 50, 60]
60
stack: [40, 50]
50
stack: [40]
40
stack: []
it Is Empty Stack

*/