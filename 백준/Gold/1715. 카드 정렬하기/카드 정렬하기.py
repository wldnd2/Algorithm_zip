import sys
import heapq
input = sys.stdin.readline

card = [int(input()) for _ in range(int(input()))]
heapq.heapify(card)
acc = 0
while True:
    num1 = heapq.heappop(card)
    if not card:
        print(acc)
        break
    num2 = heapq.heappop(card)
    acc += num1 + num2
    heapq.heappush(card, num1+num2)