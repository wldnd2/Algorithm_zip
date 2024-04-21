import sys; input = sys.stdin.readline

n = int(input())
for _ in range(n):
    category = {}
    for _ in range(int(input())):
        name, kind = input().strip().split()
        if kind in category:
            category[kind] += 1
        else:
            category[kind] = 1
    numberOfClothes = 1
    for key in category:
        numberOfClothes *= category[key] + 1
    print(numberOfClothes - 1)