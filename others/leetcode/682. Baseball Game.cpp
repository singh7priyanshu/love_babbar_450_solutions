/*
682. Baseball Game

You are keeping score for a baseball game with strange rules. 
The game consists of several rounds, where the scores of past 
rounds may affect future rounds' scores.

At the beginning of the game, you start with an empty record. 
You are given a list of strings ops, where ops[i] is the ith 
peration you must apply to the record and is one of the 
following:

An integer x - Record a new score of x.
"+" - Record a new score that is the sum of the previous two 
    scores. It is guaranteed there will always be two previous 
    scores.
"D" - Record a new score that is double the previous score. 
    It is guaranteed there will always be a previous score.
"C" - Invalidate the previous score, removing it from the record. 
    It is guaranteed there will always be a previous score.
Return the sum of all the scores on the record. The test cases 
are generated so that the answer fits in a 32-bit integer.

 

Example 1:

Input: ops = ["5","2","C","D","+"]
Output: 30
Explanation:
"5" - Add 5 to the record, record is now [5].
"2" - Add 2 to the record, record is now [5, 2].
"C" - Invalidate and remove the previous score, record is now [5].
"D" - Add 2 * 5 = 10 to the record, record is now [5, 10].
"+" - Add 5 + 10 = 15 to the record, record is now [5, 10, 15].
The total sum is 5 + 10 + 15 = 30.
Example 2:

Input: ops = ["5","-2","4","C","D","9","+","+"]
Output: 27
Explanation:
"5" - Add 5 to the record, record is now [5].
"-2" - Add -2 to the record, record is now [5, -2].
"4" - Add 4 to the record, record is now [5, -2, 4].
"C" - Invalidate and remove the previous score, record is now [5, -2].
"D" - Add 2 * -2 = -4 to the record, record is now [5, -2, -4].
"9" - Add 9 to the record, record is now [5, -2, -4, 9].
"+" - Add -4 + 9 = 5 to the record, record is now [5, -2, -4, 9, 5].
"+" - Add 9 + 5 = 14 to the record, record is now [5, -2, -4, 9, 5, 14].
The total sum is 5 + -2 + -4 + 9 + 5 + 14 = 27.
Example 3:

Input: ops = ["1"]
Output: 1
 

Constraints:

1 <= ops.length <= 1000
ops[i] is "C", "D", "+", or a string representing an integer 
in the range [-3 * 104, 3 * 104].
For operation "+", there will always be at least two previous 
scores on the record.
For operations "C" and "D", there will always be at least one 
previous score on the record.
*/

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        for(auto it: ops){
            if(it == "+"){
                int num1 = st.top(); st.pop();
                int num2 = st.top();
                st.push(num1);
                st.push(num1+num2);
            }
            else if(it == "D")
                st.push(st.top()*2);
            
            else if(it== "C")
                st.pop();
            
            else
                st.push(stoi(it));       
        }
        int res = 0;
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        return res;
    }
};
/*
//by using vector 
class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> record;
        for (string ch : ops) {
            if (ch == "C")
                record.pop_back();
            else if (ch == "D")
                record.push_back(record.back() * 2);
            else if (ch == "+")
                record.push_back(record.back() + record[record.size() - 2]);
            else
                record.push_back(stoi(ch));
        }
        
        return accumulate(record.begin(), record.end(), 0);
    }
};
*/