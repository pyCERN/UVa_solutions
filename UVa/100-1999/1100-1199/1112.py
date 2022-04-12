# UVa 1112 - Mice and Maze
# Shortest path on weighted graph (Dijkstra's algorithm)
import queue


def dijkstra(s):
    dist = [1e9 for _ in range(N+1)]; dist[s] = 0
    pq = queue.PriorityQueue(); pq.put([s, 0])

    while not pq.empty():
        u, t = pq.get()
        if t > dist[u]: continue
        for v, w in edgeList[u]:
            if dist[v] > dist[u] + w:
                dist[v] = dist[u] + w
                pq.put([v, dist[v]])

    return dist[E] <= T

TC = int(input())

while TC > 0:
    input()
    N = int(input())
    E = int(input())
    T = int(input())
    M = int(input())
    ans = 0

    edgeList = {}
    for i in range(1, N+1): edgeList[i] = []

    for i in range(M):
        a, b, t = list(map(int, input().split(' ')))
        edgeList[a].append([b, t])

    for i in range(1, N+1):
        ans += dijkstra(i)
    print(ans)
    TC -= 1
    if TC: print()