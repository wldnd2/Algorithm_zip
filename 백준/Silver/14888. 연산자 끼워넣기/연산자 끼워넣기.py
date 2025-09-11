# https://www.acmicpc.net/step/34

import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def calc_operator(root, num, op_idx):
    if op_idx == 0:
        return root + num
    if op_idx == 1:
        return root - num
    if op_idx == 2:
        return root * num
    if op_idx == 3:
        if root < 0: return -((-root) // num)
        else: return root // num

def backtracking(root, depth):
    if depth == n:
        result.append(root)
        return 
    for i in range(4):
        if operator[i]:
            # 상태 변화
            operator[i] -= 1
            prev_root = root
            # 백트래킹
            root = calc_operator(root, nums[depth], i)
            backtracking(root, depth+1)
            # 상태 복원
            operator[i] += 1
            root = prev_root

n = int(input())
nums = list(map(int, input().split()))
# + - * //
operator = list(map(int, input().split()))
result = []
backtracking(nums[0], 1)
print(max(result))
print(min(result))