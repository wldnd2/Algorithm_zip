import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n = int(input())
data = list(map(int, input().split()))
LIS = [1]*n
LDS = [1]*n

for i in range(n):
    for j in range(i):
        if data[j] < data[i]:
            LIS[i] = max(LIS[i], LIS[j]+1)

data_reverse = data[::-1][:]
for i in range(n):
    for j in range(i):
        if data_reverse[j] < data_reverse[i]:
            LDS[i] = max(LDS[i], LDS[j]+1)
LDS = LDS[::-1]

for i in range(n):
    LDS[i] = LIS[i]+LDS[i]-1

print(max(LDS))