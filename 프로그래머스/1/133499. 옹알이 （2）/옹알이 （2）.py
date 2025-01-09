def solution(babbling):
    speak = ["aya", "ye", "woo", "ma"]
    for i in range(len(babbling)):
        for s in speak:
            if s*2 not in babbling[i]:
                babbling[i] = babbling[i].replace(s, " ")
    return len([i for i in babbling if i.isspace()])