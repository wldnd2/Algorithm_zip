import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def backtrack(data, current_data, visited, depth, limit):
    if(depth == limit):
        print(*current_data)
        return
    for i in range(limit):
        if not visited[i]:
            visited[i] = True
            current_data.append(data[i])
            backtrack(data, current_data, visited, depth+1, limit)
            visited[i] = False
            current_data.pop()
    return

n = int(input())
data = [i for i in range(1, n+1)]
visited = [False]*n

backtrack(data, [], visited, 0, n)
