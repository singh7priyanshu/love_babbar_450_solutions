/*
Coin game winner where every player has three choices

A and B are playing a game. At the beginning there are n coins. 
Given two more numbers x and y. In each move a player can 
pick x or y or 1 coins. 
A always starts the game. 
The player who picks the last coin wins the game or the 
person who is not able to pick any coin loses the game. 

For a given value of n, find whether A will win the game
or not if both are playing optimally.

Examples: 

Input :  n = 5, x = 3, y = 4
Output : A
There are 5 coins, every player can pick 1 or
3 or 4 coins on his/her turn.
A can win by picking 3 coins in first chance.
Now 2 coins will be left so B will pick one 
coin and now A can win by picking the last coin.

Input : 2 3 4
Output : B

Let us take few example values of n for x = 3, y = 4. 
n = 0 A can not pick any coin so he losses 
n = 1 A can pick 1 coin and win the game 
n = 2 A can pick only 1 coin. Now B will pick 1 coin and win the game 
n = 3 4 A will win the game by picking 3 or 4 coins 
n = 5, 6 A will choose 3 or 4 coins. Now B will have to choose 
    from 2 coins so A will win.
We can observe that A wins game for n coins only when B loses 
    for coins n-1 or n-x or n-y. 

*/
// C++ program to find winner of game
// if player can pick 1, x, y coins
#include <bits/stdc++.h>
using namespace std;
 
// To find winner of game
bool findWinner(int x, int y, int n)
{
    // To store results
    int dp[n + 1];
 
    // Initial values
    dp[0] = false;
    dp[1] = true;
 
    // Computing other values.
    for (int i = 2; i <= n; i++) {
 
        // If A losses any of i-1 or i-x
        // or i-y game then he will
        // definitely win game i
        if (i - 1 >= 0 and !dp[i - 1])
            dp[i] = true;
        else if (i - x >= 0 and !dp[i - x])
            dp[i] = true;
        else if (i - y >= 0 and !dp[i - y])
            dp[i] = true;
 
        // Else A loses game.
        else
            dp[i] = false;
    }
 
    // If dp[n] is true then A will
    // game otherwise  he losses
    return dp[n];
}
 
// Driver program to test findWinner();
int main()
{
    int x = 3, y = 4, n = 5;
    if (findWinner(x, y, n))
        cout << 'A';
    else
        cout << 'B';
 
    return 0;
}
/*
Output: 

A
*/