from collections import deque


adj_list = {}
adj_rev_list = {}
drinked = {}
queue = deque()
'''
0: []
1: [0]
2: [0, 1]
3: [1, 2]
4: [3]
5: [2]
6: [7]
7: []

0: [1, 2]
1: [2, 3]
2: [3, 5]
3: [4]
4: []
5: []
6: []
7: [6]

[1, 2
'''
def bfs(bev):
    drink_queue = deque()
    drink_queue.append(bev)

    while drink_queue:
        
    

N = int(input())
for _ in range(N):
    bev = input()
    adj_list[bev] = []
    drinked[bev] = False
    

M = int(input())
for _ in range(M):
    bev1, bev2 = input().split(' ')
    adj_list[bev2].append(bev1)
    adj_rev_list[bev1].append(bev2)

for bev in adj_rev_list.keys():
    if adj_rev_list[bev] == []:
        queue.append(bev)
        bfs(bev)