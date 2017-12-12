# C Programs

This repository is a collection of C programs written by me. I decided to rewrite and/or update all codes that I found important and I will update this repository with time. That's organized by these categories:

- Data Structure
- Sort Algorithms
- Misc

## Data Structure

This directory has some data structure algorithms:

- Linked-List
- Doubly Linked-List
- Circular Linked-List
- Doubly Circular Linked-List `[WIP]`
- Stack
- Queue
- AVL Tree `[Not Implemented]`
- Binary Search Tree `[Not Implemented]`


>The most .c files cannot be used simultaneosly because some structures are the same, e.g. `node_t` and `data_t`, used in _linked-lists_, _stack_ and _queue_ files. One way to make everything work is rename the structures in each file.

>Only on ciruclar linked-list and circular doubly-linked-list has the implementations is the descriptive data type used and, **in the case of the lists, there is no insertion order**.

>All data structures work from a pointer and must be initialized with the **NULL** value. e.g. `list_t *list = NULL` because I have opted to not use a global variable for them. That's possibilite the use of _n_ structures at the same time.

## Sort Algorithms

For while, nothing.

## Misc

- Monte Carlo `[WIP]`: Algorithms to calculate Pi value with Monte Carlo Technique with multi threads and mutual exclusion semaphore. **Work only on unix systems and, for while, this codes are written in pt-br.**

## Task list

- [x] Finish the Queue and Stack Data Structure
- [x] Finish the Simple Linked List and Simple Circular Linked List
- [ ] Finish the Doubly Linked List and Doubly Circular Linked List `[WIP]`
- [ ] Finish the Binary Search Tree and AVL Tree
- [ ] Optimize and make some updates in the Monte Carlo Algorithm, merging the implementation of _threads_ and _mutex_ into a single file. `[WIP]`
- [ ] Start developing of Sort Algorithms

## License
This library is under GNU General Public License (GPL) 3.

**Knowledge is power and the power is for everyone.**
