# UVa 732 - Anagrams by Stack
# DFS
import sys


in_str, out_str = '', ''
# E, S
dr, dc = [0, 1], [1, 0]

'''
(N+1) x (N+1) grid
push/pop for right/down direction
Only upper triangle paths are available (more push than pop)
'''
def dfs(push_str, pop_str, ops, r, c):
    if r == N and c == N:
        if pop_str == out_str:
            ans.append(ops)
        return

    for i in [0, 1]:
        rr, cc = r+dr[i], c+dc[i]
        if rr > cc or rr > N or cc > N:
            continue

        if i == 0:
            dfs(push_str+in_str[cc-1], pop_str, ops+'i', rr, cc)
        else:
            dfs(push_str[:-1], pop_str+push_str[-1], ops+'o', rr, cc)


i = 0
for line in sys.stdin:
    if line == '\n': continue
    line = line[:-1]
    if i % 2 == 0:
        in_str = line
    else:
        out_str = line
        N = len(in_str)

        ans = []
        dfs('', '', '', 0, 0)

        print('[')
        for ops in ans:
            print(' '.join(ops))
        print(']')

    i += 1
