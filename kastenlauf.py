distance = lambda x, y: abs(x[0] - y[0]) + abs(x[1] - y[1])

def dfs(graph, start, end, visited=None):
    if not visited:
        visited = set()
    if start == end:
        return True
    if start in visited:
        return False
    visited.add(start)
    
    for neighbor in graph[start]:
        if dfs(graph, neighbor, end, visited):
            return True
    return False

for _ in range(int(input())):
    graph = {}
    numstores, start = int(input()), tuple(map(int, input().split()))
    for s in range(numstores):
        graph[tuple(map(int, input().split()))] = []
    end = tuple(map(int, input().split()))
    graph[start] = []
    graph[end] = []
    
    for i in graph:
        for j in graph:
            if i == j or i == end:
                continue
            dist = distance(i, j)
            if dist / 50 <= 20:
                graph[i].append(j)

    print("happy") if dfs(graph, start, end) else print("sad")