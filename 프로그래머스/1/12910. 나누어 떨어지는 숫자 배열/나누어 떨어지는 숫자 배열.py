def solution(arr, divisor):
    answer = [item for item in arr if not item % divisor]
    return sorted(answer) if len(answer) else [-1]