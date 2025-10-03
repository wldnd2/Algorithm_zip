import sys; input = sys.stdin.readline
from collections import deque

directions = [(-1, 0), (0, -1), (1, 0), (0, 1)]

def bfs(start):
    cnt = {"o":0, "v":0} 
    q = deque([start])
    visited[start[0]][start[1]] = True
    escaped = False # 초기에는 탈출하지 않았다고 가정
    
    if matrix[start[0]][start[1]] == "v": cnt["v"] += 1
    elif matrix[start[0]][start[1]] == "o": cnt["o"] += 1
        
    while q:
        x, y = q.popleft()
        # 현재 칸이 경계인지 다시 확인 (시작점 처리 포함)
        if x == 0 or x == r-1 or y == 0 or y == c-1:
            escaped = True
        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            if 0 <= nx < r and 0 <= ny < c and not visited[nx][ny] and matrix[nx][ny] != "#":
                # 인접한 칸이 경계라면 플래그 설정
                if nx == 0 or nx == r-1 or ny == 0 or ny == c-1:
                    escaped = True
                # 카운트 로직 'k'를 'o'로 수정
                if matrix[nx][ny] == "v": cnt["v"] += 1
                elif matrix[nx][ny] == "o": cnt["o"] += 1
                
                q.append((nx, ny))
                visited[nx][ny] = True
    if escaped:
        # 경계에 닿았다면 모두 탈출하여 생존하지 못함
        cnt["o"] = 0
        cnt["v"] = 0
    else:
        # 울타리에 갇힌 경우: 양의 수가 늑대보다 많으면 양 승리
        if cnt["o"] > cnt["v"]: # 문제 조건: 양이 늑대보다 많으면(o > v) 양 승리
            cnt["v"] = 0
        else: # 그렇지 않으면 늑대 승리
            cnt["o"] = 0
    return cnt

r, c = map(int, input().split())
matrix = [list(input().rstrip()) for _ in range(r)]
visited = [[False]*c for _ in range(r)]

result = [0, 0] # [최종 양 (o), 최종 늑대 (v)]

for i in range(r):
    for j in range(c):
        if matrix[i][j] != "#" and not visited[i][j]:
            cnt = bfs((i, j)) 
            result[0] += cnt["o"]
            result[1] += cnt["v"]

print(*result)