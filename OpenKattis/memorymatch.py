from collections import Counter

n = int(input())
k = int(input())
cards = ["?" for _ in range(n)]
for _ in range(k):
    c1, c2, p1, p2 = input().split()
    if p1 == p2:
        cards[int(c1) - 1] = "*"
        cards[int(c2) - 1] = "*"
    else:
        cards[int(c1) - 1] = p1
        cards[int(c2) - 1] = p2


counter = Counter(cards)
ans = 0
for k, v in counter.most_common():
    if k not in ["*", "?"] and v == 2:
        ans += 1

ones = 0
for k, v in counter.most_common():
    if k not in ["*", "?"] and v == 1:
        ones += 1


if counter["?"] == ones:
    ans += ones
elif counter["?"] == 2:
    ans += 1

print(ans)