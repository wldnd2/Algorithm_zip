import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    result = 1
    applicant = []
    for _ in range(n):
        a, b = map(int, input().split())
        applicant.append([a,b])
    applicant.sort(key=lambda x: (x[0], x[1]))
    score = applicant[0][1]
    for i in range(1, n):
        if score > applicant[i][1]: 
            score = applicant[i][1]
            result += 1
    print(result)