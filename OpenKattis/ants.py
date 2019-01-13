import sys
import decimal

test_cases = int(input())

def find_border_ant(ants, length):
	closest = length
	for ant in ants :
		if abs(ant - length) < closest or ant < closest:
			closest = ant if ant < length / 2 else length - ant
	return closest

def find_center_ant(ants, length):
	closest = length
	for ant in ants:
		if abs(ant - (length / 2)) < closest:
			closest = abs(ant - (length / 2))
	return closest

def remove_trailing(n):
	n = decimal.Decimal(n)
	return n.to_integral() if n == n.to_integral() else n.normalize()

for _ in range(test_cases):
	length, n = map(int, input().split())
	ants = []
	while n > 0:
		x = list(map(int, input().split()))
		n -= len(x)
		ants.extend(x)

	center = find_center_ant(ants, length)
	mid = length / 2
	best_case = abs((mid + center) - length)
	worst_case = length - find_border_ant(ants, length)
	print("{} {}".format(remove_trailing(best_case), worst_case))

	


