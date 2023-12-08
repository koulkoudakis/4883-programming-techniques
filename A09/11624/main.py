# 11624 - Fire!

from queue import Queue

# Define the possible movements in the grid
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

def solve(r, c, building):
    # Initialize two queues for fire spreading and person's movements
    Q1 = Queue()
    Q2 = Queue()

    # Initialize 2D arrays for fire spread, visited cells, and set default values
    f = [[-1 for _ in range(c)] for _ in range(r)]
    v = [[0 for _ in range(c)] for _ in range(r)]

    # Process the initial state of the building
    for i in range(r):
        for j in range(c):
            f[i][j] = -1
            v[i][j] = 0

            # If it's a fire, add it to the fire queue and set its time to 0
            if building[i][j] == 'F':
                Q1.put((i, j))
                f[i][j] = 0
            # If it's the person, add it to the person's queue with time 0 and mark it as visited
            elif building[i][j] == 'J':
                Q2.put((i, j, 0))
                v[i][j] = 1

    # Perform BFS for fire spreading
    while not Q1.empty():
        i, j = Q1.get()
        for d in range(4):
            a, b = i + dx[d], j + dy[d]
            # Check if the neighboring cell is within bounds, not a wall, and hasn't been visited
            if 0 <= a < r and 0 <= b < c and building[a][b] != '#' and f[a][b] == -1:
                f[a][b] = f[i][j] + 1
                Q1.put((a, b))

    # Perform BFS for the person's movements
    while not Q2.empty():
        i, j, t = Q2.get()
        # Check if the person has reached the boundary of the building
        if i == 0 or j == 0 or i == r - 1 or j == c - 1:
            return t + 1
        else:
            # Check the neighboring cells for possible movements
            for d in range(4):
                a, b = i + dx[d], j + dy[d]
                # Check if the neighboring cell is within bounds, not on fire, and hasn't been visited
                if 0 <= a < r and 0 <= b < c and (f[a][b] == -1 or f[a][b] > t + 1) and building[a][b] != '#' and not v[a][b]:
                    v[a][b] = 1
                    Q2.put((a, b, t + 1))

    # If the person cannot escape, return -1
    return -1

def main():
    # Read the number of test cases
    runs = int(input())
    for _ in range(runs):
        # Read the dimensions of the building
        r, c = map(int, input().split())
        # Read the building layout
        building = [input().rstrip() for _ in range(r)]
        # Call the solve function and print the result
        res = solve(r, c, building)
        if res == -1:
            print("IMPOSSIBLE")
        else:
            print(res)

if __name__ == "__main__":
    main()
