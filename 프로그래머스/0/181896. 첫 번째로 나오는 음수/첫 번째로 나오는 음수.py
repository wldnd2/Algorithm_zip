def solution(num_list):
    for idx, i in enumerate(num_list):
        if i < 0: return idx
    else: return -1