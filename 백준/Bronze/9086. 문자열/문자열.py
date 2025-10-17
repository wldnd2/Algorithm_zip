# 테스트 개수 입력받기
n = int(input())

# 테스트 개수만큼 반복
for i in range(n):
    word = input()
    print(word[0] + word[-1])