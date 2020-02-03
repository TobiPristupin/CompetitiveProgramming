def solve():
    conditions = [tuple(input().split()) for i in range(3)]
    coins = list("ABCDEFGHIJKL")
    for cond in conditions:
        if cond[2] == "even":
            for coin in cond[0] + cond[1]:
                try:
                    coins.remove(coin)
                except ValueError:
                    pass

    for coin in coins:
        for value in [-1, 1]:
            for condition in conditions:
                sum_left = value if coin in condition[0] else 0
                sum_right = value if coin in condition[1] else 0
                if (sum_left == sum_right and condition[2] != "even") or (sum_left > sum_right and condition[2] != "up") or (sum_right > sum_left and condition[2] != "down"):
                    break
            else:
                print("{} is the counterfeit coin and it is {}.".format(coin, "light" if value == -1 else "heavy"))
                return

n = int(input())
for _ in range(n):
    solve()          
    