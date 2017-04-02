#include <iostream> 
#include <sstream> 
#include <string> 
#include <map>

using namespace std;

/*
List of Conquests (UVa 10420)

Author Ian Blake
April 26th 2013 

At ﬁrst I approached this problem completely the wrong way. I was using 
a string stream to read in each word on each line and counting them as 
individual conquests. When that gave me not only the wrong answers but 
more output lines then i was expecting I reevaluated my approach and 
reread the problem and decided to use a const char* to int map and just 
count the number of times the keys appeared and basically ignore the whole 
line. Const char* map wasn’t working for whatever reason, i was getting 
huge compile errors so I changed it to strings and everything went 
swimmingly from there. Really the approach was pretty straight forward. 
I was hung up on how to print the map values however and had to look that 
up. This was a helpful problem in that it taught me something about iterators.

SOLUTION CORRECT : YES
*/

int main() 
{ 
	map<string , int> m; 
	string curr_country; 
	string line; 
	int lines;

	cin >> lines;

	while(lines > 0) 
	{ 
		cin >> curr_country; 
		getline(cin, line); 
		
		m[curr_country]++; 
		
		lines --; 
	}

	for(map<string,int>::iterator i = m.begin(); i != m.end(); i++) 
	{ 
		cout << i->first << " " << i->second; 
		cout << endl; 
	}
}
