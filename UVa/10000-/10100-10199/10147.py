# UVa 10147 - Highways
# MST
class UnionFind:
    def __init__(self, N):
        self.parent, self.rank = [], []
        for i in range(N+1):
            self.parent.append(i)
            self.rank.append(0)
        
    def FindSet(self, i):
        if self.parent[i] == i: return i
        self.parent[i] = self.FindSet(self.parent[i])
        return self.parent[i]
    
    def IsSameSet(self, i, j):
        return self.FindSet(i) == self.FindSet(j)
    
    def UnionSet(self, i, j):
        x, y = self.FindSet(i), self.FindSet(j)

        if x != y:
            self.parent[y] = x
        else:
            self.parent[x] = y
            if self.rank[x] == self.rank[y]: self.rank[y] += 1

TC = int(input())

while TC > 0:
    input()
    N = int(input())
    uf = UnionFind(N)
    edgeList, roads, pos = [], [], []

    for i in range(N):
        x, y = list(map(int, input().split(' ')))
        pos.append([x, y])

    for i in range(N-1):
        for j in range(i+1, N):
            d = (pos[i][0]-pos[j][0]) ** 2 + (pos[i][1]-pos[j][1]) ** 2
            edgeList.append([i+1, j+1, d])
    edgeList = sorted(edgeList, key=lambda x: x[2])

    M = int(input())

    for i in range(M):
        v1, v2 = list(map(int, input().split(' ')))
        uf.UnionSet(v1, v2)

    for i, e in enumerate(edgeList):
        v1, v2, d = e
        if not uf.IsSameSet(v1, v2):
            uf.UnionSet(v1, v2)
            roads.append([v1, v2])
            print(v1, v2)

    if roads == []: print('No new highways need')
    TC -= 1