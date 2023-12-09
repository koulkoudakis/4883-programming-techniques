# 161 - Traffic Lights

file = open('in', 'r')

INF = 99999999

for i in range(3):
  # Input the durations of the traffic lights
  A = []
  intdelay = -1
  line = ['start']
  while intdelay != 0:
    line = file.readline().split()
    print(line)
    for delay in line:
      print(int(delay))
      intdelay = delay
      A.append(int(delay))
      if int(delay) == 0:
        A.pop()
        break

    # print('iteration')
    break
    
  # A = list(map(int, file.readline().split()))
  print(A)
  # A = list(map(int, input().split()))

  # Check for the end of input
  # if A[0] == 0:
  #   break
    
  n = len(A)
  time = [0] * n
  
  s = INF

  for i in range(n):
    if A[i] < s:
      s = A[i]

  # if (s % 10 == 0):
  #   print(s)

  # Iterate over the time until the lights synchronize
  while s <= 18000:
    sync = True

    # Check if all lights are synchronized at time 's'
    for i in range(n):
      while time[i] + A[i] - 5 <= s:
        time[i] += 2 * A[i]
        
      if not (time[i] <= s < time[i] + A[i] - 5):
        s = time[i] - 1
        yes = False
        break

    # If all lights are synchronized, break out of the loop
    if sync:
      break

    s += 1

  if s > 18000:
    print("Signals fail to synchronise in 5 hours")
  else:
    # Print the synchronized time in HH:MM:SS format
    print(f"{s // 3600:02d}:{(s % 3600) // 60:02d}:{s % 60:02d}")
