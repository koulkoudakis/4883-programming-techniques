## 572- Oil Deposits
### Sharome Burton
### Description:

The GeoSurvComp geologic survey company is responsible for detecting underground oil deposits.
GeoSurvComp works with one large rectangular region of land at a time, and creates a grid that divides
the land into numerous square plots. It then analyzes each plot separately, using sensing equipment to
determine whether or not the plot contains oil.
A plot containing oil is called a pocket. If two pockets are adjacent, then they are part of the
same oil deposit. Oil deposits can be quite large and may contain numerous pockets. Your job is to
determine how many different oil deposits are contained in a grid.

**Input**

The input file contains one or more grids. Each grid begins with a line containing m and n, the number
of rows and columns in the grid, separated by a single space. If m = 0 it signals the end of the input;
otherwise 1 ≤ m ≤ 100 and 1 ≤ n ≤ 100. Following this are m lines of n characters each (not counting
the end-of-line characters). Each character corresponds to one plot, and is either ‘*’, representing the
absence of oil, or ‘@’, representing an oil pocket.

**Output**

For each grid, output the number of distinct oil deposits. Two different pockets are part of the same
oil deposit if they are adjacent horizontally, vertically, or diagonally. An oil deposit will not contain
more than 100 pockets.

**Sample Input**

1 1

*

3 5

*@*@*

**@**

*@*@*

1 8

@@****@*

5 5

****@

*@@*@

*@**@

@@@*@

@@**@

0 0

**Sample Output**

0

1

2

2


### Files

|   #   | File                       | Description                                                |
| :---: | -------------------------- | ---------------------------------------------------------- |
|   1   | [main.py](./main.py)     | solution file.                                             |
|   2   | [in](./in)           | Test input file from problem statement                     |
|   3   | [in2](./in2)           | Test input file from udebug                    |
|   4   | [572.pdf](./572.pdf)         | Problem document                            |


### Instructions

- This project was run using Python 3.5.1

### Solution Description

My approach to solving this problem involves using depth-first search (DFS) to traverse the grid
and identify distinct oil deposits. The script starts by reading the dimensions of the grid and
initializing a counter for oil deposits. It then reads the grid as a list of lists, where each
character represents a plot either containing or lacking oil. For each plot containing oil ('@'),
the script increments the deposit counter and initiates a DFS from that position. 

The DFS function
explores adjacent plots in all eight directions, marking visited plots as it progresses.
The main loop iterates through each plot in the grid, and whenever it encounters an unexplored oil plot,
it increments the deposit counter and explores the entire connected oil deposit using DFS.
The final output consists of the count of distinct oil deposits for each grid.

**Sources**
- https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
