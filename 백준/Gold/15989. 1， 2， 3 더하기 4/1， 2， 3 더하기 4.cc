#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 10000;

void solve(){
    int n;
    vector<int> data;
    vector<int> dp(MAX, 0);
    cin >> n;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        data.push_back(temp);
    }
    int max_ele = *max_element(data.begin(), data.end());

    int step = 1;
    dp[1] = 1;

    for(int i = 2; i < max_ele+1; i++){
        if (i % 6 == 0){
            step++;
            dp[i] = dp[i-1] + step;
        }
        else if (i % 6 == 1){
            dp[i] = dp[i-1] + step - 1;
        }
        else dp[i] = dp[i-1] + step;
        // cout << i << " " << step  << ": " << dp[i] << "\n";
    }

    for (const auto& item: data){
        cout << dp[item] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}