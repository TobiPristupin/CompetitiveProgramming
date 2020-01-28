from collections import deque

n = int(input())
while n != -1:
    matrix = [input().split() for _ in range(n)]
    graph = {i:set() for i in range(n)}
    for r in range(n):
        for c in range(n):
            if matrix[r][c] == "1":
                graph[r].add(c)

    ans = deque()

    for v, neighbors in graph.items():
        if (len(neighbors) < 2):
            ans.append(v)
            continue

        weak = True
        for i in neighbors:
            if not weak:
                break

            for j in neighbors:
                if i != j and j in graph[i] and i in graph[j]:
                    weak = False

        if (weak): 
            ans.append(v)

    print(" ".join(map(str, ans)))

    n = int(input())