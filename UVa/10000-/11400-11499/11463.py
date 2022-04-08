# UVa 11463 - Commandos
# SSSP (Floyd-Warshall algorithm O(V^3))
def AllPairsShortestPath():
    for k in range(N):
        for i in range(N):
            for j in range(N):
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

tc, TC = 1, int(input())

while tc <= TC:
    N = int(input())
    R = int(input())
    dist = [[1e9 for j in range(N)] for i in range(N)]
    for i in range(N): dist[i][i] = 0

    for i in range(R):
        v1, v2 = list(map(int, input().split(' ')))
        dist[v1][v2] = dist[v2][v1] = 1

    AllPairsShortestPath()

    s, d = list(map(int, input().split(' ')))
    ans = 0
    for i in range(N):
        ans = max(ans, dist[s][i] + dist[i][d])
    print('Case {}: {}'.format(tc, ans))
    tc += 1