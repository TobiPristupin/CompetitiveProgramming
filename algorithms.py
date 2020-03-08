from timeit import timeit
from collections import *
import itertools
import bisect

#bisect.bisect_left(arr, val) same as std:lower_bound. bisect_right same as std::upper_bound

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

def component_size(graph, start, visited=None):
    if not visited:
        visited = set()
    if start in visited:
        return 0
    visited.add(start)
    return 1 + sum([component_size(graph, v, visited) for v in graph[start]])


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


print(max_range_sum([4, -5, 4, -3, 4, 4, -4, 4, -5]))
# print(arr)
# build(0, len(arr) - 1)
# print(tree)
# update(0, len(arr) - 1, 3, 10)
# print(tree)




