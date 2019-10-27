t = int(input())
for _ in range(t):
    n = int(input())
    gear = {}
    for i in range(n):
        x, category = input().split()
        if category not in gear:
            gear[category] = 1
        gear[category] += 1
    combos = 1
    for category in gear:
        combos *= gear[category]
    print(combos-1)

