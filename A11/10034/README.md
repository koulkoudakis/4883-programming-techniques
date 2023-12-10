## 10034 - Freckles
### Sharome Burton
### Description:

In an episode of the Dick Van Dyke show, little Richie connects the freckles on his Dad’s back to form a
picture of the Liberty Bell. Alas, one of the freckles turns out to be a scar, so his Ripley’s engagement
falls through.

Consider Dick’s back to be a plane with freckles at various (x, y) locations. Your job is to tell Richie
how to connect the dots so as to minimize the amount of ink used. Richie connects the dots by drawing
straight lines between pairs, possibly lifting the pen between lines. When Richie is done there must be
a sequence of connected lines from any freckle to any other freckle.

**Input**

The input begins with a single positive integer on a line by itself indicating the number of the cases
following, each of them as described below. This line is followed by a blank line, and there is also a
blank line between two consecutive inputs.
The first line contains 0 < n ≤ 100, the number of freckles on Dick’s back. For each freckle, a line
follows; each following line contains two real numbers indicating the (x, y) coordinates of the freckle.

**Output**

For each test case, the output must follow the description below. The outputs of two consecutive cases
will be separated by a blank line.
Your program prints a single real number to two decimal places: the minimum total length of ink
lines that can connect all the freckles.

**Sample Input**

1

3

1.0 1.0

2.0 2.0

2.0 4.0

**Sample Output**

3.41


### Files

|   #   | File                       | Description                                                |
| :---: | -------------------------- | ---------------------------------------------------------- |
|   1   | [main.py](./main.py)     | solution file.                                             |
|   2   | [in](./in)           | Test input file from problem statement                     |
|   3   | [in2](./in2)           | Test input file from udebug                    |
|   4   | [10034.pdf](./10034.pdf)         | Problem document                            |


### Instructions

- This project was run using Python 3.5.1

### Solution Description

My approach to solving this problem involves implementing the Prim's algorithm to find the minimum spanning tree 
of the freckles on Dick's back. The goal is to minimize the total length of ink lines needed to connect all the freckles.
The algorithm begins by calculating the Euclidean distances between all pairs of freckles and storing them in a list.
This list is then sorted in ascending order based on the distances. 

The algorithm maintains a boolean array to keep
track of connected freckles and connects the freckles at each iteration with the smallest distances to make sure that the
resulting graph remains connected. The total cost of ink lines is updated with each iteration. The process continues
until all freckles are connected in the MST. Prims algorithm gets the solution in our case by greedily
selecting the shortest edges while avoiding the formation of cycles.

**Sources**

- https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/
- https://www.simplilearn.com/tutorials/data-structure-tutorial/minimum-spanning-tree-algorithm-in-data-structure
