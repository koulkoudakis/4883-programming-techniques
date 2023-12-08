# 10226 - Hardwood Species

from collections import defaultdict
# The main difference between defaultdict and dict is that when you try to access or modify a key that's not present in the dictionary, a default value is automatically given to that key - helpful for adding the first occurence of a hardwood species to the dictionary.


def main():
  # file = open('in2', 'r')

  # Read the number of test cases
  num_test_cases = int(input())
  # num_test_cases = int(file.readline())

  # Read an empty line after the number of test cases
  input()
  # file.readline()

  while num_test_cases > 0:
    # Create a defaultdict to store the frequency of each tree species
    tree_frequency = defaultdict(int)
    total_trees = 0

    # Read tree species until an empty line is encountered
    while True:
      tree_name = input().strip()
      # tree_name = file.readline().strip()

      # Break if an empty line is encountered
      if not tree_name:
        break

      # Update the frequency of the tree species
      tree_frequency[tree_name] += 1
      total_trees += 1

    # Print the percentage of each tree species in alphabetical order
    for tree in sorted(tree_frequency.keys()):
        count = tree_frequency[tree]
        percentage = (count / total_trees) * 100
        print(f"{tree} {percentage:.4f}")


    # Print a blank line between test cases
    num_test_cases -= 1
    if num_test_cases > 0:
      print()


if __name__ == "__main__":
  main()
