# C Programs

This repository is a collection of C programs written by me. I decided to rewrite and/or update all codes that I found important and I will update this repository with time.

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

### Monte Carlo Tecnique

#### Description
This is a simple implementation of the Monte Carlo Algorithm to estimate the Pi value, using multi-thread processing and mutual exclusion semaphore to avoid the _Race Condition_.

>Originally this was a work for the discipline of Operational Systems in 2/2017, but I have decided to update this code and share this here.

#### How it works
The Monte Carlo technique defines a circle of radius 1 in the cartesian plane starting from the origin.
Then have the need to generate N random points with x,y belonging to the interval [-1, 1] and calculates pi by multiplying 4 to the total points that are part of the area of the circle and dividing the result by the total of points generated.

**[WARNING] This code only work on linux systems.**

#### Compiling and running
To compile the code, pass the arguments of `lpthread` and `lm` to GCC.

>`gcc mc_pi.c -o out -lpthread -lm`

To run, just pass two arguments to the program: first, the quantity of threads you want use. second, the quantity of points each thread needs generate and count, e.g. `./out 10 100000`.

## Task list

- [x] Finish the Queue and Stack Data Structure
- [x] Finish the Simple Linked List and Simple Circular Linked List
- [ ] Finish the Doubly Linked List and Doubly Circular Linked List `[WIP]`
- [ ] Finish the Binary Search Tree and AVL Tree
- [x] Optimize and make some updates in the Monte Carlo Algorithm, merging the implementation of _threads_ and _mutex_ into a single file.
- [ ] Start developing of Sort Algorithms

## License
This library is under GNU General Public License (GPL) 3.

**Knowledge is power.**
