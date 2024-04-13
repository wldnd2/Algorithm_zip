import sys
sys.setrecursionlimit(150000)
input = sys.stdin.readline

def dfs(r, cc):
  visited[r] = cc
  for i in adjency[r]:
    if not visited[i]:
      dfs(i, cc)

n, m = map(int, input().split())
visited = [0] * (n+1)
adjency = [[] for _ in range(n+1)]

for _ in range(m):
  u, v = map(int, input().split())
  adjency[u].append(v)
  adjency[v].append(u)

cnt = 0
for i in range(1, n+1):
  if not visited[i]:
    cnt += 1
    dfs(i, cnt)

print(cnt)