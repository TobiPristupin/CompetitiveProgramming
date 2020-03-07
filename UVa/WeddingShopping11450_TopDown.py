def solve(money, i):
    if money < 0:
        return float("inf")

    if memo[money][i] != None:
        return memo[money][i]
    elif i == c:
        result = money
    else:
        result = min([solve(money - g, i + 1) for g in garments[i]])
    memo[money][i] = result
    return result

t = int(input())
for tcase in range(t):
    m, c = map(int, input().split())
    memo = [[None for i in range(c+1)] for j in range(m+1)]
    garments = []
    for _ in range(c):
        garments.append(list(map(int, input().split()))[1:])
    
    ans = solve(m, 0)
    if ans == float("inf"):
        print("no solution")
    else:
        print(m - ans)
    