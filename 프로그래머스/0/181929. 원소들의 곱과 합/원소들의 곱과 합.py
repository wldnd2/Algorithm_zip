def solution(num_list):
    multi = 1
    for i in num_list: multi*=i
    square = sum(num_list)**2
    return 1 if multi < square else 0