#include <cstring> 
#include <iostream>

using namespace std;

/*
Equidivisions (UVa 11110)

Authors Ian Blake and Seth Kuller 
March 22nd 2013 

For this problem we were given a matrix as input and had to tell whether 
or not the matrix ﬁt a speciﬁc conﬁguration. That was that each of n 
numbers appeared only n times and were all adjacent to other numbers of 
the same type. Our approach was ﬁrst just to read in the matrix as a two 
dimensional array. We then had a recursive method that would take the matrix 
and a starting number and check the ﬁrst space in the matrix for the 
starting number. It would then check the spaces around that number, 
respecting bounds. As it found new instances of the starting number it would 
set them to -1 to avoid repetition. If this method found 5 instances of the 
starting number it would recurse with the next number (starting number + 1). 
If it found a break at any point, a number with no others like it around it, 
or did not ﬁnd enough of the starting number, it would set a global boolean to 
false and the recursion would be over. If the method reached the last value (n) 
That boolean would remain true and the matrix is good. We had a problem that 
we couldn’t solve where this approach worked for every number but n, (5 for this case). 
The counter would over count at the last number and, for example with 5, we would end 
up with 17, which seemed to suggest that the counting loop was running multiple times 
without resetting the 5’s (or ns) to -1. Dr Mayﬁeld took a brief look at this one and 
couldn’t ﬁgure out why that was. He suggested we reworke the whole method and I’m 
thinking I’ll have to do just that because I haven’t been able to salvage what we 
have, still having an issue at n.

SOLUTION CORRECT : NO
*/

// 0 < N < 100 
int n; 
int AdjMat [100][100]; 
bool good;

void output_calc(int start_num) 
{ 
	int counter = 1; 
	int start = 0;

	for(int i = 0; i <= n; i++) 
	{ 
	if(AdjMat[start][0] == start_num) 
		break; 
	//else 
		//start++; 
	}
	
	for(int i = start; i <= n; i++)
	{
		for(int j = 0; j <= n; j++) 
		{ 
			if(AdjMat[i][j] == start_num) 
			{ 
				if(AdjMat[i + 1][j] == start_num) 
				{ 
					counter++; AdjMat[i][j] = 0; 
				} 
				if(AdjMat[i][j + 1] == start_num) 
				{ 
					counter++; AdjMat[i][j] = 0; 
				} 
				if(AdjMat[i][j - 1] == start_num) 
				{ 
					counter++; AdjMat[i][j] = 0; 
				} 
				if(AdjMat[i - 1][j] == start_num) 
				{ 
					counter++; 
					AdjMat[i][j] = 0; 
				} 
				else 
					AdjMat[i][j] = 0; 
			} 
		}
	}
	
	if(counter == n) 
	{ 
		if(start_num == n) 
			good = true; 
		else 
			output_calc(start_num + 1); 
	} 
	else good = false;
}
	
int main() 
{ 
	int part, pair; 
	int i, j;
	
	while (true) 
	{ 
		//get the next test case 
		cin >> n;
		if (n == 0) 
			break;
		
		//initialize the matrix, verify that you know Kung-fu and are the one. 
		memset(AdjMat , 0, sizeof(AdjMat)); 
		
		for (part = 1; part < n; part++) 
		{ 
			for (pair = 1; pair <= n; pair++) 
			{ 
				cin >> i >> j; 
				AdjMat[i][j] = part; 
			} 
		} 
		for(int i = 0; i <= n; i++) 
		{ 
			for(int j = 0; j <= n; j++) 
			{ 
				if(AdjMat[i][j] == 0) 
					AdjMat[i][j] = n; 
			} 
		} 
			
		output_calc(1);
	
		if(good)
			cout << "goood" << endl;
		else
			cout << "wrong" << endl;
	}
}