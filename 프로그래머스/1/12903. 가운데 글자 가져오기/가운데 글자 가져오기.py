def solution(s):
    center = len(s)//2
    if len(s) % 2 == 0: 
        return s[center-1] + s[center]
    else : return s[center]