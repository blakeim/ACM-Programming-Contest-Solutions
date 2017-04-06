#include <iostream>

using namespace std; 

/* 
The 3n + 1 problem (UVa 100)
https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=36

Author Ian Blake
April 2013

For this problem I was given a set of numbers, two per line and tasked 
to ﬁnd the maximum cycle length of the numbers between them using a 
prescribed algorithm. Getting the input was fairly simple and the 
algorithm was given, so the diﬃcult part was deciding where to execute 
the algorithm as well as keeping track of it. One surprisingly big issue 
for this problem was deciding where to reset values and use temporary 
values, the problem required a lot of temporary values. My Approach was 
just to ﬁnd the greater of the two numbers, then start at that one and 
loop until the smaller one, on each pass running the algorithm on the 
current number, then decrementing the number by one and so on until the 
smaller number is reached. At the end I compared the cycle length of that 
number to the current max cycle length. As far as I can tell this problem 
works and I’ve tested it heavily, however I can’t get it past the UVa 
submission system, all I can think is that there’s some obscure test case 
that I’m not thinking of, I tried as many situations as I could think of 
without trying every possibility.

SOLUTION CORRECT : NO
*/ 

int main() 
{ 
	int i; 
	int j; 
	int cycle; 
	int tempCycle; 
	int pivot1; 
	int pivot2; 
	int cycleLength = 0; 
	int tempCycleLength = 0;

	while(!cin.eof()) 
	{ 
		cin >> i; 
		cin >> j;
		if(i < j) 
		{
			pivot1 = j; 
			pivot2 = i;
		}	
		else
		{
			pivot1 = i; 
			pivot2 = j;
		}

		cycle = pivot1; 
		cycleLength = 0;

		while(cycle >= pivot2)
		{
			tempCycleLength = 0; 
			tempCycle = cycle;
			
			while(true) 
			{ 
				if(tempCycle <= 1) 
				{ 
					tempCycleLength++; 
					break; 
				} 
				if((tempCycle % 2) != 0) 
				{ 
					tempCycle = ((3 * tempCycle) + 1); 
				} 
				else 
				{ 
					tempCycle = (tempCycle / 2); 
				}
				
				tempCycleLength++;
			}
	
			cycle --;
	
			if(tempCycleLength > cycleLength) 
			{ 
				cycleLength = tempCycleLength; 
			}
		}
	
		cout << i << " " << j << " "; 
		cout << cycleLength << endl;
	}
}