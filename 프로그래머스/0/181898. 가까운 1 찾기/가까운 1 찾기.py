def solution(arr, idx):
    for idx, item in enumerate(arr[idx:], start=idx):
        if item == 1: return idx
    return -1