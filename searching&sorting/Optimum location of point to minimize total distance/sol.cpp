/*
Optimum location of point to minimize total distance

Given a set of points as and a line as ax+by+c = 0. We need to find a point on given line for 
which sum of distances from given set of points is minimum. 

If we take one point on given line at infinite distance then total distance cost will be 
infinite, now when we move this point on line towards given points the total distance cost 
starts decreasing and after some time, it again starts increasing which reached to infinite 
on the other infinite end of line so distance cost curve looks like a U-curve and we have to 
find the bottom value of this U-curve. 

As U-curve is not monotonically increasing or decreasing we can’t use binary search for finding 
bottom most point, here we will use ternary search for finding bottom most point, ternary search 
skips one third of search space at each iteration.

A ternary search algorithm is a technique in computer science for finding the minimum or 
maximum of a unimodal function. A ternary search determines either that the minimum or maximum 
cannot be in the first third of the domain or that it cannot be in the last third of the domain, 
then repeats on the remaining two thirds. A ternary search is an example of a 
divide and conquer algorithm

The function
Assume we are looking for a maximum of f(x) and that we know the maximum lies somewhere 
between A and B. For the algorithm to be applicable, there must be some value x such that

for all a,b with A ≤ a < b ≤ x, we have f(a) < f(b), and
for all a,b with x ≤ a < b ≤ B, we have f(a) > f(b).

Algorithm
Let f(x) be a unimodal function on some interval [l; r]. Take any two points m1 and m2 in 
this segment: l < m1 < m2 < r. Then there are three possibilities:

if f(m1) < f(m2), then the required maximum can not be located on the left side - [l; m1]. 
    It means that the maximum further makes sense to look only in the interval [m1;r]
if f(m1) > f(m2), that the situation is similar to the previous, up to symmetry. Now, 
    the required maximum can not be in the right side - [m2; r], so go to the segment [l; m2]
if f(m1) = f(m2), then the search should be conducted in [m1; m2], but this case can be 
    attributed to any of the previous two (in order to simplify the code). Sooner or later the 
    length of the segment will be a little less than a predetermined constant, and the 
    process can be stopped.

choice points m1 and m2:

m1 = l + (r-l)/3
m2 = r - (r-l)/3
Run time order
{\displaystyle T(n)=T(2n/3)+1=\Theta (\log n)}T(n)=T(2n/3)+1=\Theta (\log n)

Recursive algorithm
def ternary_search(f, left, right, absolute_precision) -> float:
    """Left and right are the current bounds;
    the maximum is between them.
    """
    if abs(right - left) < absolute_precision:
        return (left + right) / 2

    left_third = (2*left + right) / 3
    right_third = (left + 2*right) / 3

    if f(left_third) < f(right_third):
        return ternary_search(f, left_third, right, absolute_precision)
    else:
        return ternary_search(f, left, right_third, absolute_precision)



So solution proceeds as follows, we start with low and high initialized as some smallest and 
largest values respectively, then we start iteration, in each iteration we 
calculate two mids, mid1 and mid2, which represent 1/3rd and 2/3rd position in search space, 
we calculate total distance of all points with mid1 and mid2 and update low or high by 
comparing these distance cost, this iteration continues until low and high 
become approximately equal. 


*/

// C/C++ program to find optimum location and total cost
#include <bits/stdc++.h>
using namespace std;
#define sq(x) ((x) * (x))
#define EPS 1e-6
#define N 5

// structure defining a point
struct point {
	int x, y;
	point() {}
	point(int x, int y): x(x), y(y) {}
};

// structure defining a line of ax + by + c = 0 form
struct line {
	int a, b, c;
	line(int a, int b, int c) : a(a), b(b), c(c) {}
};

// method to get distance of point (x, y) from point p
double dist(double x, double y, point p)
{
	return sqrt(sq(x - p.x) + sq(y - p.y));
}

/* Utility method to compute total distance all points
	when choose point on given line has x-coordinate
	value as X */
double compute(point p[], int n, line l, double X)
{
	double res = 0;

	// calculating Y of chosen point by line equation
	double Y = -1 * (l.c + l.a * X) / l.b;
	for (int i = 0; i < n; i++)
		res += dist(X, Y, p[i]);

	return res;
}

// Utility method to find minimum total distance
double findOptimumCostUtil(point p[], int n, line l)
{
	double low = -1e6;
	double high = 1e6;

	// loop until difference between low and high
	// become less than EPS
	while ((high - low) > EPS) {
		// mid1 and mid2 are representative x co-ordiantes
		// of search space
		double mid1 = low + (high - low) / 3;
		double mid2 = high - (high - low) / 3;

		//
		double dist1 = compute(p, n, l, mid1);
		double dist2 = compute(p, n, l, mid2);

		// if mid2 point gives more total distance,
		// skip third part
		if (dist1 < dist2)
			high = mid2;

		// if mid1 point gives more total distance,
		// skip first part
		else
			low = mid1;
	}

	// compute optimum distance cost by sending average
	// of low and high as X
	return compute(p, n, l, (low + high) / 2);
}

// method to find optimum cost
double findOptimumCost(int points[N][2], line l)
{
	point p[N];

	// converting 2D array input to point array
	for (int i = 0; i < N; i++)
		p[i] = point(points[i][0], points[i][1]);

	return findOptimumCostUtil(p, N, l);
}

// Driver code to test above method
int main()
{
	line l(1, -1, -3);
	int points[N][2] = {
		{ -3, -2 }, { -1, 0 }, { -1, 2 }, { 1, 2 }, { 3, 4 }
	};
	cout << findOptimumCost(points, l) << endl;
	return 0;
}

/*
Output
20.7652

*/