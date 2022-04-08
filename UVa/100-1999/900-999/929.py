# UVa 929 - Number Maze
# Dijkstra's algorithm
import queue


def bfs():
    dist = [[1e9 for j in range(M)] for i in range(N)]
    pq = queue.PriorityQueue()
    pq.put([0, 0, maze[0][0]]) # r, c, d
    dist[0][0] = maze[0][0]

    while not pq.empty():
        r, c, d = pq.get()
        if d > dist[r][c]: continue
        for i in range(4):
            rr, cc = r + dr[i], c + dc[i]
            if rr < 0 or rr >= N or cc < 0 or cc >= M: continue

            if dist[r][c] + maze[rr][cc] < dist[rr][cc]:
                dist[rr][cc] = dist[r][c] + maze[rr][cc]
                pq.put([rr, cc, dist[rr][cc]])
    
    print(dist[N-1][M-1])


# E, N, W, S
dr, dc = [0, -1, 0, 1], [1, 0, -1, 0]

TC = int(input())

while TC > 0:
    N = int(input())
    M = int(input())

    maze = []
    for i in range(N):
        maze.append(list(map(int, input().split(' '))))

    bfs()
    TC -= 1
