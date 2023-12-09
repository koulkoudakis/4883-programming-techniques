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

Input

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
Output
For each case of input, there will be one line of output. It will contain the case number followed by the
minimum time required to complete the mission. Look at the sample output for exact formatting.
Sample Input
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
Universidad de Valladolid OJ: 11463 – Commandos 2/2
Sample Output
Case 1: 4
Case 2: 1


### Files

|   #   | File                       | Description                                                |
| :---: | -------------------------- | ---------------------------------------------------------- |
|   1   | [main.py](./main.py)     | solution file.                                             |
|   2   | [in](./in)           | Test input file from problem statement                     |
|   3   | [in2](./in2)           | Test input file from udebug                    |
|   4   | [11624.pdf](./11624.pdf)         | Problem document                            |


### Instructions

- This project was run using Python 3.5.1

### Solution Description

My approach to solving this problem involves simulating the movement of both Joe and the fire in the maze using a BFS approach. I initialize two queues to represent the spreading of fire and Joe's movements. 

The algorithm processes the starting state of the maze, marking the positions of fire and Joe, and then explores the neighboring cells by iteration to spread the fire and find the shortest path for Joe to escape. 

The BFS for fire spreads the fire in all directions from each burning cell, calculating the time it takes to reach each cell. The BFS for Joe explores the passable cells, ensuring Joe doesn't step on a burning cell and updating the time it takes to reach each cell. 

The algorithm terminates when Joe reaches an edge of the maze (a successful escape), or when it shows that Joe cannot escape before the fire catches him.


**Sources**
- https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
  
