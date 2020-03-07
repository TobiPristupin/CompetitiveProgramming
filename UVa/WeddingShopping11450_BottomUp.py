t = int(input())
for tcase in range(t):
    m, c = map(int, input().split())
    dp = [[0 for i in range(m+1)] for j in range(c)]
    garments = []
    for _ in range(c):
        garments.append(list(map(int, input().split()))[1:])

    for p in garments[0]:
        if m - p >= 0:
            dp[0][m - p] = 1
    
    for i in range(1, len(garments)):
        for price in garments[i]:
            for j in range(len(dp[i - 1])):
                prev_state = dp[i - 1][j]
                if prev_state and j - price >= 0:
                    dp[i][j - price] = 1
    
    for j in range(len(dp[-1])):
        if dp[-1][j]:
            print(m - j)
            break
    else:
        print("no solution")