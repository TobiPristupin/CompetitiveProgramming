from collections import deque, defaultdict

n, m, d = map(int, input().split())
t = {name:int(t) for name, t in (input().split() for _ in range(n))}
graph = defaultdict(set)
for _ in range(m):
    u, v = input().split()
    graph[u].add(v)
    graph[v].add(u)

root = input()

day_heard_rumor = {}
day_heard_rumor[root] = 0
heard = set()
spreading = set()
spreading.add(root)
spreaders = deque()
spreaders.append(root)


while spreaders:
    node = spreaders.popleft()
    if day_heard_rumor[node] >= d:
        continue

    for neighbor in graph[node]:
        heard.add(neighbor)
    
        if neighbor not in spreading:
            t[neighbor] -= 1
            if t[neighbor] == 0:
                spreading.add(neighbor)
                day_heard_rumor[neighbor] = day_heard_rumor[node] + 1
                spreaders.append(neighbor)
                
heard.discard(root)
print(len(heard))