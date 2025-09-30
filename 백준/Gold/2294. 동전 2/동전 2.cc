// https://www.acmicpc.net/problem/2294
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

int n, k;
vector<int> coins;
vector<int> dp;

void init(){
    cin >> n >> k;
    coins.assign(n, 0);
    dp.assign(k+1, 9999999);
    dp[0] = 0;
    for (int i = 0; i < n; i++){
        cin >> coins[i];
    }
    
    sort(coins.begin(),coins.begin()+n);
}

void solve(){
    for (int coin: coins){
        for (int j = coin; j < k+1; j++){
            dp[j] = min(dp[j], dp[j-coin]+1);
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    solve();
    int result = dp[k] == 9999999 ? -1:dp[k];
    cout << result;
    return 0;
}