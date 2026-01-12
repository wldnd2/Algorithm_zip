def solution(brown, yellow):
    for i in range(1, int(yellow//2)+2):
        if not (yellow % i):
            out = (yellow//i)*2 + (i*2) + 4
            y = i+2
            x = (yellow//i)+2
            if (out == brown and x >= y):
                return [x, y]