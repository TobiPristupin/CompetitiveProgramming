t = int(input())
for _ in range(t):
    n = int(input())
    s = {input() for i in range(n)}
    print(len(s))