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
vector<vector<int>> graph(MAX, vector<int>(MAX, 1));

void input(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> graph[i][j];
        }
    }
}

void backtracking(int r, int c, int dir){
    if(graph[r][c]) return;
    if(r == n && c == n) { cnt++; return; }
    if(dir == 1) backtracking(r, c + 1, 1);
    if(dir == 2) backtracking(r + 1, c, 2);
    if(dir == 3) backtracking(r, c + 1, 1), backtracking(r + 1, c, 2);
    if(!graph[r][c+1] && !graph[r+1][c] && !graph[r+1][c+1])
        backtracking(r + 1, c + 1, 3);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    backtracking(1, 2, 1);
    cout << cnt << "\n";
}
