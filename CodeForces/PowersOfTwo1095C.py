from collections import deque

n, k = map(int, input().split())
binary = bin(n)
powers = deque([2**i for i, bit in enumerate(reversed(binary)) if bit == "1"])

if len(powers) > k or k > n:
    print("NO")
    exit(0)

print("YES")
ones = 0
while len(powers) + ones != k:
    x = powers.pop()

    if x == 1:
        ones += 1
    elif x // 2 == 1:
        ones += 2
    else:
        powers.append(x // 2)
        powers.append(x // 2)

powers.extend([1] * ones)
print(*powers)



