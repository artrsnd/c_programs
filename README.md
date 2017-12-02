# C Programs

This repository is a collection of C programs written by me. It is organized by these categories:

- Data Structure
- Sort Algorithms
- Misc

## Data Structure

This directory has some data structure algorithms:

- Linked-List
- Doubly Linked-List
- Circular Linked-List `[WIP]`
- Doubly Circular Linked-List `[WIP]`
- Stack
- Queue
- AVL Tree `[WIP]`
- Binary Search Tree `[WIP]`

### Notes:
- The most .c files cannot be used simultaneosly because some structures are the same, e.g. ```node_t``` and ```data_t```, used in _linked-lists_, _stack_ and _queue_ files. One way to make everything work is rename the structures in each file.

- In none of the implementations is the descriptive data type used and, **in the case of the lists, there is no insertion order**. This is made only in the tail of the list. This easly can be modified.

- All data structures work from a pointer and must be initialized with the **NULL** value. e.g. ```list_t *list = NULL```.

## Sort Algorithms

For while, nothing.

## Misc

- Monte Carlo `[WIP]`: Algorithms to calculate Pi value with Monte Carlo Technique with multi threads and mutual exclusion semaphore. **Work only on unix systems and this codes are written in pt-br.**

## License
This library is under GNU General Public License (GPL) 3.

**Knowledge is power and the power is for everyone.**
