# UVa 1208 - Oreon
# MST
class UnionFind:
    def __init__(self, n):
        self.parent = []
        self.rank = []
        for i in range(n):
            self.parent.append(i)
            self.rank.append(0)

    def FindSet(self, i):
        if self.parent[i] == i:
            return i
        self.parent[i] = self.FindSet(self.parent[i])
        return self.parent[i]
    
    def IsSameSet(self, i, j):
        return self.FindSet(i) == self.FindSet(j)

    def UnionSet(self, i, j):      
        if not self.IsSameSet(i, j):
            x, y = self.FindSet(i), self.FindSet(j)

            if self.rank[x] > self.rank[y]:
                self.parent[y] = x
            else:
                self.parent[x] = y
                self.rank[y] += 1

TC = int(input())
tc = 1
while tc <= TC:
    n_cities = int(input())
    min_cost = 0
    uf = UnionFind(n_cities)
    edge_list = []

    for i in range(n_cities):
        weights = list(map(int, input().split(', ')))
        for j, w in enumerate(weights):
            if i != j and w != 0:
                edge_list.append([w, [i, j]])

    edge_list = sorted(edge_list, key=lambda x: x[0])

    print('Case {}:'.format(tc))
    for i in range(len(edge_list)):
        edge = edge_list[i]

        if not uf.IsSameSet(edge[1][0], edge[1][1]):
            min_cost += edge[0]
            uf.UnionSet(edge[1][0], edge[1][1])
            print(chr(edge[1][0]+65) + '-' + chr(edge[1][1]+65) + ' ' + str(edge[0]))
    
    tc += 1