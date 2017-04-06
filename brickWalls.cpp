#include <iostream>

using namespace std;

/*
Brick Wall Patterns (UVa 900)
https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=841
 
Author Ian Blake 
April 6 th 2013 

This problem was harder then I had original thought, mostly because 
of formatting but also logically. The problem gives you a number, n, 
and tasks you to ﬁgure out how many possible arrangements of n bricks, 
the wall was limited to 2 high. At ﬁrst the problem seemed like n = n. 
Which I should have realized was far to simplistic but I tried it anyway. 
Eventually I decided to make brick arrangements by hand for 1 to 5 and a 
modiﬁed ﬁbonocci sequence emerged. From here the logic was fairly simple. 
The main problem emerged when trying to deal with maximum input size, 
which was 50. The 50th number in this sequence far overﬂowed ints and 
unsigned ints. It ﬁt in ﬂoats but cout prints ﬂoats in scientiﬁc notation 
if they are large enough so I had to ﬁgure out how to set the precision for cout, 
which is what the cout.precision(100) line does. This solution was wrong according 
to UVa so I thought there might have been precision loss using ﬂoats instead of 
doubles so I tried it with doubles and it worked.

SOLUTION CORRECT : YES
*/ 

double fibo (double position) 
{ 
	double base = 1; 
	double pivot = 0; 
	double temp; 
	double count;
	
	while (count < position) 
	{ 
		temp = base; 
		base = base + pivot; 
		pivot = temp; 
		count ++; 
	}
	
	return base;
}
	
int main () 
{ 
	double bricks = 99999; 
	while (true) 
	{ 
		cin >> bricks; 
		if (bricks > 0) { 
			cout.precision(100); 
			cout << fibo(bricks) << endl; 
		}
		else 
		{ 
			break; 
		}
	}
}
