def solution(num_list):
    odd, even = "", ""
    for item in num_list:
        if item%2: odd+=str(item)
        else: even+=str(item) 
    return eval(f"{odd}+{even}")