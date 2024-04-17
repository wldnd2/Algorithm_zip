import sys; input = sys.stdin.readline
from collections import deque

n, k = map(int, input().split())
# deque에 튜플 넣을 시 리스트에 넣어야 함
# 그래야 튜플로 인식해서 upacking 가능
q = deque([(n, 0)])
visited = [0] * 100001
visited[n] = 1

while q:
    v, sec = q.popleft()
    if v == k: 
        print(sec)
        break
    for dir in (v-1, v+1, v*2):
        if 0 <= dir < 100001 and not visited[dir]:
            visited[dir] = 1
            if dir == v*2: q.appendleft((dir, sec))
            else: q.append((dir, sec + 1))