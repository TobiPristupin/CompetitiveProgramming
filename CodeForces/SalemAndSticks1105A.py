n, arr = int(input()), list(map(int, input().split()))

def find_cost(arr, t):
    cost = 0
    for x in arr:
        if x == t:
            continue
        elif x < t:
            cost += t - x - 1
        else:
            cost += x - t - 1
    
    return cost


small, big = min(arr), max(arr)
cost = [[t, find_cost(arr, t)] for t in range(small, big + 1)]
best = min(cost, key=lambda x: x[1])
print(*best)

