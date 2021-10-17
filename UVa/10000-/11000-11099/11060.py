from collections import deque


in_edge = {}
out_edge = {}
queue = deque() # set of nodes with no in-edge

N = int(input())
for i in range(N):
    bev = input()
    in_edge[bev] = []
    out_edge[bev] = []

M = int(input())
for _ in range(M):
    bev1, bev2 = input().split(' ')
    in_edge[bev2].append(bev1)
    out_edge[bev1].append(bev2)

