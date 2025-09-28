# 문제 링크: https://www.acmicpc.net/problem/9084
import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def solve(dp, coin, target):
    for i in range(coin, target+1):
        dp[i] = dp[i] + dp[i-coin]
    return dp

t = int(input())
for _ in range(t):
    n = int(input())
    coins = list(map(int, input().split()))
    m = int(input())
    dp = [0]*(m+1)
    dp[0] = 1
    for item in coins: 
        dp = solve(dp, item, m)
    print(dp[m])
