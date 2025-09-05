import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

def dfs(start, color, graph, visited):
    visited[start] = color
    for i in graph[start]:
        if not visited[i]:
            res = dfs(i, -color, graph, visited)
            if res == False: return False
        else:
            if visited[i] == visited[start]: 
                return False
    return True

k = int(input())
for i in range(k):
    v, e = map(int, input().split())
    graph = [[] for j in range(v)]
    visited = [0 for j in range(v)]
    for _ in range(e):
        x, y = map(int, input().split())
        graph[x-1].append(y-1)
        graph[y-1].append(x-1)
    result = True
    for j in range(v):
        if not visited[j]:
            if not dfs(j, 1, graph, visited):
                result = False
                break
    print("YES" if result else "NO")
