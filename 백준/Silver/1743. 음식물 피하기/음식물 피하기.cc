#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <queue>
using namespace std;

int n, m, cnt;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int result = -1;
vector<vector<bool>> board;
vector<vector<bool>> visited;

void init(){
    cin >> n >> m >> cnt;
    board.resize(n, vector<bool> (m, false));
    visited.resize(n, vector<bool> (m, false));
    int x,y;
    for(int i = 0;  i < cnt; i++){
        cin >> x >> y;
        board[x-1][y-1] = true;
    }
}

void solve(int x, int y){
    int cnt = 1;
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    while(!q.empty()){
        pair<int, int> pos = q.front();
        q.pop();
        for (int i = 0; i < 4; i++){
            int nx = pos.first + dx[i];
            int ny = pos.second + dy[i];
            if (0 > nx || nx >= n || 0 > ny || ny >= m) continue;
            if (!visited[nx][ny] && board[nx][ny]){
                q.push({nx, ny});
                visited[nx][ny] = true;
                cnt++;
            }
        }
    }
    result = result > cnt ? result: cnt;
}   

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if (board[i][j] && !visited[i][j]) solve(i, j);
        }
    }
    
    cout << result;
    return 0;
}