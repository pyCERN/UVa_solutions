# UVa 558 - Wormholes
# Check negative cycle in weighted graph (Bellman-Ford algorithm O(VE))
def CheckNegCycle():
    dist = [1e9 for _ in range(n)]
    dist[0] = 0

    for i in range(n-1):
        for u in range(n):
            for v, t in adjList[u]:
                dist[v] = min(dist[v], dist[u] + t)

    for u in range(n):
        for v, t in adjList[u]:
            if dist[v] > dist[u] + t:
                return True
    return False


TC = int(input())

while TC > 0:
    n, m = list(map(int, input().split(' ')))
    adjList = {}
    for i in range(n): adjList[i] = []

    for i in range(m):
        x, y, t = list(map(int, input().split(' ')))
        adjList[x].append([y, t])

    if CheckNegCycle(): print('possible')
    else: print('not possible')
    TC -= 1