import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def dfs(start, color, graph, visited):
    visited[start] = color
    for item in graph[start]:
        if not visited[item]:
            if not dfs(item, -color, graph, visited): return False
        elif visited[start] == visited[item]: return False
    return True

for _ in range(int(input())):
    n, m = map(int, input().split())
    graph = [[] for _ in range(n+1)]
    visited = [0] * (n+1)
    for _ in range(m):
        u, v = map(int, input().split())
        graph[u].append(v)
        graph[v].append(u)
    result = True
    for i in range(1, n+1):
        if not visited[i]:
            if not dfs(i, 1, graph, visited):
                result = False
                break
    print("possible" if result else "impossible")
