# UVa 10305 - Ordering Tasks
# Topological sort
def dfs(i):
    visited[i] = True
    for j in adjList[i]:
        if not visited[j]:
            dfs(j)
    ans.append(i)

while True:
    n, m = list(map(int, input().split(' ')))
    if n == 0 and m == 0: break
    adjList = {}
    for i in range(n): adjList[i+1] = []
    for i in range(m):
        v1, v2 = list(map(int, input().split(' ')))
        adjList[v1].append(v2)

    visited = [False for _ in range(n+1)]
    ans = []
    for i in range(1, n+1):
        if not visited[i]: dfs(i)

    while len(ans) > 1:
        print(ans.pop(), end=' ')
    print(ans[0])