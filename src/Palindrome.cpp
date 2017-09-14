#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <ctime>

//Include the header
#include "deque.h"

using namespace std;

int main(){
	//Initialize the random number generator
	srand(time(0));
	Deque<char> q;
	char c = '\0';

	//Read in the chars
	while(1) {
		//Read in a single char
		c = getchar();
		if (c=='\n') break;
		//Omit all the spaces and returns
		if (c=='A'||c=='T'||c=='G'||c=='C') q.addFirst(c);
	}

	bool flag = true;
	for (int i = 0; i<(q.size()/2); ++i) {
		//Remove from the begining and the end symmetrically
		int tmp = q.removeFirst() + q.removeLast();
		//Check if it is A-T, G-C pairs by evaluate the sum of values
		if ((tmp != 149)&&(tmp != 138)) {
			flag = false;
			break;
		}
	}
	if (q.size()==0) flag = false;
	cout << (flag == true ? "true" : "false") << endl;

	
	return 0;
}