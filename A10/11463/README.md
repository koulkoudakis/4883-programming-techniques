## 11463 - Commandos
### Sharome Burton
### Description:

A group of commandos were assigned a critical task. They are to destroy an enemy head quarter.
The enemy head quarter consists of several buildings and the buildings are connected by roads. The
commandos must visit each building and place a bomb at the base of each building. They start their
mission at the base of a particular building and from there they disseminate to reach each building.
The commandos must use the available roads to travel between buildings. Any of them can visit one
building after another, but they must all gather at a common place when their task in done.
In this problem, you will be given the description of different enemy headquarters. Your job is to
determine the minimum time needed to complete the mission. Each commando takes exactly one unit
of time to move between buildings.
You may assume that the time required to place a bomb is negligible. Each commando can carry
unlimited number of bombs and there is an unlimited supply of commando troops for the mission.

**Input**

The rst line of input contains a number T < 50, where T denotes the number of test cases.
Each case describes one head quarter scenario. The rst line of each case starts with a positive
integer N ≤ 100, where N denotes the number of buildings in the head quarter. The next line contains
a positive integer R, where R is the number of roads connecting two buildings. Each of the next R
lines contain two distinct numbers, 0 ≤ u, v < N , this means there is a road connecting building u
to building v. The buildings are numbered from 0 to N − 1. The last line of each case contains two
integers 0 ≤ s, d < N . Where s denotes the building from where the mission starts and d denotes the
building where they must meet.
You may assume that two buildings will be directly connected by at most one road. The input will
be such that, it will be possible to go from any building to another by using one or more roads.

**Output**

For each case of input, there will be one line of output. It will contain the case number followed by the
minimum time required to complete the mission. Look at the sample output for exact formatting.

**Sample Input**

2

4

3

0 1

2 1

1 3

0 3

2

1

0 1

1 0

**Sample Output**

Case 1: 4

Case 2: 1


### Files

|   #   | File                       | Description                                                |
| :---: | -------------------------- | ---------------------------------------------------------- |
|   1   | [main.py](./main.py)     | solution file.                                             |
|   2   | [in](./in)           | Test input file from problem statement                     |
|   3   | [in2](./in2)           | Test input file from udebug                    |
|   4   | [11463.pdf](./11463.pdf)         | Problem document                            |


### Instructions

- This project was run using Python 3.5.1

### Solution Description

My approach to solving this problem involves using the Floyd-Warshall algorithm to find the shortest paths between all pairs of buildings in each enemy headquarters scenario. The input is processed for each test case, constructing an adjacency matrix to represent the connectivity between buildings through roads. The matrix is initialized with large values (INF) for unconnected buildings, and diagonal elements are set to 0. The Floyd-Warshall algorithm is then applied to iteratively update the matrix, considering all possible paths. Once the shortest paths are computed, the minimum time for the commandos to complete their mission is determined by finding the maximum time taken among all possible routes from the starting building to the meeting point. This maximum time reflects the bottleneck in the commandos' movements, ensuring that all commandos gather at the common meeting place. The result is printed in the specified output format for each test case.




**Sources**

- https://github.com/ajahuang/UVa/blob/master/UVa%2011463%20-%20Commandos.cpp
- https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/ 
