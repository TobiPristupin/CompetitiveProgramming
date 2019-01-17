from collections import deque

def pop_until(queue, stopleft, stopright):
    while queue and s[0] != stopleft:
        s.popleft()
    while queue and s[-1] != stopright:
        s.pop()

s = deque(input())

pop_until(s, "[", "]")
if not(s and s[0] == "[" and s[-1] == "]"):
    print(-1)
    exit(0)

# Remove brackets for convenience
s.popleft()
s.pop()

pop_until(s, ":", ":")
if not len(s) >= 2:
    print(-1)
    exit(0)

# Remove colons for convenience
s.popleft()
s.pop()

vertical_lines = s.count("|")
print(vertical_lines + 4)

