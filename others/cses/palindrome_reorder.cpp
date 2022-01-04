	
/*

Given a string, your task is to reorder its letters in such a way that it becomes a palindrome (i.e., it reads the same forwards and backwards).

Input

The only input line has a string of length n consisting of characters A–Z.

Output

Print a palindrome consisting of the characters of the original string. You may print any valid solution. If there are no solutions, print "NO SOLUTION".

Constraints
1≤n≤106
Example

Input:
AAAACACBA

Output:
AACABACAA

*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> a(26);
    for(char c : s) a[c - 'A']++;
    
    int check = 0;
    for(int i = 0; i < 26; i++) check += (a[i] % 2);
    //only one of the letters should be of odd frequency or all pair
    if(check > 1){
        cout << "NO SOLUTION";
        return 0;
    }
    //organize the palindrome
    string result;
    for (int i = 0; i < 26; i++){
        if(!(a[i]%2)){
            for(int j = 0; j < a[i]/2; j++) result.push_back(i + 'A');
        }
    }
    for (int i = 0; i < 26; i++){
        if(a[i]%2){
            for(int j = 0; j < a[i]; j++) result.push_back(i + 'A');
        }
    }
    for (int i = 25; i >= 0; i--){
        if(!(a[i]%2)){
            for(int j = 0; j < a[i]/2; j++) result.push_back(i + 'A');
        }
    }

    cout << result << endl;
    return 0;
}