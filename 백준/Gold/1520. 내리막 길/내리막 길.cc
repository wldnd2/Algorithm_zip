//https://www.acmicpc.net/problem/1520 : 내리막길
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 501;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

void printDP(vector<vector<int>>& data, int x, int y) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cout << data[i][j] << " ";
        }
        cout << "\n";
    }
}

int dfs(vector<vector<int>>& dp, vector<vector<int>>& graph, pair<int, int> pre, pair<int, int> end){
    if (pre == end) return 1;
    if (dp[pre.first][pre.second] != -1) return dp[pre.first][pre.second];

    dp[pre.first][pre.second] = 0;
    for (int i = 0; i < 4; i++){
        int nx = pre.first + dx[i];
        int ny = pre.second + dy[i];
        if ((nx <= end.first && nx >= 0) && (ny <= end.second && ny >= 0) && (graph[nx][ny] < graph[pre.first][pre.second])){
            dp[pre.first][pre.second] += dfs(dp, graph, {nx, ny}, end);
        }
    }
    return dp[pre.first][pre.second];
}

int solve(){
    int n, m;
    vector<vector<int>> graph(MAX, vector<int>(MAX, -1));
    vector<vector<int>> result(MAX, vector<int>(MAX, -1));
    cin >> m >> n;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }
    cout << dfs(result, graph, {0, 0}, {m-1, n-1}) << "\n";
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}
