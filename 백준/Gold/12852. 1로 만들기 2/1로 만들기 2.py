import sys; input = sys.stdin.readline
from collections import deque

visited = [0] * 1000001

def bfs(start):
  q = deque([(start, 0)])
  visited[start] = 0
  while q:
    v, sec = q.popleft()
    if v == 1: return sec
    if v % 3 == 0 and not visited[v//3]:
      visited[v//3] = v
      q.append((v//3, sec+1))
    if v % 2 == 0 and not visited[v//2]:
      visited[v//2] = v
      q.append((v//2, sec+1))
    if not visited[v-1]:
      visited[v-1] = v
      q.append((v-1, sec+1))

print(bfs(int(input())))
nv = 1
result = [nv]
while nv:
  nv = visited[nv]
  result.append(nv)
print(*result[:-1][::-1])