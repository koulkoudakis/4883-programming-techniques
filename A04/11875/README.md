## 11875 - Brick Game
### Sharome Burton
### Description:

There is a village in Bangladesh, where brick game is very popular. Brick game is a team game. Each
team consists of odd number of players. Number of players must be greater than 1 but cannot be
greater than 10. Age of each player must be within 11 and 20. No two players can have the same age.
There is a captain for each team. The communication gap between two players depends on their age
difference, i.e. the communication gap is larger if the age difference is larger. Hence they select the
captain of a team in such a way so that the number of players in the team who are younger than that
captain is equal to the number of players who are older than that captain.
Ages of all members of the team are provided. You have to determine the age of the captain.

**Input**

Input starts with an integer T (T ≤ 100), the number of test cases.
Each of the next T lines will start with an integer N (1 < N < 11), number of team members
followed by N space separated integers representing ages of all of the members of a team. Each of these
N integers will be between 11 and 20 (inclusive). Note that, ages will be given in strictly increasing order
or strictly decreasing order. We will not mention which one is increasing and which one is decreasing,
you have to be careful enough to handle both situations.

**Output**

For each test case, output one line in the format ‘Case x: a’ (quotes for clarity), where x is the case
number and a is the age of the captain.

**Sample Input**

2

5 19 17 16 14 12

5 12 14 16 17 18

**Sample Output**

Case 1: 16

Case 2: 16


### Files

|   #   | File                       | Description                                                |
| :---: | -------------------------- | ---------------------------------------------------------- |
|   1   | [main.py](./main.py)     | solution file.                                             |
|   2   | [in](./in)           | Test input file from problem statement                     |
|   3   | [in2](./in2)           | Test input file from udebug                    |
|   3   | [in3](./in3)           | Test input file from udebug                   |
|   4   | [11875.pdf](./11875.pdf)         | Problem document                            |


### Instructions

- This project was run using Python 3.5.1

### Solution Description

My approach involves using a loop to
iterate through each test case and extract the age information. Since the ages are in increasing or decreasing order,
I create a list of integers from the input and find the captain's age by accessing the middle element
(the number of players is always odd so it is the n//2 + 1th player). This is simple enough arithmetic.
I then print the result in the required
format for each test case. 


 
