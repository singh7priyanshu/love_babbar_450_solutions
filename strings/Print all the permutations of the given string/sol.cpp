/*
Print all the permutations of the given string

Given a string S. The task is to print all permutations of a given string in 
lexicographically sorted order.

 

Example 1:

Input: ABC
Output:
ABC ACB BAC BCA CAB CBA
Explanation:
Given string ABC has permutations in 6 
forms as ABC, ACB, BAC, BCA, CAB and CBA .
Example 2:

Input: ABSG
Output:
ABGS ABSG AGBS AGSB ASBG ASGB BAGS 
BASG BGAS BGSA BSAG BSGA GABS GASB 
GBAS GBSA GSAB GSBA SABG SAGB SBAG 
SBGA SGAB SGBA
Explanation:
Given string ABSG has 24 permutations.
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function 
find_permutaion() which takes the string S as input parameter and returns a vector of 
string in lexicographical order.

 

Expected Time Complexity: O(n! * n)

Expected Space Complexity: O(n)

 

Constraints:
1 <= length of string <= 5

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
		vector<string>find_permutation(string S){
		    vector<string>res;
		    sort(S.begin(), S.end());
		    do{
		        res.push_back(S);
		    }while(next_permutation(S.begin(), S.end()));
		    return res;
		}
};

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        vector<string>ans = ob.find_permutation(S);
        for(auto i: ans){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}