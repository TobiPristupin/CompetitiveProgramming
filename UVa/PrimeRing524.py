def prime(n):
    if n <= 1: return False
    if n <= 3: return True
    if n % 2 == 0 or n % 3 == 0: return False

    i = 5
    while i ** 2 <= n:
        if n % i == 0 or n % (i+2) == 0:
            return False
        i += 6
    
    return True

def solve(n, arr, used, i=1):
    if i == n:
        if prime(arr[0] + arr[n-1]):
            print(" ".join(map(str, arr)))
        return

    for p in range(2, n + 1):
        if p not in used:
            if prime(arr[i - 1] + p):
                arr[i] = p
                used.add(p)
                solve(n, arr, used, i + 1)
                arr[i] = -1
                used.remove(p)

tcase = 1
n = int(input())
while True:
    arr = [-1] * n
    arr[0] = 1
    print("Case {}:".format(tcase))
    solve(n, arr, set())
    tcase += 1
    try:
        n = int(input())
        print()
    except EOFError:
        break