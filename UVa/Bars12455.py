import math

def solve(arr, n, used):
    if n == 0:
        return True
    if n < 0:
        return False
    
    for i in range(len(arr)):
        if not used[i]:
            used[i] = True
            if solve(arr, n - arr[i], used):
                return True
            used[i] = False
    
    return False
    

t = int(input())
for _ in range(t):
    n = int(input())
    p = int(input())
    arr = list(map(int, input().split()))
    used = [False] * p
    ans = solve(arr, n, used)
    print("YES" if ans else "NO")