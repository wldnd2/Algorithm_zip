#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

// 최대 이동 길이를 저장해야함.
int dfs(int x, int y, int n, const vector<vector<int>>& graph, vector<vector<int>>& dp) {
    if (dp[x][y] > -1) return dp[x][y];
    dp[x][y] = 1;
    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if ((nx >= 0 && nx < n) && (ny >= 0 && ny < n) && (graph[nx][ny] > graph[x][y])){
            dp[x][y] = max(dp[x][y], dfs(nx, ny, n, graph, dp)+1);
        }
    }
    return dp[x][y];
}

void solve(){
    int n;
    vector<vector<int>> graph;
    vector<vector<int>> dp;
    
    cin >> n;
    graph.assign(n, vector<int>(n));
    dp.assign(n, vector<int>(n, -1));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }

    int result = -999;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            result = max(result, dfs(i, j, n, graph, dp));
        }
    }
    cout << result << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}