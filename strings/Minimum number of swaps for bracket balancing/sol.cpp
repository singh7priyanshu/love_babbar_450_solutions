/*
Minimum number of swaps for bracket balancing.

You are given a string S of 2N characters consisting of N ‘[‘ brackets and N ‘]’ brackets. 
A string is considered balanced if it can be represented in the for S2[S1] where S1 and S2 
are balanced strings. We can make an unbalanced string balanced by swapping adjacent 
characters. Calculate the minimum number of swaps necessary to make a string balanced.
Note - Strings S1 and S2 can be empty.

 

Example 1:

Input  : []][][
Output : 2
Explanation :
First swap: Position 3 and 4
[][]][
Second swap: Position 5 and 6
[][][]

 

Example 2:

Input : [[][]]
Output : 0 
Explanation:
String is already balanced.
 

Your Task:

You don't need to read input or print anything. Your task is to complete the function 
minimumNumberOfSwaps() which takes the string S and return minimum number of operations 
required to balance the bracket sequence.

 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

 

Constraints:

1<=|S|<=100000
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int minimumNumberOfSwaps(string S){
        int swap = 0, imbalance = 0, countLeft = 0, countRight = 0;
        int sizeofArray = S.size();
        for(int i = 0;i<sizeofArray;i++){
            if(S[i] == '['){
                countLeft++;
                if(imbalance > 0){
                    swap += imbalance;
                    imbalance--;
                }
            }
            else if(S[i] == ']'){
                countRight++;
                imbalance = (countRight-countLeft);
            }
        }
        return swap;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        string S; cin>>S;
        Solution ob;
        cout<<ob.minimumNumberOfSwaps(S)<<endl;
    }
    return 0;
}