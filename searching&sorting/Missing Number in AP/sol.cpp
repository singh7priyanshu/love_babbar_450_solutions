/*
Missing Number in AP

Given three integers  'A' denoting the first term of an arithmetic sequence,
'C' denoting the common difference of an arithmetic sequence and an integer 
'B'. you need to tell whether 'B' exists in the arithmetic sequence or not.

Example 1:

Input: A = 1, B = 3, C = 2
Output: 1
Explaination: 3 is the second term of the 
sequence starting with 1 and having a common 
difference 2.
Example 2:

Input: A = 1, B = 2, C = 3
Output: 0
Explaination: 2 is not present in the sequence.
Your Task:
You do not need to read input or print anything. Your task is to complete the 
function inSequence() which takes A, B and C and returns 1 if B is present in 
the sequence. Otherwise, returns 0.

Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)

Constraints:
-109 ≤ A, B, C ≤ 109  
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int inSequence(int A, int B, int C){
        int d = (B-A);
        if(d==0)return 1;
        if(d<0){
            if(C>=0)return 0;
            if(d%C == 0)return 1;
            return 0;
        }
        else{
            if(C<=0)return 0;
            if(d%C == 0)return 1;
            return 0;
        }
        return 0;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int A, B, C;
        cin>>A>>B>>C;
        Solution ob;
        cout<<ob.inSequence(A, B, C)<<endl;
    }
    return 0;
}