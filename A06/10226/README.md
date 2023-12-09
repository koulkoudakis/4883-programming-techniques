## 10226 - Hardwood Species
### Sharome Burton
### Description:

Hardwoods are the botanical group of trees that have broad leaves,
produce a fruit or nut, and generally go dormant in the winter.
America's temperate climates produce forests with hundreds of
hardwood species |trees that share certain biological characteris-
tics. Although oak, maple and cherry all are types of hardwood
trees, for example, they are different species. Together, all the hard-
wood species represent 40 percent of the trees in the United States.
On the other hand, softwoods, or conifers, from the Latin word
meaning “cone-bearing”, have needles. Widely available US soft-
woods include cedar, r, hemlock, pine, redwood, spruce and cy-
press. In a home, the softwoods are used primarily as structural
lumber such as 2×4s and 2×6s, with some limited decorative appli-
cations.
Using satellite imaging technology, the Department of Natural Resources has compiled an inventory
of every tree standing on a particular day. You are to compute the total fraction of the tree population
represented by each species.

**Input**

The rst line is the number of test cases, followed by a blank line.
Each test case of your program consists of a list of the species of every tree observed by the satellite;
one tree per line. No species name exceeds 30 characters. There are no more than 10,000 species and
no more than 1,000,000 trees.
There is a blank line between each consecutive test cases.

**Output**

For each test case print the name of each species represented in the population, in alphabetical order,
followed by the percentage of the population it represents, to 4 decimal places.
Print a blank line between 2 consecutive test cases.

**Sample Input**

1

Red Alder

Ash

Aspen

Basswood

Ash

Beech

Yellow Birch

Ash

Cherry

Cottonwood

Ash

Cypress

Red Elm

Gum

Hackberry

White Oak

Hickory

Pecan

Hard Maple

White Oak

Soft Maple

Red Oak

Red Oak

White Oak

Poplan

Sassafras

Sycamore

Black Walnut

Willow


**Sample Output**

Ash 13.7931

Aspen 3.4483

Basswood 3.4483

Beech 3.4483

Black Walnut 3.4483

Cherry 3.4483

Cottonwood 3.4483

Cypress 3.4483

Gum 3.4483

Hackberry 3.4483

Hard Maple 3.4483

Hickory 3.4483

Pecan 3.4483

Poplan 3.4483

Red Alder 3.4483

Red Elm 3.4483

Red Oak 6.8966

Sassafras 3.4483

Soft Maple 3.4483

Sycamore 3.4483

White Oak 10.3448

Willow 3.4483

Yellow Birch 3.4483


### Files

|   #   | File                       | Description                                                |
| :---: | -------------------------- | ---------------------------------------------------------- |
|   1   | [main.py](./main.py)     | solution file.                                             |
|   2   | [in](./in)           | Test input file from problem statement                     |
|   3   | [in2](./in2)           | Test input file from udebug                    |
|   4   | [10226.pdf](./10226.pdf)         | Problem document                            |


### Instructions

- This project was run using Python 3.5.1

### Solution Description

My approach uses a defaultdict to keep track of the frequency of each species and calculates the total number
of trees. By iterating through the data, the script sums the occurence of each tree species, and then after calculates and prints the percentage of each tree species in alphabetical order for each test case. The defaultdict is useful for handling the first occurrence of a tree species when looping through the data and adding new keys.

The script repeats this process for all test cases, ensuring to print a blank line between
consecutive cases as specified in the problem statement. 


 
