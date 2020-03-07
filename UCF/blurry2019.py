t = int(input())
for tcase in range(1, t+1):
    n, k = map(int, input().split())
    img = [list(map(int, input().split())) for i in range(n)]
    dp = [[0 for i in range(n + 1)] for j in range(n + 1)]

    for i in range(1, n+1):
        for j in range(1,n+1):
            dp[i][j] = dp[i-1][j] + dp[i][j-1] + img[i-1][j-1] - dp[i-1][j-1]

    def sum_region(r1, c1, r2, c2):
        r1, c1, r2, c2 = r1+1, c1+1, r2+1, c2+1
        return dp[r2][c2] - dp[r2][c1-1] - dp[r1-1][c2] + dp[r1-1][c1-1]

    offset = (k-1)//2
    for r in range(n):
        for c in range(n):
            r1, c1, r2, c2 = r-offset, c-offset, r+offset, c+offset
            if r1 < 0 or r2 >= n or c1 < 0 or c2 >= n:
                img[r][c] = 0
                continue
            rect = sum_region(r1, c1, r2, c2)
            img[r][c] = round(rect / (k*k))

    print(f"Image #{tcase}:")
    for r in img:
        print(*r)
    if tcase != t:
        print()