# 2179 비슷한 단어
# https://www.acmicpc.net/problem/2179
import sys
input = sys.stdin.readline

n = int(input())
data = [input().strip() for _ in range(n)]
s_data = sorted(list(enumerate(data)),key = lambda x: x[1])

check_similary = [0]*(n+1)
for i in range(n-1):
    cnt = 0
    for item1, item2 in zip(s_data[i][1], s_data[i+1][1]):
        if item1 == item2: cnt += 1
        else: break
    check_similary[s_data[i][0]] = max(check_similary[s_data[i][0]], cnt)
    check_similary[s_data[i+1][0]] = max(check_similary[s_data[i+1][0]], cnt)

max_length = max(check_similary)
first = True
for i in range(n):
    if first:
        if check_similary[i] == max_length:
            print(data[i])
            pre = data[i][:max_length]
            first = False
    else:
        if check_similary[i] == max_length and data[i][:max_length] == pre:
            print(data[i])
            break