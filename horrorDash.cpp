#include <iostream> 
#include <algorithm>

using namespace std;
/* 
Horror Dash (UVa 11799)

Author Ian Blake 
April 6 th 2013 

This problem was actually a lot easier then I thought it would be. 
The objective was to take a series of integers representing the 
speed of monsters and show how fast a clown would have to run to 
outrun all of them, but only barely. This basically amounted to 
picking the largest out of a series of numbers. There is probably a 
more eﬃcient way to do this but my solution works and it works reasonably 
quickly. Basically I just brought in the numbers and stored them in an array, 
the size of the array was dictated by the ﬁrst number in the line, then 
sorted the array and picked the last value out of it.

SOLUTION CORRECT : YES
*/ 

int main () 
{ 
	int * runners; 
	int clownSpeed; 
	int n; 
	int cases; 
	int i = 1; 
	int j;
	cin >> cases; 

	while(i <= cases) 
	{ 
		cin >> n; 
		runners = new int [ n ]; 
		j = 0; 
		
		while ( j < n ) 
		{ 
		cin >> runners [ j ]; 
		j++; 
		} 
		
		sort(runners , runners + n); 
		cout << " Case " << i << " : " ; 
		cout << runners [n -1] << endl ; 
		i++; 
	}
}
