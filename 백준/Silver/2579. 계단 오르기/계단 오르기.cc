#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> stairs;
int dp[301] = {0, };

void init(){
    cin >> n;
    stairs.assign(n, 0);
    for(int i = 0; i < n; i++){
        cin >> stairs[i];
    }
}

int solve(){
    dp[0] = stairs[0];
    dp[1] = stairs[0] + stairs[1];
    dp[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);
    for(int i = 3; i < n; i++){
        dp[i] = max(dp[i-2] + stairs[i], dp[i-3] + stairs[i-1] + stairs[i]);
    }
    return dp[n-1];
}

int main(){
    init();
    cout << solve() << endl;
}