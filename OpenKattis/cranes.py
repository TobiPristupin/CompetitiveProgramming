import math

def available_space(cranes, x):
    for c in cranes:
        if math.sqrt((c[0] - x[0]) ** 2 + (c[1] - x[1]) ** 2) <= c[2] + x[2]:
            return False
    return True

def main(cranes, n=0, selected=[]):
    if n == len(cranes):
        return 0
    elif not available_space(selected, cranes[n]):
        return main(cranes, n+1, selected)
    else:
        dont_add = main(cranes, n+1, selected)
        add = cranes[n][2] ** 2 + main(cranes, n+1, selected + [cranes[n]])
        return max(add, dont_add)


for _ in range(int(input())):
    cranes = []
    for c in range(int(input())):
        cranes.append(list(map(int, input().split())))
    print(main(cranes))
    









    