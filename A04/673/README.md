## 673 - Balancing Parentheses
### Sharome Burton
### Description:

You are given a string consisting of parentheses () and []. A string of this type is said to be correct:
(a) if it is the empty string
(b) if A and B are correct, AB is correct,
(c) if A is correct, (A) and [A] is correct.
Write a program that takes a sequence of strings of this type and check their correctness. Your
program can assume that the maximum string length is 128.

**Input**
The file contains a positive integer n and a sequence of n strings of parentheses ‘()’ and ‘[]’, one string
a line.

**Output**
A sequence of ‘Yes’ or ‘No’ on the output file.

**Sample Input**
3

([])

(([()])))

([()[]()])()

**Sample Output**

Yes

No

Yes

### Files

|   #   | File                       | Description                                                |
| :---: | -------------------------- | ---------------------------------------------------------- |
|   1   | [main.py](./main.py)     | solution file.                                             |
|   2   | [in](./in)           | Test input file from problem statement                     |
|   3   | [673.pdf](./673.pdf)         | Problem document                            |


### Instructions

- This project was run using Python 3.5.1

### Solution Description

My approach to solving this problem involves using a stack data structure to keep track of the open parentheses
and square brackets as I traverse the input string. I iterate through each character in the string, and for
each opening parenthesis or bracket, I push it onto the stack. 

If I encounter a closing parenthesis or bracket,
I check if the stack is not empty and if the top of the stack matches the right opening character.
If it does, I pop the opening character from the stack. 

If not, I output "No" and exit the loop.
If the stack is empty at the end of the iteration and there were no errors, I output "Yes" to indicate
that the input string is correctly balanced. Otherwise, I output "No."
 
