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

n, m = map(int, input().split())
while not (n == 0 and m == 0):
    edges = set()
    graph = UnionFind(n)
    for line in range(m):
        u, v, w = map(int, input().split())
        edges.add((min(u, v),  max(u, v), w))
        graph.union(u, v)
        graph.union(v, u)

    if graph.components() != 1:
        n, m = map(int, input().split())
        print("Impossible")
        continue
        
    
    edges = list(edges)
    edges.sort(key=lambda edge: edge[2])

    mst = []
    graph = UnionFind(n)
    cost = 0
    for edge in edges:
        if not graph.connected(edge[0], edge[1]):
            mst.append(edge)
            cost += edge[2]
            graph.union(edge[0], edge[1])
            graph.union(edge[1], edge[0])

    if len(mst) == 0:
        print("Impossible")
    else:
        print(cost)
        for edge in sorted(mst):
            print(edge[0], edge[1])
    
    n, m = map(int, input().split())
