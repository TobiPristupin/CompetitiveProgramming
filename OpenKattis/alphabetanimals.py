letter = input()[-1]
words = [input() for _ in range(int(input()))]

starts_with = {}
for w in words:
    if w[0] not in starts_with:
        starts_with[w[0]] = []
    starts_with[w[0]].append(w)


if letter not in starts_with:
    print("?")
    exit(0)

for w in words:
    if w[0] == letter and (w[-1] not in starts_with or (len(starts_with[w[-1]]) == 1 and starts_with[w[-1]][0] == w)):
        print(w + "!")
        exit(0) 

for w in words:
    if w[0] == letter:
        print(w)
        exit(0)