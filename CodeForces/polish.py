from sys import stdin
from collections import deque

def is_int(string):
    try:
        int(string)
        return True
    except ValueError:
        return False

for number, line in enumerate(stdin):
    line = line[:-1]
    stack = deque()
    for c in reversed(line.split()):
        if c in "+-*":
            a = stack.pop()
            b = stack.pop()
            if is_int(a) and is_int(b):
                stack.append(eval(str(a) + str(c) + str(b)))
            else:
                stack.append(b)
                stack.append(a)
                stack.append(c)
        else:
            stack.append(c)
    print("Case " + str(number + 1) + ": " + " ".join(map(str, reversed(stack))))




    
