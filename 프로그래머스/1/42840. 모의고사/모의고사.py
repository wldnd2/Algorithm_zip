def solution(answers):
    p1 = [1, 2, 3, 4, 5]
    p2 = [2, 1, 2, 3, 2, 4, 2, 5]
    p3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    pl1, pl2, pl3 = len(p1), len(p2), len(p3)
    check = [0,0,0]
    for i in range(len(answers)):
        if answers[i] ==  p1[i%pl1]: check[0] += 1
        if answers[i] ==  p2[i%pl2]: check[1] += 1
        if answers[i] ==  p3[i%pl3]: check[2] += 1
    max_value =  max(check)
    result = []
    for i in range(3):
        if max_value == check[i]: result.append(i+1)
    return result