from collections import deque

_, tasks, spaces = input(), list(sorted(map(int, input().split()))), deque(sorted(map(int, input().split())))

count = 0

for task in tasks:
    while spaces:
        if task <= spaces[0]:
            spaces[0] -= task
            count += 1
            break
        else:
            spaces.popleft()

print(count)


