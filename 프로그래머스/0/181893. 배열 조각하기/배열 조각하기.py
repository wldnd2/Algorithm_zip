def solution(arr, query):
    for idx, item in enumerate(query):
        if idx % 2: arr = arr[item:]
        else: arr = arr[:item + 1]
    return arr