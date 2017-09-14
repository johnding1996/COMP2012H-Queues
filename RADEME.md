# Queues
Project 3 for COMP2012H, 2016 Fall, HKUST

A simple implementation of dequeue and randomized queue data sturctures


## How-to-compile-and-run
```
$ make
$ ./bin/rand_test
$ ./bin/deque_test
$ ./bin/Subset
$ ./bin/Palindrome
```

## Technical Details
Source file tree:
```
    Queues
    |
    |--dequeue
    |  |--deque.h
    |
    |--randomized_queue
    |  |--randomized_queue.h
    |
    |--src
    |  |--main_deque.cpp
    |  |--main_rand.cpp
    |  |--Palindrome.cpp
    |  |--Subset.cpp
    |
    |--Makefile
```


## Q&A
```
/**********************************************************************
 *  Explain briefly how you implemented the randomized queue and deque.
 *  Which data structure did you choose (array, linked list, etc.)
 *  and why?
 **********************************************************************/
The deque is implemented by double-linked list. Since it automatically support constant time insertion and deletion at the two ends of the queue.
The randomized queue is implemented by dynamic array. Since it must support amotized constant time random access.


/**********************************************************************
 *  Briefly describe why any sequence of N randomized queue operations,
 *  starting from an empty randomized queue, takes O(N) time.
 **********************************************************************/
List of all the operations:
enqueue:
    This operation involves two part: insert and adjust the size. Inserting is simply to place the item at the last position of the array and is O(1). Adjusting the size is O(N) when the randomized queue needs to enlarge itself. If we need to enlarge the array, suppose the size before enlarging is k, there should be at least k/2 enqueue operations. So that the adjustment is amortized O(1) time.
dequeue:
    This operation also involves two part: delete and ajust the size. Delete involves swaping the element to delete with the last element of array and then release the last element of array. So it is O(1) time complexity. Similarly, adjusting is amortized O(1) time.
isEmpty, size:
    Clearly O(1).
sample:
    A random number is generated. And the corresponding element is returned. So it is O(1).
Each operation is O(1) amortized. So any sequence of N randomized queue operations, starting from an empty randomized queue, takes O(N) time.

/**********************************************************************
 *  Briefly describe why each Deque operation takes O(1) time.
 **********************************************************************/
List of all the operations:
addFirst, addLast:
    Can be achieved by several pointer manipulation, which are all O(1).
removeFirst, removeLast:
    Similar to the inserting. In total O(1).
isEmpty, size:
    Clearly O(1).



/**********************************************************************
 *  How much memory (in bytes) does your data type use to store N items.
 *  Use tilde notation to simplify your answer. Use the memory requirements
 *  for a "typical machine" given in Lecture. In your analysis, don't include
 *  the memory for the items themselves (as this memory is allocated by
 *  the client and depends on the item type.
 *  For a typical machine, refer to page 11 of 
 *  https://www.cs.princeton.edu/courses/archive/spr10/cos226/lectures/02-14Analysis-2x2.pdf
 **********************************************************************/
In a 32-bit machine

RandomizedQueue:
object overhead: 8 bytes
array T**: 4 bytes
length int: 4 bytes
capacity int: 4 bytes

Overall: 20 bytes

Dequeue:
object overhead: 8 bytes
begin Node*: 4 bytes 
end Node*: 4 bytes
length int: 4 bytes

Overall: 20 bytes


/**********************************************************************
 *  Known bugs / limitations.
 **********************************************************************/
Limitation:
1, Generating random number using the symbolic constant RAND_MAX, which gives a upper limit of the length and size of the dynamic array in the randomized queue.
2, Clearly, the indices are stored are int type number, have certain range.

/**********************************************************************
 *  List whatever help (if any) that you received and from whom,
 *  including help from staff members or lab TAs.
 **********************************************************************/
The Fisher–Yates shuffle algorithm from the wiki page:
https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
 During the debugging process, I encounter the "double free or corruption" error because I attempt to free a pointer that has not been allocated to dynamic memory.


/**********************************************************************
 *  List any other comments here. Feel free to provide any feedback   
 *  on how much you learned from doing the assignment, and whether    
 *  you enjoyed doing it.                                             
 **********************************************************************/
 The idea of this assignment is great. However, I myself want to study more about the implementation of STL containers systematically
```
