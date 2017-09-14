#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdexcept>

//Include the header
#include "deque.h"

using namespace std;

//Basic test to test the operations
void basic_test() {
	int i;
	Deque<int> q;
	Deque<int>::Iterator itr;
	
	cout << "Basic Test" << endl;
	cout << "------------------------------" << endl;
	
	//Add elements
	q.addLast(1);
	q.addFirst(2);
	q.addFirst(3);
	q.addFirst(4);
	q.addFirst(5);
	q.addFirst(6);
	q.addFirst(7);
	q.addFirst(8);
	q.addFirst(9);
	q.addFirst(10);
	
	//Traversal by iterator
	itr = q.iterator();
	//Return size
	cout << "Deque of size: " << q.size() << endl;
	cout << "Deque contains: ";
	for(i = 0; i < q.size(); i++, ++itr) {
		cout << (*itr) << " ";
	}
	cout << endl;
	
	//Remove elements
	cout << "Removing: " << q.removeFirst() << endl;
	cout << "Removing: " << q.removeFirst() << endl;
	cout << "Removing: " << q.removeLast() << endl;
	cout << "Removing: " << q.removeLast() << endl;
	cout << "Removing: " << q.removeFirst() << endl;
	cout << "Removing: " << q.removeLast() << endl;

	//Traversal by iterators again
	itr = q.iterator();
	cout << "Deque of size: " << q.size() << endl;
	cout << "Deque contains: ";
	for(i = 0; i < q.size(); i++, ++itr) {
		cout << (*itr) << " ";
	}
	cout << endl;
	
	//Remove elemenets
	cout << "Removing: " << q.removeFirst() << endl;
	cout << "Removing: " << q.removeFirst() << endl;
	cout << "Removing: " << q.removeLast() << endl;
	cout << "Removing: " << q.removeLast() << endl;

	//Return size
	cout << "Deque of size: " << q.size() << endl;
	
	cout << "------------------------------" << endl;
	cout << "End of the Basic Test" << endl;
	cout << endl;
}

//Exception test to test the use of exception 
void exception_test() {
	int i;
	Deque<int> q;
	Deque<int>::Iterator itr;
	
	cout << "Exception Test" << endl;
	cout << "------------------------------" << endl;
	
	//Add elements
	q.addFirst(1);
	q.addFirst(2);
	q.addFirst(3);
	q.addFirst(4);
	q.addFirst(5);
	q.addFirst(6);
	q.addFirst(7);
	q.addFirst(8);
	q.addFirst(9);
	q.addFirst(10);
	
	//Traversal by iterator
	itr = q.iterator();
	cout << "Deque of size: " << q.size() << endl;
	cout << "Deque contains: ";
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

	cout << "Deque contains: ";
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
	//Iterator underflow
	cout << endl;
	try {
		itr--;
	}
	catch(runtime_error &e) {
		cout << "Exception caught: " << e.what() << '\n';
	}

	//Remove all the elements
	cout << "Removing: " << q.removeFirst() << endl;
	cout << "Removing: " << q.removeFirst() << endl;
	cout << "Removing: " << q.removeFirst() << endl;
	cout << "Removing: " << q.removeFirst() << endl;
	cout << "Removing: " << q.removeFirst() << endl;
	cout << "Removing: " << q.removeFirst() << endl;
	cout << "Removing: " << q.removeFirst() << endl;
	cout << "Removing: " << q.removeFirst() << endl;
	cout << "Removing: " << q.removeFirst() << endl;
    cout << "Removing: " << q.removeFirst() << endl;

    //Remove element from an empty queue
	try {
		cout << "Removing: " << q.removeFirst() << endl;
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
