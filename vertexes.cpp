#include <iostream> 
#include <cstdio>

using namespace std

/*
Vertex (UVa 280)  
https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=216

Author: Seth Kuller & Ian Blake 
Date: 03/15/2013 

This problem was meant to be an implementation of a shortest path algorithm. 
We were given input representing a directed graph. Each line gave us a 
starting edge and reachable edges from that point. Our approach was to create 
an adjancancy matrix for each case. We then made a single array for the 
numbers used in the test cases. We checked each number in the matrix against 
the test cases to see if they were reachable. This is another one we were 
having a peculiar problem with. It was reading everything in ﬁne and getting 
all the values back, but we couldn’t get it to print right. If it formatted 
right then the answer was wrong and if the answer was right then the formatting 
was wrong. We asked Dr Aboutabl about this and he said it could have had 
something to do with using cout as opposed to printf. We tried to set it up 
with printf but were having the same problem. It may have something to do 
with line-ﬂushing. Even after I’ve looked at it Im still not sure what’s going on.

SOLUTION CORRECT : NO
*/
int length(int*);

int main() 
{ 
	int n; 
	int cases;
	cin >> n;
	
	int matrix[n+1][n+1];
	
	for(int i = 0; i < n; i++) 
	{ 
		for(int j = 0; j <= n; j++) 
		{	 
			cin >> matrix[i][j]; 
				if(matrix[i][j] == 0) 
					break; 
		} 
	}

	int endEdge; 
	cin >> endEdge;

	if(endEdge == 0) 
	{ 
		cin >> cases; 
		for(int i = 0; i < cases; i++) 
		{ 
			int testVert; 
			cin >> testVert; 
			int usedNums[n]; 
			for(int j = 1; j < n+1; j++) 
			{ 
				int num; 
				num = matrix[testVert - 1][j]; 
				
				if (num == 0) break; 
				
				usedNums[j-1] = num; 
			} 
			
			int nonUsed = n - (sizeof(usedNums))); 
			cout << nonUsed;
			
			for(int j = 0; j < n; j++) 
			{ 
				int good = 0; 
				for(int k = 0; k < (sizeof(usedNums)/sizeof(int)); k++) 
				{ 
					if(matrix[j][0] == usedNums[k]) 
						good = 1; 
				} 
				if(good == 0) 
					cout << " " << matrix[j][0]; 
			} 
			
			cout << endl;
		}
	}
}