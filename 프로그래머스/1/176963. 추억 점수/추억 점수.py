def solution(name, yearning, photo):
    answer = []
    scoreDict = {name:score for name, score in zip(name, yearning)}
    for page in photo:
        temp = 0
        for item in page:
            if item in scoreDict:
                temp += scoreDict[item]
        answer.append(temp)
    return answer