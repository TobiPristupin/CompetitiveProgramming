from collections import deque
from itertools import combinations, chain

def powerset(iterable):
    iterable = list(iterable)
    return list(chain.from_iterable(combinations(iterable, r) for r in range(1, len(iterable) + 1)))

chars = list(input())
stack = deque()
pairs = []

for i, char in enumerate(chars):
    if char == "(":
        stack.append(i)
    elif char == ")":
        pairs.append((stack.pop(), i))

answers = []
for combination in powerset(pairs):
    c = list(chars)
    avoid = [j for i in combination for j in i]
    answers.append("".join([char for i, char in enumerate(c) if i not in avoid]))

print(*sorted(set(answers)), sep="\n")

