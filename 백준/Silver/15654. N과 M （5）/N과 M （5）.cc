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
    for (int i = 0; i < n; i++){
        if (!visited[i]){
            result.push_back(nums[i]);
            visited[i] = true;
            solve(depth+1);
            result.pop_back();
            visited[i] = false;
        }
    }
}

int main(void){
    init();
    solve(0);
}