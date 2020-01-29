from math import sqrt

squares = {i**2 for i in range(1, 101)}

def solve():
    s = [c for c in input() if c.isalpha()]
    if len(s) not in squares:
        print("No magic :(")
        return

    k = int(sqrt(len(s)))
    i = 0
    arr = []
    for r in range(k):
        arr.append([])
        for c in range(k):
            arr[r].append(s[i])
            i += 1

    i = 0    
    for r in range(k):
        for c in range(k):
            if arr[r][c] != s[i]:
                print("No magic :(")
                return
            i += 1

    i = 0    
    for c in range(k):
        for r in range(k):
            if arr[r][c] != s[i]:
                print("No magic :(")
                return
            i += 1

    i = 0    
    for c in range(k):
        for r in range(k):
            if arr[r][c] != s[i]:
                print("No magic :(")
                return
            i += 1

    i = 0
    for r in range(k-1, -1, -1):
        for c in range(k-1, -1, -1):
            if arr[r][c] != s[i]:
                print("No magic :(")
                return
            i += 1

    i = 0
    for c in range(k-1, -1, -1):
        for r in range(k-1, -1, -1):
            if arr[r][c] != s[i]:
                print("No magic :(")
                return
            i += 1

    print(k)

t = int(input())
for tcase in range(t):
    print("Case #{}:".format(tcase+1))
    solve()
    
                