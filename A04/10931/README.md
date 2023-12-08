## 10931 - Parity
### Sharome Burton
### Description:

We define the parity of an integer n as the sum of the bits in binary representation computed modulo
two. As an example, the number 21 = 101012 has three 1s in its binary representation so it has parity
3(mod2), or 1.

In this problem you have to calculate the parity of an integer 1 ≤ I ≤ 2147483647.

**Input**

Each line of the input has an integer I and the end of the input is indicated by a line where I = 0 that
should not be processed.

**Output**

For each integer I in the inputt you should print a line ‘The parity of B is P (mod 2).’, where B
is the binary representation of I.

**Sample Input**

1

2

10

21

0

**Sample Output**

The parity of 1 is 1 (mod 2).

The parity of 10 is 1 (mod 2).

The parity of 1010 is 2 (mod 2).

The parity of 10101 is 3 (mod 2).


### Files

|   #   | File                       | Description                                                |
| :---: | -------------------------- | ---------------------------------------------------------- |
|   1   | [main.cpp](./main.cpp)     | solution file.                                             |
|   2   | [in](./in)           | Test input file from problem statement                     |
|   2   | [in2](./in2)           | Test input file from problem statement                     |
|   3   | [10931.pdf](./10931.pdf)         | Problem document                            |
|   4   |    |  |
|   5   |  |                |

### Instructions

- This project was run using Python 3.5.1

### Solution Description

My approach to solving this problem involves repeatedly taking integers as input until encountering a 0.
For each input integer, I convert it to its binary representation using the 'bitset' class.
I then remove leading zeros from the binary string, since they don't affect the parity. Using this 
binary representation, I count the number of '1's in the string to calculate the parity.

The final output original binary representation, the count of '1's, and the
result of the parity modulo 2. The program displays the parity
for each input integer, iterating through the process until encountering a terminating 0.
 
