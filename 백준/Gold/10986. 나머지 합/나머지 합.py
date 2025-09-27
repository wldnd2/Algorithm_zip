# https://www.acmicpc.net/problem/10986
import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n, m = map(int, input().split())
data = list(map(int, input().split()))

dp = [0]
for i in range(n):
    dp.append(dp[i]+data[i])

mod = [0] * m
for i in dp:
    mod[i % m] += 1

result = 0
for i in mod:
    result += ((i*(i-1)//2))
print(result)