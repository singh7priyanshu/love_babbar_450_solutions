/*
895. Maximum Frequency Stack

Design a stack-like data structure to push elements to the 
stack and pop the most frequent element from the stack.

Implement the FreqStack class:

FreqStack() constructs an empty frequency stack.
void push(int val) pushes an integer val onto the top of the stack.
int pop() removes and returns the most frequent element in the stack.
If there is a tie for the most frequent element, the element closest 
to the stack's top is removed and returned.
 

Example 1:

Input
["FreqStack", "push", "push", "push", "push", "push", 
 "push", "pop", "pop", "pop", "pop"]
[[], [5], [7], [5], [7], [4], [5], [], [], [], []]

Output
[null, null, null, null, null, null, null, 5, 7, 5, 4]

Explanation
FreqStack freqStack = new FreqStack();
freqStack.push(5); // The stack is [5]
freqStack.push(7); // The stack is [5,7]
freqStack.push(5); // The stack is [5,7,5]
freqStack.push(7); // The stack is [5,7,5,7]
freqStack.push(4); // The stack is [5,7,5,7,4]
freqStack.push(5); // The stack is [5,7,5,7,4,5]
freqStack.pop();   // return 5, as 5 is the most frequent. 
    The stack becomes [5,7,5,7,4].
freqStack.pop();   // return 7, as 5 and 7 is the most frequent, 
    but 7 is closest to the top. The stack becomes [5,7,5,4].
freqStack.pop();   // return 5, as 5 is the most frequent. 
    The stack becomes [5,7,4].
freqStack.pop();   // return 4, as 4, 5 and 7 is the most frequent, 
    but 4 is closest to the top. The stack becomes [5,7].
 

Constraints:

0 <= val <= 109
At most 2 * 104 calls will be made to push and pop.
It is guaranteed that there will be at least one element in 
the stack before calling pop.

*/

class FreqStack {
public:
    //This will store the count of each element
    unordered_map<int,int> frequency;
    //This maps the elements which have same count
    //But the element that come last will come first of same count
    unordered_map<int,stack<int>> group_stack;
    //Maximum frequency possible
    int max_frequency=0;
    FreqStack() {
        
    }
    //Push elements in the stack
    void push(int val) {
        //Increment the count
        frequency[val]++;
        //Check is this element occurs maximum time
        max_frequency=max(max_frequency,frequency[val]);
        //Map the element with its count
        group_stack[frequency[val]].push(val);
    }
    
    int pop() {
        //Find the max occurence element
        int top_max_frequency=group_stack[max_frequency].top();
        //Remove it from stack
        group_stack[max_frequency].pop();
        //Decrement its count
        frequency[top_max_frequency]--;
        //If there is no element of maximum frquency the decrement max_frequency
        if(group_stack[max_frequency].size()==0)
            max_frequency--;
        return top_max_frequency;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */