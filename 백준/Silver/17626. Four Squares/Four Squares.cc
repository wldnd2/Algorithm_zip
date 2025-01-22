#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 50000
using namespace std;

int n;
// 2 - 1 1
// 3 - 1 1 1 
// 4 - 4
// 5 - 4 1
// 6 - 4 1 1
int dp[MAX+1] = {0, 1, }; 

void init(){
    cin >> n;
}

int solve(){
    for(int i = 2; i <= n; i++){
        int m = MAX;
        for(int j = 1; j*j <= i; j++){
            int idx = i-j*j;
            m = min(m, dp[idx]);
        }
        dp[i] = m+1;
    }
    return dp[n];
}

int main(){
    init();
    cout << solve() << endl;
}