import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def distance(pos1, pos2):
    return abs(pos1[0]-pos2[0])+abs(pos1[1]-pos2[1])

def bk(pre_idx, depth, target, visited):
    global result
    if depth == target:
        result.append(visited[:])
        return
    for k in range(pre_idx, len(chicken)):
        if not visited[k]:
            visited[k] = True
            bk(k, depth+1, target, visited)
            visited[k] = False
    return result

def solve(res):
    global chicken
    global house
    dist = 99999
    for i in range(len(res)):
        chicken_s = [99999] * len(house)
        for c in range(len(chicken)):
            if res[i][c]:
                for h in range(len(house)):
                    chicken_s[h] = min(chicken_s[h], distance(chicken[c], house[h]))
        dist = min(dist, sum(chicken_s))
    return dist

n, m = map(int, input().split())
# 0 blank / 1 house / 2 chicken
city = [list(map(int, input().split())) for _ in range(n)]
house = [(i, j) for i in range(n) for j in range(n) if city[i][j] == 1]
chicken = [(i, j) for i in range(n) for j in range(n) if city[i][j] == 2]

result = []
visited = [False] * len(chicken)
for i in range(1, m+1):
    bk(0, 0, i, visited)

print(solve(result))
