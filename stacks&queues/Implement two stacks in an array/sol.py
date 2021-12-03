"""
Implement two stacks in an array

Your task is to implement  2 stacks in one array efficiently.

 

Example 1:

Input:
push1(2)
push1(3)
push2(4)
pop1()
pop2()
pop2()

Output:
3 4 -1

Explanation:
push1(2) the stack1 will be {2}
push1(3) the stack1 will be {2,3}
push2(4) the stack2 will be {4}
pop1()   the poped element will be 3 
from stack1 and stack1 will be {2}
pop2()   the poped element will be 4 
from stack2 and now stack2 is empty
pop2()   the stack2 is now empty hence -1 .
 

Your Task:
You don't need to read input or print anything. You are required to complete the 4 methods push1, 
push2 which takes one argument an integer 'x' to be pushed into stack one and two and pop1, 
pop2 which returns the integer poped out from stack one and two. 
If no integer is present in the array return -1.

 

Expected Time Complexity: O(1) for all the four methods.
Expected Auxiliary Space: O(1) for all the four methods.

 

Constraints:
1 <= Number of queries <= 100
1 <= value in the stack <= 100
The sum of elements in both the stacks < size of the given array

"""


#The idea is to start two stacks from two extreme corners of arr[].
#stack1 starts from the leftmost element, the first element in stack1 is 
#pushed at index 0. The stack2 starts from the rightmost corner, the first
#element in stack2 is pushed at index (n-1). Both stacks grow (or shrink) 
#in opposite direction. To check for overflow, all we need to check is for 
#space between top elements of both stacks.


#Function to push an integer into the stack1.
def push1(a,x):
    global top1
    global top2
    
    #if there is space between the top of both stacks 
    #we push the element at top1+1.
    if top1 < top2-1:
        top1+=1
        a[top1] = x
        
#Function to push an integer into the stack2.
def push2(a,x):
    global top1
    global top2
    
    #if there is space between the top of both stacks 
    #we push the element at top2-1.
    if top1 < top2-1:
        top2-=1
        a[top2] = x

#Function to remove an element from top of the stack1.
def pop1(a):
    
    #if top1==-1, stack1 is empty so we return -1 else we 
    #return the top element of stack1.
    global top1
    if top1 == -1:
        return -1
    else:
        val = a[top1]
        top1-=1
        return val



#Function to remove an element from top of the stack2.
def pop2(a):
    global top2
    
    #if top2==size of array, stack2 is empty so we return -1 else we 
    #return the top element of stack2.
    if top2 == 101:  
        return -1
    else:
        val = a[top2]
        top2+=1
        return val


import atexit
import io 
import sys 

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INNPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER

@atexit.register

def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())

top2 = 101
top1 = -1

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        n = int(input())
        arr = list(map(int,input().strip().split()))
        a = [-1 for i in range(101)]
        i = 0
        while i<len(arr):
            if arr[i] == 1:
                if arr[i+1] == 1:
                    push1(a,arr[i+2])
                else:
                    print(pop1(a),end=" ")
                i+=1
            else:
                if arr[i+1] == 1:
                    push2(a,arr[i+2])
                    i+=1
                else:
                    print(pop2(a),end=" ")
                i+=1
            i+=1
        top2 = 101
        top1 = -1
        print(' ')