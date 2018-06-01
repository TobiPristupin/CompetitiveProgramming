import sys

books = []
total = 0

books = sorted(map(int, sys.stdin.read().split("\n")[1:]), reverse=True)

for i in range(len(books)) :
	if  (i + 1) % 3 != 0 :
		total += books[i]

print(total)


