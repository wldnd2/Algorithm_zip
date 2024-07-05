def solution(arr):
    result = [arr[0]]
    for i in arr[1:]:
        if i != result[-1]:
            result.append(i)
    return result