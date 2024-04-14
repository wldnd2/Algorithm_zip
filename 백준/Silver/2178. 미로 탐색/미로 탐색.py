# 2178 미로탐색
import sys
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().split())
graph = [list(map(int, list(input().strip()))) for i in range(n)]
queue = deque([(0,0)])
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
while queue:
    # pop()? 과 popleft()? 무슨차이??? -> 답이 달라지는 이유?
    x, y  = queue.popleft()
    for i in range(4):
        new_x = x + dx[i]
        new_y = y + dy[i]
        if 0 <= new_x < n and 0 <= new_y < m and graph[new_x][new_y] == 1:
            queue.append((new_x, new_y))
            graph[new_x][new_y] = graph[x][y] + 1

print(graph[-1][-1])