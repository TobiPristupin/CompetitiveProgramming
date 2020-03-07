from collections import defaultdict

n, m, s, t = map(int, input().split())
graph = defaultdict(set)
for _ in range(m):
    u, v = map(int, input().split())
    graph[u].add(v)
    graph[v].add(u)

received_prev = [0 for _ in range(n)] #Squawks received in last iteration
received_prev[s] = 1

for time in range(t):
    squawks = 0
    received = [0 for _ in range(n)]
    for node, v in enumerate(received_prev):
        if v > 0:
            for neighbor in graph[node]:
                received[neighbor] += v
                squawks += v
    received_prev = received

print(squawks)

