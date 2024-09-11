def solution(name, yearning, photo):
    answer = []
    nameDict = {name:idx for idx, name in enumerate(name)}
    for page in photo:
        temp = 0
        for item in page:
            try:
                temp += yearning[nameDict[item]]
            except:
                continue
        answer.append(temp)
    return answer