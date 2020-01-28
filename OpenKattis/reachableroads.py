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


cities = int(input())
for _ in range(cities):
    m = int(input())
    r = int(input())
    union = UnionFind(m)
    for i in range(r):
        a, b = map(int, input().split())
        union.union(a, b)
        union.union(b, a)
    print(union.components() - 1)


