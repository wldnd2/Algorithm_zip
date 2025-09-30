def solution(dartResult):
    answer = []
    print(dartResult)
    dartResult = dartResult.replace("10", "O")
    print(dartResult)
    idx = -1
    for item in dartResult:
        if item.isdigit():
            answer.append(int(item))
            idx += 1
        elif item == "O":
            answer.append(10)
            idx += 1
        elif item in ["D", "T"]:
            if item == "D": answer[idx] = answer[idx]**2
            elif item == "T": answer[idx] = answer[idx]**3
        elif item in ["*", "#"]:
            if item == "*":
                if idx > 0: answer[idx-1] = answer[idx-1]*(2)
                answer[idx] = answer[idx]*(2)
            elif item == "#":
                answer[idx] = answer[idx]*(-1)
    return sum(answer)