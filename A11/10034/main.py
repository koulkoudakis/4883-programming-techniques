# 10034 - Freckles

import math


# Function to calculate Euclidean distance between two freckles
def get_distance(freckle1, freckle2):
  x_diff = freckles_x[freckle1] - freckles_x[freckle2]
  y_diff = freckles_y[freckle1] - freckles_y[freckle2]
  return math.sqrt(x_diff * x_diff + y_diff * y_diff)


# Struct-like class to represent distances between freckles
class Distance:

  def __init__(self, distance, freckle1, freckle2):
    self.distance = distance
    self.freckle1 = freckle1
    self.freckle2 = freckle2


# Function to connect two freckles and update total cost
def connect(dist):
  connected[dist.freckle1] = connected[dist.freckle2] = True
  global total_cost
  total_cost += dist.distance


# Main function
def main():
  # # Open a file for reading
  # file = open('in2', 'r')

  T = int(input().strip())  # Number of test cases
  # T = int(file.readline().strip())  # Number of test cases

  # file.readline().strip()  # Ignore the 2nd line
  blank = input().strip()  # Ignore the 2nd line

  for _ in range(T):
    if _ > 0:
      print()  # Separate output for different test cases

    N = int(input().strip())  # Number of freckles
    # N = int(file.readline().strip())  # Number of freckles
    global freckles_x, freckles_y, connected, total_cost

    freckles_x = [0.0] * N
    freckles_y = [0.0] * N
    connected = [False] * N

    # Read freckle coordinates
    for i in range(N):
      freckles_x[i], freckles_y[i] = map(float, input().strip().split())
      # freckles_x[i], freckles_y[i] = map(float, file.readline().strip().split())

    num_distances = 0
    all_distances = []

    # Calculate all pairwise distances
    for i in range(N):
      for j in range(i):
        distance = get_distance(i, j)
        all_distances.append(Distance(distance, i, j))
        num_distances += 1

    # Sort distances in ascending order
    all_distances.sort(key=lambda d: d.distance)

    total_cost = 0
    num_connected = 2
    if len(all_distances) != 0:
      connect(all_distances[0])

    # Connect freckles to form the minimum spanning tree
    while num_connected < N:
      for i in range(1, len(all_distances)):
        if connected[all_distances[i].freckle1] ^ connected[
            all_distances[i].freckle2]:
          connect(all_distances[i])
          break

      num_connected += 1

    # Print total cost with two decimal places
    print("{:.2f}".format(total_cost))

    # file.readline().strip()  # Ignore the line after processing test case
    blank = input().strip()  # Ignore the line after processing test case


if __name__ == "__main__":
  main()
