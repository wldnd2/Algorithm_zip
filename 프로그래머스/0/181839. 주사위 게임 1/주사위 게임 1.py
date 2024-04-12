import math

def solution(a, b):
    if ((a+b)%2): return 2*(a+b)
    elif(a%2): return a**2+b**2
    return abs(a-b)