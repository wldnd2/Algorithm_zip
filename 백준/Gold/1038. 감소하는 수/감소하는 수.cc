#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1000000

using namespace std;

long long n, idx = 0;
vector<long long> nums;

void backtrack(long long root, int target){
    nums.push_back(root);
    for (int i = 0; i < target; i++){
        backtrack(root*10+i, i);
    }
}

void solve(){
    cin >> n;
    for (int i = 0; i < 10; i++){
        backtrack(i, i);
    }
    sort(nums.begin(), nums.end());

    if (n >= nums.size()){
        cout << -1 << "\n";
    }
    else{
        cout << nums[n] << "\n";
    }
}

int main(void){
    solve();
    return 0;
}