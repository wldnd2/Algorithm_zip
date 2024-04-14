import sys; input = sys.stdin.readline

n = int(input())
basic = "I"+"OI"*n
b_len = 1 + 2*n
s_len = int(input())
s = input().strip()
cnt = 0
for i in range(s_len - n - 1):
    if basic == s[i:i+b_len]:
        cnt += 1
print(cnt)