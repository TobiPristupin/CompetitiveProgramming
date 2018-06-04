import sys
import math

p, a, b, c, d, n = map(int, sys.stdin.read().split(" "))

if n == 0:
	print(0)
	sys.exit()

def price(k):
	return (p * (math.sin(a * k + b) + math.cos(c * k + d) + 2))

prices = [price(i) for i in range(1, n + 1)]

max_decline = 0
max_price = prices[0]

for i in prices[1:]:
	i = max(max_price, i)
	max_decline = max(max_decline, max_price - i)

print(max_decline)


