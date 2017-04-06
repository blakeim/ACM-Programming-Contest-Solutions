#include <iostream>

using namespace std;

/* 
f91 (UVA 10696)
https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1637

Author Ian Blake 
April 26th 2013 

This problem seemed ripe for recursion. It actually tripped me up for 
a while because I was just treating the second condition as an else 
not as a speciﬁc case. In the end though the solution was right there 
in the problem, just had to look for it.

SOLUTION CORRECT : YES
*/

int f91(int n) 
{ 

	if(n <= 100) 
	{ 
		return f91(f91((n + 11))); 
	} 
	else if(n >= 101) 
	{ 
		return (n - 10); 
	}
}

int main() 
{ 
	int input = -1;

	while(input != 0) 
	{ 
		cin >> input;
		if(input != 0) 
		{ 
			cout << "f91(" << input << ") = " << f91(input); 
			cout << endl; 
		}
	}

	return 0;
}