b = int(input())
for r in range(1, b+1):
    s = int(input())
    arr = [int(input()) for i in range(s-1)]
    n = len(arr)


    dp = [0 for i in range(n)]
    length = [1 for i in range(n)]
    dp[0] = arr[0]
    for i in range(1, n):
        follow, new = dp[i-1] + arr[i], arr[i]
        if follow >= new:
            dp[i] = follow
            length[i] = length[i-1] + 1
        else:
            dp[i] = new
            length[i] = 1
        
    

    # print(f"arr: {arr}")
    # print(f"dp: {dp}")
    # print(f"length: {length}")
    # print(f"best: {max(dp)}")

    best = max(dp)

    if best < 0:
        print(f"Route {r} has no nice parts")
        continue

    solutions = []
    for i in range(n):
        if dp[i] == best:
            solutions.append((i + 2 - length[i], i + 2))
    solutions.sort(reverse=True, key=lambda sol: (sol[1] - sol[0], -sol[0]))

    print(f"The nicest part of route {r} is between stops {solutions[0][0]} and {solutions[0][1]}")