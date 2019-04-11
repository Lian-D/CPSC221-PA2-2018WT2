## CPSC221-PA2-2018WT2
C++ Programming Assignment Authorized Release

# The Deque Class
You will write a class named Deque which is a modification of a doubly ended queue structure. While the standard deque allows for insertion and removal at both ends of a contiguous arrangement of data, our deque will allow insertion and removal at one end, but only removal at the other. For convenience, we will refer to the removal-only end as the left end, and the other as the right.
Your deque should be implemented as follows: The underlying data structure will be a C++ standard vector. Following the convention of the queue we discussed in class, you will allow the data to “float” in the vector, with the following difference: If, upon a removal, you discover that the contiguous block of data (whose size is, say, k) will “fit” in the first k positions of the vector, then you should resize down by making a new vector and copying the k pieces of data into that new vector using the push_back function. Additions to the structure can use the standard vector functions, and can only occur at the “right” side of the contiguous data (i.e. the position of largest index). (Note that in this implementation the structure is not “circular”– we do not wrap the data using the modulo of the array size.)

# The Stack Class
You will write a class named Stack that works just like the stack you heard about in lecture, with the addition of the peek() function. It is declared in the given file stack.h. You will implement it in stack.cpp.
Your Stack class must implement all of the methods mentioned in the given code. Please read the documentation in the header file to see what limitations we have placed on your Stack class and what the running times of each function should be.

# The Queue Class
You will write a class named Queue that works just like the queue you heard about in lecture, with the addition of the peek() function. It is declared in the given file queue.h. You will implement it in queue.cpp.
Your Queue class must implement all of the methods mentioned in the given code. Please read the documentation in the header file to see what limitations we have placed on your Queue class and what the running times of each function should be.

For this part of the assignment, you will be writing a number of functions that execute a “flood fill” on a PNG image. To flood fill a region of an image, you specify a point on the image and a fill color (or pattern) and all points similar in color and adjacent to the chosen point are changed to the fill color (or pattern). We will implement two different fill algorithms and three different fill patterns. The two fill algorithms are animated in the pictures above with a rainbow color fill pattern that we implemented.

![Alt Text](https://www.ugrad.cs.ubc.ca/~cs221/2018W2/mps/p2/bfsraingirl.gif)
![Alt Text](https://www.ugrad.cs.ubc.ca/~cs221/2018W2/mps/p2/dfsraingirl.gif)
