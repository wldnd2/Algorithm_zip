import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def backtrack(depth, pre_idx, result, visited, data):
    if depth == 6:
        print(*result)
        return 
    for i in range(pre_idx, len(data)):
        if not visited[i]:
            visited[i] = True
            result.append(data[i])
            backtrack(depth+1, i, result, visited, data)
            result.pop()
            visited[i] = False
    return

while True:
    input_num = input().strip()
    if input_num == "0": break
    input_num = input_num.split()
    k = int(input_num[0])
    s = list(map(int, input_num[1:]))
    backtrack(0, 0, [], [False]*k, s)
    print()