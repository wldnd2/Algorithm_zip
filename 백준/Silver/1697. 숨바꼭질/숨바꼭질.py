import sys
from collections import deque
input = sys.stdin.readline

n, k = map(int, input().split())
visited = [0] * (100001)
queue = deque([n])

while queue:
  v = queue.popleft()
  if v == k: break
  for dist in (v-1, v+1, v*2):
    if 0<= dist <= 100000 and not visited[dist]:
      queue.append(dist)
      visited[dist] = visited[v] + 1
print(visited[k])