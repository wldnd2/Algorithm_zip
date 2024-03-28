import sys; input = sys.stdin.readline

n, k = map(int, input().split())
coins, memo = [int(input()) for _ in range(n)], [0] * (k+1)

for coin in coins:
  for i in range(coin, k+1):
    if i == coin : memo[i] += 1
    else: memo[i] += memo[i-coin]

print(memo[-1])