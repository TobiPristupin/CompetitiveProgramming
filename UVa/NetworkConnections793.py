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


tcases = int(input())
input()
for t in range(tcases):
    computers = int(input())
    union = UnionFind(computers)
    correct, wrong = 0, 0

    line = input()
    while line.strip() != "":
        instruction, a, b = line.split()
        a, b = int(a) - 1, int(b) - 1
        if instruction == "c":
            union.union(a, b)
        elif instruction == "q":
            if union.connected(a, b):
                correct += 1
            else:
                wrong += 1
        try:
            line = input()
        except EOFError:
            break
    
    print("{},{}".format(correct, wrong))
    if (t != tcases - 1): print()
    

