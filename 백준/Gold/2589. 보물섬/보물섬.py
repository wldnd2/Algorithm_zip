import sys
from collections import deque
input = sys.stdin.readline

n, k = map(int, input().split())
graph = [list(input().strip()) for _ in range(n)]

result = -1
dxs = [-1, 1, 0, 0]
dys = [0, 0, -1, 1]

for i in range(n):
  max_value = 0
  for j in range(k):
    if graph[i][j] == 'L':
      visited = [[0]*k for _ in range(n)]
      visited[i][j] = 1
      q = deque()
      q.append((i, j, 0))
      while q:
        x, y, cnt = q.popleft()
        max_value = max(max_value, cnt)
        for dx, dy in zip(dxs, dys):
          nx = x + dx; ny = y + dy
          if 0 <= nx < n and 0 <= ny < k and visited[nx][ny] == 0 and graph[nx][ny] == 'L':
            visited[nx][ny] = 1
            q.append((nx, ny, cnt+1))
  result = max(result, max_value)
print(result)