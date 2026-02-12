#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void backtrack(vector<long long>& data, int prev_num, long long acc){
    data.push_back(acc);

    for (int i = 0; i < prev_num; i++){
        backtrack(data, i, acc*10 + i);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<long long> result;

    for(int i = 0; i < 10; i++){
        backtrack(result, i, i);
    }

    if (n > result.size()) { 
        cout << -1 << "\n";
    } else {
        sort(result.begin(), result.end());
        cout << result[n-1] << "\n";
    }
}  

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}