import sys
input = sys.stdin.readline

def printResult(value, location):
  print(value + location)
  exit(0)

def divide(n, r, c, value):
  n //= 2
  if r < n and c < n:
    if n == 1: printResult(value, 0)
    divide(n, r, c, value)
  elif r < n and c >= n:
    if n == 1: printResult(value, 1)
    divide(n, r, c-n, value + (n**2 * 1))
  elif r >= n and c < n:
    if n == 1: printResult(value, 2)
    divide(n, r-n, c, value + (n**2 * 2))
  else:
    if n == 1: printResult(value, 3)
    divide(n, r-n, c-n, value + (n**2 * 3))

n, r, c = map(int,input().split())
divide(2**n,r,c,0)