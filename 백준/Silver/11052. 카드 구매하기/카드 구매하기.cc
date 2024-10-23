#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> arr;

void init(){
    cin >> n;
    arr.assign(n, 0);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
}

int solve(){
    vector<int> dp (n+1, 0);
    for (int i = 1; i < n+1; i++){
        int m = -99999;
        for (int j = 1; j < i+1; j++){
            m = max(m, (arr[j-1]+dp[i-j]));
        }
        dp[i] = m;
    }
    return dp[n];
}

int main(){
    init();
    cout << solve() << endl;
}