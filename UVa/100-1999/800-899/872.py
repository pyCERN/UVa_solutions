# UVa 872 - Ordering
# Topological Sort

from collections import deque

in_edge, out_edge = {}, {}
visited = {}
var_list = []
ordered = []

def backtrack(ordered):
    for var in var_list:
        

TC = int(input())
input()

while TC:
    in_edge, out_edge = {}, {}
    visited = {}
    var_list = input().split(' ')
    order_list = input().split(' ')

    for var in var_list:
        in_edge[var] = []
        out_edge[var] = []
        visited[var] = False

    for order in order_list:
        A, B = order.split('<')
        in_edge[B].append(A)
        out_edge[A].append(B)

    backtrack(0, ordered)

    TC -= 1