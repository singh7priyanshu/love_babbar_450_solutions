/*
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

*/

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data',inputStdin =>{
    inputString += inputStdin;
});

process.stdin.on('end', _ =>{
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });
    main();
});

function readLine(){
    return inputSting[currentLine++];
}

function main(){
    let t = parseInt(readLine());
    let i = 0;
    for(;i<t;i++){
        let sq = new TwoStacks();
        let q = parseInt(readLine());
        let input_ar1 = readLine().split(' ').map(x => parseInt(x));
        let index = 0;
        let res = '';
        while(q--){
            let stack_no = input_ar1[index++];
            let QueryType = input_ar1[index++];
            if(QueryType == 1){
                let a = input_ar1[index++];
                if(stack_no == 1)sq.push1(a);
                else sq.push2(a);
            }else{
                if(stack_no == 1)res+=sq.pop()+" ";
                else res+=sq.pop2()+" ";
            }
        }
        console.log(res);
    }
}

class TwoStacks
{
    
    constructor(){
        this.arr = new Array(100);
        this.size = 100;
        this.top1 = -1;
        this.top2 = 100;
    }
    
    //Function to push an integer into the stack1.
    push1(x)
    {
        //if there is space between the top of both stacks 
        //we push the element at top1+1.
        if (this.top1 < this.top2 - 1)
        {
           this.top1++;
           this.arr[this.top1] = x;
        }
    }
    
    //Function to push an integer into the stack2.
    push2(x)
    {
        //if there is space between the top of both stacks 
        //we push the element at top2-1.
        if (this.top1 < this.top2 - 1)
        {
           this.top2--;
           this.arr[this.top2] = x;
        }
    }

    //Function to remove an element from top of the stack1.
    pop1()
    {
        //if top1==-1, stack1 is empty so we return -1 else we 
        //return the top element of stack1.
        if (this.top1 >= 0 )
        {
            let x = this.arr[this.top1];
            this.top1--;
            return x;
        }
        else
            return -1;
    }
    
    //Function to remove an element from top of the stack2.
    pop2()
    {
        //if top2==size of the array, stack2 is empty so we return -1 else we 
        //return the top element of stack2.
        if (this.top2 < this.size)
        {
            let x = this.arr[this.top2];
            this.top2++;
            return x;
        }
        else
          return -1;
    }
}