# 673 - Parentheses Balance

from sys import stdin, stdout


def main():

  stack = []

  # # Open a file for reading
  # file = open('in', 'r')

  # # Read the first line of the file
  # n = int(file.readline())
  # print(n)

  n = int(stdin.readline().strip())

  # Loop through the rest of the file and print each line
  for _ in range(n):
    err = False

    # line = file.readline()
    # print(line)
    line = stdin.readline().strip().strip()

    for char in line:
      if char == '\n':
        break
        # print('end line')
      if char in '([':
        stack.append(char)

      elif char == ')':
        if len(stack):
          if stack[-1] == '(':
            stack.pop()
          else:
            # print('No )')
            stdout.write("{}\n".format("No"))
            break
        else:
          # print('No ) (empty stack)')
          err = True
          break

      elif char == ']':
        if len(stack):
          if stack[-1] == '[':
            stack.pop()
          else:
            # print('No ]')
            stdout.write("{}\n".format("No"))
            break
        else:
          # print('No ] (empty stack)')
          err = True
          break

      # elif not len(stack):
      #   print(char)
      #   print('No (')
      #   break

      # print(stack)

    if not len(stack) and not err:
      # print('Yes')
      stdout.write("{}\n".format("Yes"))

    else:
      # print('No')
      stdout.write("{}\n".format("No"))

  # # Close the file when you're done
  # file.close()


if __name__ == '__main__':
  main()
