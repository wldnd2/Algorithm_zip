import sys
import heapq
input = sys.stdin.readline

n = int(input())
result = 1
schedule = []
for _ in range(n):
    schedule.append(list(map(int, input().split())))
schedule.sort()

pq = []
heapq.heappush(pq, schedule[0][1])
for i in range(1, n):
    if schedule[i][0] >= pq[0]:
        heapq.heappop(pq)
    heapq.heappush(pq, schedule[i][1])

print(len(pq))