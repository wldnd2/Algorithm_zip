import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n, m = map(int, input().split())
data = sorted(list(map(int, input().split())))
visited = [False]*10001 
result = []

def bk(depth, pre, curr):
    if depth == m:
        print(*curr)
        return 
    root = 9999999
    for i in range(pre, n):
        if root != data[i]:
            root = data[i]
            curr.append(data[i])
            bk(depth+1, i, curr)
            curr.pop()

bk(0, 0, [])