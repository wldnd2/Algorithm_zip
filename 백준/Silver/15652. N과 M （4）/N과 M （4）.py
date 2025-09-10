import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

# N과 M 4
def backtracking(root, depth):
    if depth == m:
        print(' '.join(list(map(str, arr))))
        return
    for i in range(root, n):
        arr.append(nums[i])
        backtracking(i, depth+1)
        arr.pop()
    return 0

n, m = map(int, input().split())
arr = []
nums = [i for i in range(1, n+1)]
backtracking(0, 0)