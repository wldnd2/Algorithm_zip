import sys; input = sys.stdin.readline
from collections import deque

def bk(depth, target, anagram, text, visited):
    if depth == target:
        print("".join(anagram))
        return 
    last_char = ""
    for i in range(target):
        if not visited[i] and last_char != text[i]:
            visited[i] = True
            anagram.append(text[i])
            last_char = text[i]
            bk(depth+1, target, anagram, text, visited)
            anagram.pop()
            visited[i] = False

for _ in range(int(input())):
    data = sorted(input().strip())
    size = len(data)
    visited = [False]*size
    bk(0, size, [], data, visited)