def solution(n):
    result = "".join(sorted(list(str(n)), reverse=True))
    return int(result)