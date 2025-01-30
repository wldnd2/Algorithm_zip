#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
vector<vector<int>> dp;

void init(){
    cin >> n;
    for(int i = 0; i < n; i++){
        vector<int> temp(n, 0);
        for(int j = 0; j < i+1; j++){
            cin >> temp[j]; 
        }
        dp.push_back(temp);
    }
}

int solve(){
    for(int i = n-2; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            dp[i][j] += max(dp[i+1][j], dp[i+1][j+1]);
        }
    }
    return dp[0][0];
}

int main(){
    init();
    cout << solve() << endl;
}