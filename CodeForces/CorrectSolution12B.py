n, shuffled = sorted([int(d) for d in input()]), input()
if str(int(shuffled)) != shuffled:
    print("WRONG_ANSWER")
    exit(0)
zeros = n.count(0)
n = n[zeros:zeros+1] + [0] * zeros + n[zeros+1:]
print("OK") if int("".join(map(str, n))) == int(shuffled) else print("WRONG_ANSWER")