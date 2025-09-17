#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <queue>
using namespace std;

int n, m;
vector<int> nums;
vector<bool> visited;
vector<int> result;

void init(){
    cin >> n >> m;
    nums.assign(n, 0);
    visited.assign(n, false);
    for(int i = 0; i< n; i++){
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
}

void solve(int depth){
    if (depth == m) {
        for (int item: result) cout << item << " ";
        cout << "\n";
        return;
    }
    int last_num = 0;
    for (int i = 0; i < n; i++){
        // ⭐️ 핵심 조건:
        // 1. 아직 사용하지 않은 숫자여야 하고 (!visited[i])
        // 2. 지금 고르려는 숫자가 바로 이전에 골랐던 숫자와 달라야 함 (중복 수열 방지)
        if (!visited[i] && nums[i] != last_num){
            visited[i] = true;          // 사용했다고 표시
            result.push_back(nums[i]);  // 결과에 추가
            last_num = nums[i];         // 마지막으로 고른 숫자를 현재 숫자로 기록
            
            solve(depth + 1);           // 다음 숫자를 고르러 재귀 호출
            
            // 백트래킹
            result.pop_back();          // 결과에서 제거
            visited[i] = false;         // 사용 안 한 것으로 원상복구
        }
    }
}

int main(void){
    init();
    solve(0);
}
