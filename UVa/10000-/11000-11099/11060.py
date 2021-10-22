from collections import deque

# Topological Sort

def topsort(queue, in_edge, out_edge):
    for key in in_edge.keys():
        if in_edge[key] == []:
            queue.append(key)
    
    while queue:
        queue = sorted(queue, key=lambda x: bev_order[x], reverse=True)
        bev = queue.pop()
        print(' ' + bev, end='')
        bev_tmp_list = out_edge[bev].copy()

        for next_bev in bev_tmp_list:
            out_edge[bev].remove(next_bev)
            in_edge[next_bev].remove(bev)
            if in_edge[next_bev] == []:
                queue.append(next_bev)
    print('.')


TC = 1
while True:
    try:
        if TC != 1:
            print()
        N = input()
    except EOFError:
        break
    N = int(N)

    in_edge = {}
    out_edge = {}
    bev_order = {}
    queue = deque() # set of nodes with no in-edge

    for i in range(N):
        bev = input()
        in_edge[bev] = []
        out_edge[bev] = []
        bev_order[bev] = i

    M = int(input())
    for _ in range(M):
        bev1, bev2 = input().split(' ')
        if bev1 == bev2: continue
        in_edge[bev2].append(bev1)
        out_edge[bev1].append(bev2)
    input()
    print('Case #{}: Dilbert should drink beverages in this order:'.format(TC), end='')
    topsort(queue, in_edge, out_edge)
        
    TC += 1