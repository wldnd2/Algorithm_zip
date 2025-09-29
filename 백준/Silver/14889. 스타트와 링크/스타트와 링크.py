# 문제 링크: https://www.acmicpc.net/problem/15661
import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n = int(input())
data = [list(map(int, input().split())) for _ in range(n)]
visited = [False] * n
result = []

def bk(pre, depth):
    if depth == n//2:
        start, link = 0, 0
        for i in range(n):
            for j in range(n):
                if i == j: continue
                if visited[i] and visited[j]:
                    start += data[i][j]
                elif not visited[i] and not visited[j]:
                    link += data[i][j]
        result.append(abs(start-link))
        return result
    else:
        for i in range(pre, n):
            if not visited[i]: 
                visited[i] = True
                bk(i, depth+1)
                visited[i] = False
    return result

print(min(bk(0, 0)))