def solution(price, money, count):
    acc = price * (count * (count + 1)) // 2 
    return acc-money if acc > money else 0 