import sys
from collections import deque
input = sys.stdin.readline

n = int(input().strip())
start, end = map(int, input().strip().split())
m = int(input().strip())

graph = [[] for _ in range(n + 1)]

for _ in range(m):
    x, y = map(int, input().strip().split())
    graph[x].append(y)
    graph[y].append(x)

def bfs(start, end):
    visited = [False] * (n + 1)
    queue = deque([(start, 0)])  # (현재 노드, 현재 촌수)
    visited[start] = True
    while queue:
        current, degree = queue.popleft()
        if current == end:
            return degree
        for neighbor in graph[current]:
            if not visited[neighbor]:
                visited[neighbor] = True
                queue.append((neighbor, degree + 1))
    return -1

print(bfs(start, end))