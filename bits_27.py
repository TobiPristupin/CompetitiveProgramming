import sys

for n in sys.stdin.readlines()[1:]:
	digits = list(str(n.replace("\n", "")))
	most = 0
	for i in range(1, len(digits) + 1):
		binary = bin(int("".join(digits[:i])))[2:]
		most = binary.count("1") if binary.count("1") > most else most
	print(most)
	