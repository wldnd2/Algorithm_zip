def solution(food):
    temp = "".join([str(idx)*(cnt//2) for idx, cnt in enumerate(food[1:], 1)])
    answer = temp + "0" + temp[::-1]
    return answer if len(answer) > 2 else ""