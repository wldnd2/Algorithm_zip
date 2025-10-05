import sys
input = sys.stdin.readline

cnt = 0
found_permutation = None

def backtrack(depth, N, target, current_perm, origin_chars, visited):
    global cnt, found_permutation

    if found_permutation is not None:
        return found_permutation
    
    if depth == N:
        cnt += 1
        if cnt == target:
            found_permutation = "".join(current_perm)
            return found_permutation
        return None

    for i in range(N):
        if not visited[i]:
            visited[i] = True
            current_perm.append(origin_chars[i])
            
            result = backtrack(depth + 1, N, target, current_perm, origin_chars, visited)
            
            if result is not None:
                return result
            current_perm.pop()
            visited[i] = False
    return None

while (True):
    try:
        input_data = input().strip().split()
        if not input_data: 
            break
        
        test_case, k_str = input_data[0], input_data[1]
        target_k = int(k_str)
        s = test_case
        N = len(s)
        
        max_permutations = 1
        for i in range(1, N + 1):
            max_permutations *= i

        cnt = 0
        found_permutation = None
        origin_chars = list(s)
        visited = [False] * N
        
        # 순열 생성 시작
        backtrack(0, N, target_k, [], origin_chars, visited)
        
        if found_permutation:
            result_perm = found_permutation
        elif target_k > max_permutations:
            result_perm = "No permutation"
        else:
            result_perm = "No permutation"
        print(f"{test_case} {k_str} = {result_perm}")
            
    except EOFError:
        break
    except Exception:
        break