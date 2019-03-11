from timeit import timeit
from collections import *
import itertools

def binary_search_recursive(arr, target, lo, hi):
    mid = (lo + hi) // 2
    if lo >= hi:
        return -1
    if arr[mid] == target:
        return mid
    if arr[mid] > target:
        return binary_search_recursive(arr, target, lo=lo, hi=mid-1)
    return binary_search_recursive(arr, target, lo=mid+1, hi=hi)


def binary_search_iterative(arr, target):
    lo, hi = 0, len(arr)
    mid = (lo + hi) // 2
    while lo <= hi:
        mid = (lo + hi) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] > target:
            hi = mid - 1
        else:
            lo = mid + 1
    return -1

def bubblesort(arr):
    for i in range(len(arr)):
        for j in range(len(arr) - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr

def selectionsort(arr):
    for i in range(len(arr)):
        min_index = i
        for j in range(i + 1, len(arr)):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]
    return arr

def binary_search_iter(target, arr):
    lo, hi = 0, len(arr) - 1
    while lo <= hi:
        mid = (hi + lo) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] > target:
            hi = mid - 1
        else:
            lo = mid + 1
    return lo

def bfs_has_path(graph, start, end):
    visited = set()
    search = deque()
    search += graph[start]

    while search:
        node = search.popleft()
        if node not in visited:
            if node == end:
                return True
            visited.update(node)
            search += graph[node]

    return False

def bfs_return_path(graph, start, end):
    if start == end:
        return [start]

    visited = {start}
    path = {k: None for k, v in graph.items()}
    search = deque([start])

    while search:
        node = search.popleft()
        for adjacent in graph[node]:
            if adjacent not in visited:
                path[adjacent] = node
                if adjacent == end:
                    return build_path(path, end)
                visited.update(adjacent)
                search += adjacent
    return []


def build_path(p, end):
    path = [end]
    current = p[end]
    while current:
        path.insert(0, current)
        current = p[current]

    return path


def bfs_node(start, end):
    if start == end:
        return True
    
    visited = set()
    search = deque([start])

    while search:
        node = search.popleft()
        for adjacent in node.adjacent:
            if adjacent in visited:
                continue
            if adjacent == end:
                return True
            visited.add(adjacent)
            search.append(adjacent)
    return False

def bfs_node_path(start, end):
    if start == end:
        return [start]

    visited = {start}
    path = {start: None}
    search = deque([start])

    while search:
        node = search.popleft()
        for adjacent in node.adjacent:
            if adjacent in visited:
                continue
            path[adjacent] = node
            if adjacent == end:
                return build_path(path, end)
            visited.add(adjacent)
            search.append(adjacent)
    return []



def node_indegree_0(graph):
    nodes = set(itertools.chain.from_iterable(graph.values()))
    for node in graph:
        if node not in nodes:
            return node
    return None

def dfs_has_path(graph, start, end, visited=None):
    if not visited:
        visited = set()
    if start == end:
        return True
    if start in visited:
        return False
    visited.add(start)

    for adjacent in graph[start]:
        if dfs_has_path(graph, adjacent, end, visited):
            return True
    return False

def islands_floodill(grid):
    count = 0
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == 1:
                count += 1
            remove_island(grid, i, j)
    return count

def remove_island(grid, r, c):
    in_bounds = lambda row, col: 0 <= row < len(grid) and 0 <= col < len(grid[row])
    if not in_bounds(r, c) or grid[r][c] == 0:
        return
    grid[r][c] = 0
    adjacent = [(r + 1, c), (r - 1, c), (r, c + 1), (r, c - 1)]
    [remove_island(grid, x, y) for x, y in adjacent]
    return

def fibonacci_no_recursion(n):
    if n == 0:
        return 0

    back1 = 1
    back2 = 0
    curr = 0 

    for i in range(2, n):
        curr = back1 + back2
        back2 = back1
        back1 = curr
    return back1 + back2

# https://www.nayuki.io/page/next-lexicographical-permutation-algorithm
def next_permutation(arr):
    arr = list(arr)
    i = len(arr) - 1
    while i > 0 and arr[i - 1] >= arr[i]:
        i -= 1
    if i <= 0:
        print("No permutation, it is already the biggest one")
        return False

    pivot = i - 1
    j = len(arr) - 1
    while arr[j] <= arr[pivot]:
        j -= 1

    arr[pivot], arr[j] = arr[j], arr[pivot]
    arr[i:] = arr[len(arr) - 1: pivot: -1]
    return arr

import heapq

#Works 99% of the time :(  Use with caution
def dijkstra(graph, start_vertex):
    distances = {vertex: float("inf") for vertex in graph}
    distances[start_vertex] = 0
    priority_queue = []

    for vertex, distance in distances.items():
        entry = (distance, vertex)
        heapq.heappush(priority_queue, entry)

    while len(priority_queue) > 0:
        weight, current_vertex = heapq.heappop(priority_queue)
        if weight == float("inf"): break

        for neighbor, weight in graph[current_vertex].items():
            if distances[current_vertex] + weight < distances[neighbor]:
                distances[neighbor] = distances[current_vertex] + weight

    return distances


def bellman_ford_negative_cycle(graph, start):
    distances = {vertex: float("inf") for vertex in graph}
    distances[start] = 0

    for i in range(len(graph) - 1):
        for vertex in graph:
            for neighbor, weight in graph[vertex].items():
                if distances[vertex] + weight < distances[neighbor]:
                    distances[neighbor] = distances[vertex] + weight

    for vertex in graph:
            for neighbor, weight in graph[vertex].items():
                if distances[vertex] + weight < distances[neighbor]:
                    return True

    return False

def longest_increasing_subsequence(arr):
    dp = [1] * len(arr)

    for i in range(1, len(arr)):
        for j in range(i):
            if arr[i] > arr[j]:
                dp[i] = max(dp[j] + 1, dp[i])

    return max(dp)