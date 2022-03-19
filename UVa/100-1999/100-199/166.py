# UVa 166 - Making Change
# DP (coin change)
# Minimize the number of coins in transaction

coins = [5, 10, 20, 50, 100, 200]

def coin_change():
        # Customer buys from shopkeeper
        for i, c in enumerate(coins):
            while num_coins[i] > 0:
                for v in range(c, 501, 5)[::-1]:
                    DP[v] = 1 + DP[v-c]
                num_coins[i] -= 1
            
            # DP without number limitation
            for v in range(c, 501, 5):
                    DP2[v] = 1 + DP2[v-c]


while True:
    inputs = input().split(' ')
    num_coins = list(map(int, inputs[:6]))
    if num_coins == [0, 0, 0, 0, 0, 0]:
        break

    value = int(float(inputs[-1])*1000 / 10)

    DP = [1000000 for _ in range(501)]
    DP2 = [1000000 for _ in range(501)]
    DP[0] = DP2[0] = 0

    coin_change()

    # Shopkeeper buys from customer
    ans = 1000000

    for v in range(value, 501, 5):
        # Pay more than value and receive change
        ans = min(ans, DP[v] + DP2[v-value])

    print('%3d'%(ans))

