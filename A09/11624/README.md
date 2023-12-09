## 11624- Fire!
### Sharome Burton
### Description:

Joe works in a maze. Unfortunately, portions of the maze have
caught on fire, and the owner of the maze neglected to create a fire
escape plan. Help Joe escape the maze.
Given Joe’s location in the maze and which squares of the maze
are on fire, you must determine whether Joe can exit the maze before
the fire reaches him, and how fast he can do it.
Joe and the fire each move one square per minute, vertically or
horizontally (not diagonally). The fire spreads all four directions
from each square that is on fire. Joe may exit the maze from any
square that borders the edge of the maze. Neither Joe nor the fire
may enter a square that is occupied by a wall.

**Input**

The first line of input contains a single integer, the number of test
cases to follow. The first line of each test case contains the two
integers R and C, separated by spaces, with 1 ≤ R, C ≤ 1000. The
following R lines of the test case each contain one row of the maze. Each of these lines contains exactly
C characters, and each of these characters is one of:

• #, a wall

• ., a passable square

• J, Joe’s initial position in the maze, which is a passable square

• F, a square that is on fire

There will be exactly one J in each test case.

**Output**

For each test case, output a single line containing ‘IMPOSSIBLE’ if Joe cannot exit the maze before the
fire reaches him, or an integer giving the earliest time Joe can safely exit the maze, in minutes.
**
Sample Input**

2

4 4

####

#JF#

#..#

#..#

3 3

###

#J.

#.F

**Sample Output**

3

IMPOSSIBLE


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
  
