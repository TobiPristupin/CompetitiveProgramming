from collections import defaultdict

juices = defaultdict(lambda: float("inf"))
for _ in range(int(input())):
    cost, juice = input().split()
    juice = "".join(sorted(juice))
    juices[juice] = min(juices[juice], int(cost))

contains_abc = lambda s: "A" in s and "B" in s and "C" in s
one = juices["ABC"]
two = [juices[i] + juices[j] for i in juices for j in juices if i != j and contains_abc(i + j)]
two = min(two) if len(two) > 0 else float("inf")
three = juices["A"] + juices["B"] + juices["C"]
best = min(one, two, three)
print(best) if best != float("inf") else print(-1)