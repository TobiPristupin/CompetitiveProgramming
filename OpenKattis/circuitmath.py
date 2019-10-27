from collections import deque

n = int(input())
values = [True if x == "T" else False for x in input().split()]
circuit = list(input().split())
stack = deque()

for c in circuit:
    if c in ["*", "+"]:
        a, b = stack.pop(), stack.pop()
        if c == "*":
            stack.append(a and b)
        elif c == "+":
            stack.append(a or b)
    elif c == "-":
        stack.append(not stack.pop())
    else:
        stack.append(values[ord(c) - 65])

print("T" if stack.pop() else "F")
