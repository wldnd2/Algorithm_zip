def solution(my, pts):
    return "".join([my[idx][s[0]:s[1]+1] for idx, s in enumerate(pts)])