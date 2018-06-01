import sys

books = []
total = 0

for linenum, line in enumerate(sys.stdin):
    if linenum == 0 :
        continue
    books.append(int(line))

books.sort(reverse=True)

for i in range(len(books)) :
    if  (i + 1) % 3 != 0 :
        total += books[i]

print(total)
