import sys; input = sys.stdin.readline
from collections import deque

def bfs(start):
  q = deque([start])
  visited = [-1] * (n+1)
  visited[start] = 0
  while q:
    v = q.popleft()
    for x in adjency[v]:
      if visited[x] < 0:
        q.append(x)
        visited[x] = visited[v] + 1
  return visited

n, m = map(int, input().split())
adjency = [[] for _ in range(n+1)]
for _ in range(m):
  x, y = map(int,input().split())
  adjency[x].append(y)
  adjency[y].append(x)

print(sorted([(sum(bfs(i)[1:]),i) for i in range(1, n+1)])[0][1])