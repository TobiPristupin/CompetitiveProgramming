import math
from collections import deque

find_diagonal = lambda side: math.sqrt((side ** 2) * 2)
_, plots = input(), deque(sorted([int(x) * 2 for x in input().split()], reverse=True))
circular, square = [int(x) * 2 for x in input().split()], [find_diagonal(int(x)) for x in input().split()]  
houses = sorted(circular + square, reverse=True, key= lambda x: x)
placed = 0

for house in houses:
    if len(plots) == 0:
        break
    if house < plots[0]:
        plots.popleft()
        placed += 1

print(placed)
