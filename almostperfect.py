import sys, math
from collections import deque

for line in sys.stdin.readlines():
    num = int(line)
    divisors = deque()
    for i in range(1, int(math.sqrt(num)) + 1):
        if num % i == 0:
            if num / i == i or num / i == num:
                divisors.append(i)
            else:
                divisors.append(i)
                divisors.append(num/i)
    divisors = sum(divisors)
    if divisors == num:
        print("{} perfect".format(num))
    elif abs(divisors - num) <= 2:
        print("{} almost perfect".format(num))
    else:
        print("{} not perfect".format(num))