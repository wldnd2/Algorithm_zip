import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def bk(path, result, depth, target):
    if depth == target:
        result.append(path[:])
        return result
    for i in nums:
        if depth + i <= target:
            path.append(i)
            result = bk(path, result, depth+i, target)
            path.pop()
    return result

n, k = map(int, input().split())
nums = [1,2,3]
visited = []
res = []
res = bk(visited, res, 0, n)
print(-1 if len(res) < k else "+".join(list(map(str, res[k-1]))))