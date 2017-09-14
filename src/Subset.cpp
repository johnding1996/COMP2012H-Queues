#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

//Include the header
#include "randomized_queue.h"

using namespace std;

int main(int argc, char ** argv) {
	//Initialize the random number generator
	srand(time(0));
	RandomizedQueue<string> rq;

	//Process command-line input
	if(argc < 2) {
		//No input
		cout << "Please specify an output number k! " << endl;
		exit();
	}
	
	//Initialize to -1
	int k = atoi(argv[2]);

	string s = "";
	while(1) {
		//Input strings
		cin >> s;
		//Check if it is the ending character
		if (s.compare("|")==0) {
			break;
		}
		//Enqueue if legal
		rq.enqueue(s);
	}

	//Input a legal size of the subset
	while ((k<0)||(k>rq.size())) {
		cout << "Please specify the size of the subset." << endl;
	    cin >> k;
	}

	//Output the subset by repeatively calling dequeue
	for (int i = 0; i<k; ++i) {
		cout << rq.dequeue() << endl;
	}

	return 0;
}