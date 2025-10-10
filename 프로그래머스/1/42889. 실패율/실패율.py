def solution(N, stages):
    answer = [[i, 0] for i in range(1, N+1)]
    cnt = [0] * (N+2)
    players = len(stages)
    for i in stages: 
        cnt[i] += 1
    print(cnt)
    for i in range(1, N+1):
        temp = cnt[i]
        if players == 0:
            answer[i-1][1] = 0
        else:
            answer[i-1][1] = cnt[i]/players
        players -= temp
    return [item[0] for item in sorted(answer, key = lambda x: x[1], reverse=True)]