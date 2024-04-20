#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 20;
int n, cnt = 0;
vector<vector<int>> graph;

void input(){
    cin >> n;
    graph.resize(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }
}

void dfs(int x, int y, int dir){
    if (x == n - 1 && y == n - 1){
        cnt++;
        return;
    }
    if (dir == 0 || dir == 2){
        if (y + 1 < n && graph[x][y + 1] == 0){
            dfs(x, y + 1, 0);
        }
    }
    if (dir == 1 || dir == 2){
        if (x + 1 < n && graph[x + 1][y] == 0){
            dfs(x + 1, y, 1);
        }
    }
    if (x + 1 < n && y + 1 < n && graph[x + 1][y] == 0 && graph[x][y + 1] == 0 && graph[x + 1][y + 1] == 0){
        dfs(x + 1, y + 1, 2);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    dfs(0, 1, 0);
    cout << cnt << "\n";
}
