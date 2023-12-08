# 11463 - Commandos

INF = 9999

def main():
  Case = 1

  # # Open a file for reading
  # file = open('in2', 'r')

  T = int(input())  # Number of test cases
  # T = int(file.readline())
  while T > 0:
    # N, R = map(int, input().split())  # Number of buildings and roads
    # print(file.readline().split())
    # N = int(file.readline())
    N = int(input())

    # R = int(file.readline())  # Number of buildings and roads
    R = int(input())
    # Initialize adjacency matrix with INF distances
    buildings = [[INF for _ in range(N)] for _ in range(N)]

    # Set diagonal elements to 0
    for i in range(N):
      buildings[i][i] = 0

    # Read input edges and update the adjacency matrix
    for _ in range(R):
      u, v = map(int, input().split())
      # u, v = map(int, file.readline().split())

      buildings[u][v] = 1
      buildings[v][u] = 1

    # Floyd-Warshall algorithm to find shortest paths
    for k in range(N):
      for i in range(N):
        for j in range(N):
          buildings[i][j] = min(buildings[i][j],
                                buildings[i][k] + buildings[k][j])

    s, d = map(int, input().split())  # Source and destination buildings
    # s, d = map(int, file.readline().split())

    min_time = 0
    # Find the minimum time considering all possible intermediate buildings
    for i in range(N):
      if buildings[s][i] != INF and buildings[i][d] != INF:
        min_time = max(min_time, buildings[s][i] + buildings[i][d])

    # Print the result for the current test case
    print(f"Case {Case}: {min_time}")

    Case += 1
    T -= 1


# Run the solver
if __name__ == "__main__":
  main()

# https://github.com/ajahuang/UVa/blob/master/UVa%2011463%20-%20Commandos.cpp
