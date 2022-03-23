# UVa 10664 - Luggage
# DP (knapsack)
def knapsack():
    for i in range(1, len(weights)+1):
        w = weights[i-1]
        for remW in range(sum_weight_half+1)[::-1]:
            if w > remW:
                DP[i][remW] = DP[i-1][remW]
            else:
                DP[i][remW] = max(DP[i-1][remW], w + DP[i-1][remW-w])


m = int(input())

while m > 0:
    weights = list(map(int, input().split(' ')))
    sum_weight = sum(weights)
    if sum_weight % 2 != 0:
        print('NO')
        m -= 1
        continue
    sum_weight_half = int(sum_weight / 2)
    DP = [[0 for j in range(sum_weight_half+1)] for i in range(len(weights)+1)]

    knapsack()
    if DP[-1][sum_weight_half] == sum_weight_half:
        print('YES')
    else:
        print('NO')
    m -= 1
