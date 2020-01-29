from collections import Counter, deque

n = int(input())
input()
for tcase in range(n):
    lines = []
    line = input()
    while line.replace(" ", "") != "":
        lines.append(line)
        try:
            line = input()
        except:
            break
   
    
    counters = [Counter(l.replace(" ", "")) for l in lines]
    pairs = set()
    for i, x in enumerate(counters):
        for j, y in enumerate(counters):
            if i != j and x == y:
                pair = min(lines[i], lines[j]) + " = " + max(lines[i], lines[j])
                pairs.add(pair)

    for pair in sorted(pairs):
        print(pair)
    
    if tcase != n-1: print()

    