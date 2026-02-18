import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n = int(input())
print("SK" if not n % 2 else "CY")