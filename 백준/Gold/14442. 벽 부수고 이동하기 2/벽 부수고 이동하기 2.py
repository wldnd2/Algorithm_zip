import sys
from collections import deque
input = sys.stdin.readline

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs():
    q = deque([(0, 0, 0)])
    visited[0][0][0] = 1
    while(q):
        x, y, broken_cnt = q.popleft()
        
        if n-1 == x and m-1 == y: 
            return visited[broken_cnt][x][y]
        
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or nx >= n or ny < 0 or ny >= m: continue
            if not visited[broken_cnt][nx][ny] and graph[nx][ny] == '0':
                visited[broken_cnt][nx][ny] = visited[broken_cnt][x][y] + 1
                q.append([nx, ny, broken_cnt])
            elif graph[nx][ny] == '1' and broken_cnt < k and not visited[broken_cnt+1][nx][ny]:
                visited[broken_cnt+1][nx][ny] = visited[broken_cnt][x][y] + 1
                q.append([nx, ny, broken_cnt+1])
    return -1

n, m, k = map(int, input().split())
graph = [list(map(str, input().strip())) for _ in range(n)]
visited = [[[0]*(m) for _ in range(n)] for _ in range(k+1)]
print(bfs())