from timeit import timeit
from collections import *
import itertools
import bisect

#bisect.bisect_left(arr, val) same as std:lower_bound. bisect_right same as std::upper_bound


def bfs(graph, start, end):
    visited = set()
    search = deque()
    search += graph[start]

    while search:
        node = search.popleft()
        if node not in visited:
            if node == end:
                return True
            visited.add(node)
            search += graph[node]

    return False

def bfs_with_path(graph, start, end):
    parent = {}
    search = deque()
    visited = set()
    search += start
    while search:
        node = search.popleft()
        if node not in visited:
            visited.add(node)
            if node == end:
                return backtrack_path(parent, start, end)
            
            for adjacent in graph[node]:
                parent[adjacent] = node
                search += adjacent
    return backtrack_path(parent, start, end)

def backtrack_path(parent, start, end):
    path = deque()
    path.append(end)
    curr = parent[end]
    while path[0] != start:
        path.appendleft(curr)
        curr = parent[curr]
    return path


graph = {
        "A": ["B", "C"],
        "B": ["A"],
        "C": ["B"]
        }

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

#0 Indexed
class UnionFind():

    def __init__(self, size):
        self.id = [i for i in range(size)]
        self.__size = [1 for i in range(size)]
        self.__components = size
    
    def union(self, a, b):
        root_a, root_b = self.find(a), self.find(b)
        if root_a == root_b:
            return #Already connected
        if self.__size[root_a] > self.__size[root_b]:
            self.id[root_b] = root_a
            self.__size[root_a] += self.__size[root_b]
        else:
            self.id[root_a] = root_b
            self.__size[root_b] += self.__size[root_a]

        self.__components -= 1

    def connected(self, a, b):
        return self.find(a) == self.find(b)
    
    def find(self, a):
        root = a
        while self.id[root] != root:
            root = self.id[root]

        #Path Compression
        while a != root:
            _next = self.id[a]
            self.id[a] = root
            a = _next

        return root

    def components(self):
        return self.__components

    def size(self, a):
        return self.__size[self.find(a)]


arr = [1, 3, -2, 8, -7]
tree = [0] * (len(arr) * 4)

def build(lo, hi, node=1):
    if (lo == hi):
        tree[node] = arr[lo]
        return
    
    mid = (lo + hi) // 2
    build(lo, mid, 2*node)
    build(mid + 1, hi, 2*node+1)
    tree[node] = tree[2*node] + tree[2*node+1]

def sum_query(lo, hi, start, end, node=1):
    if start > hi or end < lo:
        return 0
    if start == lo and end == hi:
        return tree[node]
    
    mid = (lo + hi) // 2
    left_sum = sum_query(lo, mid, start, min(end, mid), 2*node)
    right_sum = sum_query(mid+1, hi, max(start, mid+1), end, 2*node+1)
    return left_sum + right_sum

def update(lo, hi, idx, val, node=1):
    if lo == hi:
        tree[node] = val
        arr[idx] = val
        return
    
    mid = (lo + hi) // 2
    if idx <= mid:
        update(lo, mid, idx, val, node*2)
    else:
        update(mid + 1, hi, idx, val, node*2+1)
    
    tree[node] = tree[2*node] + tree[2*node+1]

def prime(n):
    if n <= 1: return False
    if n <= 3: return True
    if n % 2 == 0 or n % 3 == 0: return False

    i = 5
    while i ** 2 <= n:
        if n % i == 0 or n % (i+2) == 0:
            return False
        i += 6
    
    return True

def kruskal_minspantree(edges: list):
    #greedy algorithm
    #1: sort the edges of the graph by their weights
    #2: start adding edges to the mst starting from the lowest weight
    #3: if an edge creates a cycle in the mst so far, don't add it. UFDS can be 
    #used to check if a cycle is created.
    mst_graph = UnionFind()
    mst = deque()
    cost = 0
    edges.sort(key=lambda x: x[2]) #Assuming each edge is a (u, v, w) tuple
    for edge in edges:
        u, v, w = edge
        if not mst_graph.connected(u, v):
            mst.append(edge)
            cost += w
            mst_graph.union(u, v)

    #if the length of mst if 0, no mst exists. 
    #keep in mind that if the graph is not connected, this would yield two different
    #mst's. Check for connectedness before using UFDS.components() == 1
    
    return cost #or mst if the actual tree is needed

def matrix_prefix_sum(matrix: list):
    #O(n) runtime
    #dp[i, j] represents the sum of the rectangle spanning from (0, 0) to (i, j)
    #dp[i, j] = dp[i-1][j] + dp[i][j-1] + matrix[i-1][j-1] - dp[i-1][j-1]
    #sum_region(r1, c1, r2, c2) = dp[r2][c2] - dp[r2][c1-1] - dp[r1-1][c2] + dp[r1-1][c1-1]
    #remember that dp size is (n+1) x (n+1), so the indices in matrix are shifted by one. sum_query assumes
    #that the indices have already been shifted
    n = len(matrix) 
    dp = [[0 for i in range(n + 1)] for j in range(n + 1)]

    for i in range(1, n+1):
        for j in range(1,n+1):
            dp[i][j] = dp[i-1][j] + dp[i][j-1] + matrix[i-1][j-1] - dp[i-1][j-1]

    def sum_region(r1, c1, r2, c2):
        r1, c1, r2, c2 = r1+1, c1+1, r2+1, c2+1
        return dp[r2][c2] - dp[r2][c1-1] - dp[r1-1][c2] + dp[r1-1][c1-1] 
    
    return dp

def max_range_sum(arr, i=0, cumsum=0):
    # #find maximum sum that can be achieved by adding a range [i, j] of the array
    dp = [0 for i in range(len(arr))]
    dp[0] = max(0, arr[0])
    for i in range(1, len(arr)):
        dp[i] = max(dp[i-1] + arr[i], 0)
    return max(dp)

# print(arr)
# build(0, len(arr) - 1)
# print(tree)
# update(0, len(arr) - 1, 3, 10)
# print(tree)