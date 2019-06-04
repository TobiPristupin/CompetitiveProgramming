n, m = map(int, input().split())
pairs = [tuple(map(int, input().split())) for i in range(m)]
first = pairs[0]
x, y = (), ()
all_differ = lambda x, y: x[0] != y[0] and x[1] != y[0] and x[0] != y[1] and x[1] != y[1]
for p in pairs:
    if all_differ(first, p):
        x, y = first, p
        break
else:
    print("YES")
    exit(0)

for (a, b) in [(x[0], y[0]), (x[0], y[1]), (x[1], y[0]), (x[1], y[1])]:
    for p in pairs:
        if all_differ((a, b), p):
            break
    else:
        print("YES")
        exit(0)

print("NO")