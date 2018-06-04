import sys
import math

bridges, knights, group_min = map(int, sys.stdin.read().split())
print(math.ceil((bridges - 1) / int(knights / group_min)))
