/*
Buy Maximum Stocks if i stocks can be bought on i-th day

In a stock market, there is a product with its infinite 
stocks. The stock prices are given for N days, where arr[i] 
denotes the price of the stock on the ith day. There is a 
rule that a customer can buy at most i stock on the ith day. 

If the customer has an amount of k amount of money initially, 
find out the maximum number of stocks a customer can buy. 

For example, for 3 days the price of a stock is given as 7, 10, 4. 
You can buy 1 stock worth 7 rs on day 1, 2 stocks worth 10 rs each 
on day 2 and 3 stock worth 4 rs each on day 3.

Examples: 

Input : price[] = { 10, 7, 19 }, 
              k = 45.
Output : 4
A customer purchases 1 stock on day 1, 
2 stocks on day 2 and 1 stock on day 3 for 
10, 7 * 2 = 14 and 19 respectively. Hence, 
total amount is 10 + 14 + 19 = 43 and number 
of stocks purchased is 4.

Input  : price[] = { 7, 10, 4 }, 
               k = 100.
Output : 6

The idea is to use greedy approach, where we should start 
buying product from the day when the stock price is least 
and so on. 

So, we will sort the pair of two values i.e { stock price, day } 
according to the stock price, and if stock prices are same, then 
we sort according to the day. 

Now, we will traverse along the sorted list of pairs, 
and start buying as follows: 

Let say, we have R rs remaining till now, and the cost of 
product on this day be C, and we can buy atmost L products 
on this day then, 
total purchase on this day (P) = min(L, R/C) 
Now, add this value to the answer. 
total purchase on this day (P) = min(L, R/C) 
Now, add this value to the answer 
total_purchase = total_purchase + P, where P =min(L, R/C) 
Now, subtract the cost of buying P items from remaining money, R = R – P*C. 
Total number of products that we can buy is equal to total_purchase.

Below is the implementation of this approach: 

*/
// C++ program to find maximum number of stocks that
// can be bought with given constraints.
#include <bits/stdc++.h>
using namespace std;

// Return the maximum stocks
int buyMaximumProducts(int n, int k, int price[])
{
	vector<pair<int, int> > v;

	// Making pair of product cost and number
	// of day..
	for (int i = 0; i < n; ++i)
		v.push_back(make_pair(price[i], i + 1));

	// Sorting the vector pair.
	sort(v.begin(), v.end());

	// Calculating the maximum number of stock
	// count.
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += min(v[i].second, k / v[i].first);
		k -= v[i].first * min(v[i].second,
							(k / v[i].first));
	}

	return ans;
}

// Driven Program
int main()
{
	int price[] = { 10, 7, 19 };
	int n = sizeof(price)/sizeof(price[0]);
	int k = 45;

	cout << buyMaximumProducts(n, k, price) << endl;

	return 0;
}

/*
Output: 

4
Time Complexity :O(nlogn).
*/