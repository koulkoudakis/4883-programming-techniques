from sys import stdin, stdout

# # Open a file for reading
file = open('in3', 'r')

# # Read the first line of the file
case = int(file.readline())
# print(case)

# case = 1
# case = int(stdin.readline())

# n = int(input())
# n = stdin.readline().strip()
# n = file.readline().strip()
# print(n)
# print(n.split())

for i in range(case):
  # a = list(map(int, input().split()))

  # n = stdin.readline().strip()
  n = file.readline().strip()

  if n == "":
    stdout.write("")

  # print(n)
  # print(n[i].strip())

  a = list(map(int, n.split()))

  print("Case {}: {}\n".format(i + 1, a[a[0] // 2 + 1]))
  # stdout.write("Case {}: {}\n".format(i + 1, a[a[0] // 2 + 1]))
  case += 1
