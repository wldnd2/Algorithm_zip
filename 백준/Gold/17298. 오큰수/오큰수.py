import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n = int(input())
nums = list(map(int, input().split()))
temp = [nums.pop()]
temp_idx = 0

answer = [-1]*n

for i in range(n-2, -1, -1):
    item = nums.pop()
    while(temp_idx >= 0):
        if temp[temp_idx] > item:
            answer[i] = temp[temp_idx]
            break
        else: 
            temp.pop()
            temp_idx -= 1
            if temp_idx == -1: 
                break
    temp.append(item)
    temp_idx +=1

print(*answer)