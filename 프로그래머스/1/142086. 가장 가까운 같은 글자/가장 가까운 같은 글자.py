def solution(s):
    answer = []
    position = [0]*26
    for idx, c in enumerate(s):
        if position[ord(c)-97] : answer.append(idx-position[ord(c)-97]+1)
        else: answer.append(-1)
        position[ord(c)-97] = idx+1
    return answer