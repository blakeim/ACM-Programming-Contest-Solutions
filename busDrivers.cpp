#include <iostream> 
#include <algorithm>

using namespace std;

/* 
Bus Drivers (UVa 11389)
Author: Ian Blake 
Feburary 2013 

To solve this problem, we were given a scenario with n bus drivers 
each given two routes that could not add up to more then r hours 
or the state would have to pay the drivers an extra d dollars per 
hour over. My goal was to create a program that would ensure that 
the state paid the least overtime each day. My approach to this 
problem was fairly straight forward. Since the morning routes 
were inconsequential I placed them in the ﬁrst array and sorted 
them from smallest to largest. The second route is what matters, 
so I put all of the PM routes into an array and sorted them 
smallest to largest. I then matched the farthest right 
value (largest) of the PM routes with the farthest left (smallest) 
of the AM routes. Then I continued inward recursively until I was 
done with the two lists. The problem speciﬁed that input would always 
contain n drivers and only n AM routes and n PM routes, so 
I didn’t take into account diﬀerently sized sets. 
The recursive function used is below.

SOLUTION CORRECT : YES
*/
void recurse(int possibleD) 
{ 
	int n; 
	int d; 
	int r; 
	int temp = 0; 
	int nextLine = -1;

	if(possibleD > -1) 
		n = possibleD; 
	else 
		cin >> n;
	
	cin >> d; 
	cin >> r;
	
	int *morn = new int[n]; 
	int *eve = new int[n];
	
	for(int i = 0; i < n; i++) 
	{ 
		cin >> morn[i]; 
	} 
	for(int i = 0; i < n; i++) 
	{ 
		cin >> eve[i]; 
	}
	
	sort(morn , morn + n); 
	sort(eve, eve + n);
	
	for(int i = 0; i < n; i++) 
	{ 
		if(morn[i] + eve[n-i - 1] > d) 
			temp += ((morn[i] + eve[n-i -1] - d) * r); 
	}
	
	cout << temp << endl;
	cin >> nextLine;
	
	if(nextLine > 0) 
		recurse(nextLine);
}

int main() 
{ 
	recurse(-1); 
	return 0; 
}
