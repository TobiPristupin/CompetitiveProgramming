def simulate(k):
    barely = False
    for i in range(len(rugs) - 1):
        if rugs[i + 1] - rugs[i] > k:
            return False, False
        elif rugs[i + 1] - rugs[i] == k:
            k -= 1
            barely = True
    return barely, True

t = int(input())
for tcase in range(1, t + 1):
    n = int(input())
    rugs = list(map(int, input().split()))
    rugs.insert(0, 0)
    diff = 0
    for i in range(1, len(rugs)):
        print(rugs[i] - rugs[i - 1], end = " ")
        diff = max(diff, rugs[i] - rugs[i - 1])
    print()
    
    lo, hi = diff, pow(10, 7) + 1
    k = (lo + hi) // 2
    barely, success = simulate(k)
    tries = 0
    while not (success and barely):
        print(lo, hi, k, success, barely)

        if tries > 200:
            r = 1/ 0
            
        if not success:
            lo = k + 1
        if success and not barely:
            hi = k

        k = (lo + hi) // 2
        barely, success = simulate(k)
        tries += 1

    print("Case {}: {}".format(tcase, k))
        

