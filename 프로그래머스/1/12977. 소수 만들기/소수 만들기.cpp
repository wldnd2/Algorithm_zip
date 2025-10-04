#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int is_prime(int n){
    if (n < 2) return 0;
    for(int i = 2; i < (int)sqrt(n)+1; i++)
        if(n%i == 0) return 0;
    return 1;
}

int bk(int pre_idx, int cnt, int depth, int acc, vector<int> nums, bool visited[]){
    if (depth == 3){
        // cout << acc << " " << is_prime(acc) << endl;
        if (is_prime(acc)) cnt ++;
        return cnt;
    }
    for (int i = pre_idx; i < nums.size(); i++){
        if (!visited[i]){
            visited[i] = true;
            acc += nums[i];
            pre_idx = i;
            cnt = bk(pre_idx, cnt, depth+1, acc, nums, visited);
            acc -= nums[i];
            visited[i] = false;
        }
    }
    return cnt;
}

int solution(vector<int> nums) {
    int answer = -1;
    bool visited[51] = {false, };
    answer = bk(0, 0, 0, 0, nums, visited);
    return answer;
}