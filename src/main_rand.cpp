#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdexcept>

//Include the header
#include "randomized_queue.h"

using namespace std;

//Basic test to test the operations
void basic_test() {
	int i;
	RandomizedQueue<int> q;
	RandomizedQueue<int>::Iterator itr;
	
	cout << "Basic Test" << endl;
	cout << "------------------------------" << endl;

	//Add elements
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6);
	q.enqueue(7);
	q.enqueue(8);
	q.enqueue(9);
	q.enqueue(10);

	//Traversal by iterator
	itr = q.iterator();
	//Return size
	cout << "RandomizedQueue of size: " << q.size() << endl;
	cout << "RandomizedQueue contains: ";
	for(i = 0; i < q.size(); i++, ++itr) {
		cout << (*itr) << " ";
	}
	cout << endl;
	
	//Remove elements
	cout << "Removing: " << q.dequeue() << endl;
	cout << "Removing: " << q.dequeue() << endl;
	cout << "Removing: " << q.dequeue() << endl;
	cout << "Removing: " << q.dequeue() << endl;
	cout << "Removing: " << q.dequeue() << endl;
	cout << "Removing: " << q.dequeue() << endl;

	//Traversal by iterators again
	itr = q.iterator();
	cout << "RandomizedQueue of size: " << q.size() << endl;
	cout << "RandomizedQueue contains: ";
	for(i = 0; i < q.size(); i++, ++itr) {
		cout << (*itr) << " ";
	}
	cout << endl;

	//Remove elemenets
	cout << "Removing: " << q.dequeue() << endl;
	cout << "Removing: " << q.dequeue() << endl;
	cout << "Removing: " << q.dequeue() << endl;
	cout << "Removing: " << q.dequeue() << endl;

	//Return size
	cout << "RandomizedQueue of size: " << q.size() << endl;
	
	cout << "------------------------------" << endl;
	cout << "End of the Basic Test" << endl;
	cout << endl;
}

//Exception test to test the use of exception
void exception_test() {
	int i;
	RandomizedQueue<int> q;
	RandomizedQueue<int>::Iterator itr;
	
	cout << "Exception Test" << endl;
	cout << "------------------------------" << endl;
	
	//Add elements
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6);
	q.enqueue(7);
	q.enqueue(8);
	q.enqueue(9);
	q.enqueue(10);
	
	//Traversal by iterator
	itr = q.iterator();
	cout << "RandomizedQueue of size: " << q.size() << endl;
	cout << "RandomizedQueue contains: ";
	for(i = 0; i < q.size(); i++, ++itr) {
		cout << (*itr) << " ";
	}
	cout << endl;
	//Iterator overflow
	try {
		itr++;
	}
	catch(runtime_error &e) {
		cout << "Exception caught: " << e.what() << '\n';
	}

	cout << "RandomizedQueue contains: ";
	cout << endl;
	//Dereference the past the end element
	for(i = 0; i < q.size(); i++, --itr) {
		try {
			cout << (*itr) << " ";
		}
		catch(runtime_error &e) {
			cout << "Exception caught: " << e.what() << '\n';
		}
	}
	cout << endl;
	//Iterator underflow
	try {
		itr--;
	}
	catch(runtime_error &e) {
		cout << "Exception caught: " << e.what() << '\n';
	}

	//Remove all the elements
	cout << "Removing: " << q.dequeue() << endl;
	cout << "Removing: " << q.dequeue() << endl;
	cout << "Removing: " << q.dequeue() << endl;
	cout << "Removing: " << q.dequeue() << endl;
	cout << "Removing: " << q.dequeue() << endl;
	cout << "Removing: " << q.dequeue() << endl;
	cout << "Removing: " << q.dequeue() << endl;
	cout << "Removing: " << q.dequeue() << endl;
	cout << "Removing: " << q.dequeue() << endl;
    cout << "Removing: " << q.dequeue() << endl;

    //Remove element from an empty queue
	try {
	cout << "Removing: " << q.dequeue() << endl;
	}
	catch(runtime_error& e) {
		cout << "Exception caught: " << e.what() << '\n';
	}
	
	cout << "------------------------------" << endl;
	cout << "End of the Exeception Test" << endl;
}

int main(){
	//Initialize the random number generator
	srand(time(0));
	basic_test();
	exception_test();
}
