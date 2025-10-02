import math

def solution(numbers, hand):
    answer = ''
    keypad = [[1,2,3],[4,5,6],[7,8,9],[999,0,999]]
    r_hand = [3, 0]
    l_hand = [3, 2]
    for num in numbers:
        if num in [1,4,7]:
            answer += "L"
            l_hand = [num//3, 0]
        elif num in [3,6,9]:
            answer += "R"
            r_hand = [num//3-1, 2]
        else:
            pos = [num//3, 1] if num else [3, 1]
            # print()
            # print(num, ":", pos, l_hand, r_hand)
            l_dist = math.ceil(abs((pos[0]-l_hand[0])**2+(pos[1]-l_hand[1])**2)**(1/2))
            r_dist = math.ceil(abs((pos[0]-r_hand[0])**2+(pos[1]-r_hand[1])**2)**(1/2))
            # print(l_dist, r_dist)
            if l_dist < r_dist:
                answer += "L"
                l_hand = pos[:]
            elif l_dist > r_dist:
                answer += "R"
                r_hand = pos[:]
            else:
                if hand == "right": 
                    answer += "R"
                    r_hand = pos[:]
                else:
                    answer += "L"
                    l_hand = pos[:]
    return answer