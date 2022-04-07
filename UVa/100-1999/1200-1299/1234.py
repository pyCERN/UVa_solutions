# UVa 1234 - RACING
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
            if self.rank[x] > self.rank[y]:
                self.parent[y] = x
            else:
                self.parent[x] = y
                if self.rank[x] == self.rank[y]: self.rank[y] += 1
    

TC = int(input())

while TC > 0:
    n, m = list(map(int, input().split(' ')))
    edgeList = []
    uf = UnionFind(n)
    cost = 0

    for i in range(m):
        v1, v2, w = list(map(int, input().split(' ')))
        edgeList.append([v1, v2, w])
        cost += w

    edgeList = sorted(edgeList, key=lambda x: -x[2])

    for i, e in enumerate(edgeList):
        v1, v2, w = e
        if not uf.IsSameSet(v1, v2):
            uf.UnionSet(v1, v2)
            cost -= w
    print(cost)
    TC -= 1
input()
