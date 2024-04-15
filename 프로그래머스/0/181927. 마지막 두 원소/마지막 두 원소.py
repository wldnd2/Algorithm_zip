def solution(num):
    return num+[num[-1]-num[-2] if num[-1] > num[-2] else num[-1]*2]