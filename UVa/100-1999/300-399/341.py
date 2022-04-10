# UVa 341 - Non-Stop Travel
# Shortest path (Floyd-Warshall algorithm)
def ShortestPath():
    for k in range(n):
        for i in range(1, n+1):
            for j in range(1, n+1):
                adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
            
tc = 1

while True:
    n = int(input())
    if n == 0: break
    adjMat = [[1e9 for j in range(n+1)] for i in range(n+1)]

    for i in range(1, n+1):
        s = list(map(int, input().split(' ')))
        for j in range(1, len(s), 2):
            adjMat[i][s[j]] = s[j+1]

    ShortestPath()

    s, e = list(map(int, input().split(' ')))
    print('Case {}: Path = {} {}; {} second delay'.format(tc, s, e, adjMat[s][e]))
    tc += 1

    input()
