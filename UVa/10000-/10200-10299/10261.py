def knapsack():
    for i in range(1, len(cars)):
        car = cars[i]
        for l in range(L+1):
            # if previous car was successfully loaded
            if DP[i-1][l]:
                if car + l <= L:
                    DP[i][car+l] = True
                    ans[i][car+l] = 'starboard'
                    last[0] = [i, car+l]
                if (sum[i-1] - l) + car <= L:
                    DP[i][l] = True
                    ans[i][l] = 'port'
                    last[0] = [i, l]


L = int(input()) * 100
cars = [0]
sum = [0]

while True:
    l = int(input())
    if l == 0: break
    cars.append(l)
    sum.append(sum[-1] + l)

ans = [[0 for j in range(L+1)] for i in range(len(cars)+1)]
DP = [[False for j in range(L+1)] for i in range(len(cars)+1)] # DP[i][l]: if cars[i] can be put when sum_left == l
DP[0][0] = True
last = [0]

knapsack()

print(last)