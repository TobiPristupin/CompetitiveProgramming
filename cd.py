while True:
    n, m = map(int, input().split())
    if n == 0 and m == 0:
        break

    n = set(int(input()) for _ in range(n))
    total = 0
    for _ in range(m):
        if int(input()) in n:
            total += 1
    print(total)


