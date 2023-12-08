# 572 - Oil Deposits

def dfs(r, c):
  # Base case: Check if the current position is out of bounds or already visited
  if r < 0 or r >= m or c < 0 or c >= n or grid[r][c] == '*':
      return

  # Mark the current position as visited
  grid[r][c] = '*'

  # Explore neighbors in eight directions using DFS
  dfs(r - 1, c)       # up
  dfs(r - 1, c + 1)   # top-right
  dfs(r, c + 1)       # right
  dfs(r + 1, c + 1)   # bottom-right
  dfs(r + 1, c)       # bottom
  dfs(r + 1, c - 1)   # bottom-left
  dfs(r, c - 1)       # left
  dfs(r - 1, c - 1)   # top-left


while True:
  # Input grid dimensions
  m, n = map(int, input().split())

  # Check for the end of input
  if m == 0 and n == 0:
      break

  # Initialize the counter for oil deposits
  cnt = 0

  # Input the grid as a list of lists
  grid = [list(input()) for _ in range(m)]

  # Traverse the grid to find oil deposits
  for i in range(m):
      for j in range(n):
          if grid[i][j] == '@':
              # Found a new oil deposit, increment the counter and explore it
              cnt += 1
              dfs(i, j)

  # Output the count of oil deposits for the current test case
  print(cnt)