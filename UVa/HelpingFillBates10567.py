import bisect
from collections import defaultdict

s = input()
chars = defaultdict(list)
for i, c in enumerate(s):
    chars[c].append(i)


q = int(input())
for _ in range(q):
    query = input()
    start, end = 10000001, -1
    index = -1
    for c in query:
        k = bisect.bisect_right(chars[c], index)
        if k == len(chars[c]):
            print("Not matched")
            break
        
        j = chars[c][k]
        start = min(start, j)
        end = max(end, j)
        index = j
    
    else:
        print("Matched {} {}".format(start, end))

    