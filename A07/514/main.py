# 514 - Rails

while True:
  file = open('in', 'r')

  # n = int(input())
  n = int(file.readline())
  if n == 0:
      break

  while True:
      # target = list(map(int, input().split()))
      target = list(map(int, file.readline().split()))
    
      if target[0] == 0:
          print()  # Output a newline for each test case
          break

      current_train, target_index = 1, 0
      station = []

      # Simulate the train station and check if the target permutation is possible
      while current_train <= n:
          station.append(current_train)

          while station and station[-1] == target[target_index]:
              station.pop()
              target_index += 1
              if target_index >= n:
                  break

          current_train += 1

      # Output the result for the current test case
      if not station:
          print("Yes")
      else:
          print("No")
        
