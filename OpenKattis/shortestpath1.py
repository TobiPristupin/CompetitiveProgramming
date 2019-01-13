import heapq

def dijkstra(graph, start_vertex):
    distances = {vertex: float("inf") for vertex in graph}
    distances[start_vertex] = 0
    priority_queue = []

    for vertex, distance in distances.items():
        entry = (distance, vertex)
        heapq.heappush(priority_queue, entry)

    while len(priority_queue) > 0:
        weight, current_vertex = heapq.heappop(priority_queue)

        for neighbor, weight in graph[current_vertex].items():
            if distances[current_vertex] + weight < distances[neighbor]:
                distances[neighbor] = distances[current_vertex] + weight

    return distances


inp = input()

while True:
    n, m, q, start_vertex = map(int, inp.split())

    graph = {vertex: dict() for vertex in range(n)}
    for _ in range(m):
        u, v, w = map(int, input().split())
        graph[u][v] = w

    distances = dijkstra(graph, start_vertex)

    for _ in range(q):
        end_vertex = int(input())
        print(distances[end_vertex]) if distances[end_vertex] != float("inf") else print("Impossible")

    inp = input()
    if inp != "0 0 0 0":
        print()
        pass
    else:
        break




