//https://www.acmicpc.net/problem/14502 : 연구실
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <regex>
#include <cmath>
#define MAX 8
using namespace std;

int n,m;
int lab[MAX][MAX] = {0, };
bool blank_visited[MAX*MAX] = {false, };
vector<pair<int, int>> blank;   // 0
vector<pair<int, int>> wall;    // 1
vector<pair<int, int>> virus;   // 2
vector<vector<pair<int, int>>> combi_wall;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void init(){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> lab[i][j];
            if (lab[i][j] == 0) blank.push_back({i, j});
            else if (lab[i][j] == 1) wall.push_back({i, j});
            else if (lab[i][j] == 2) virus.push_back({i, j});
        }
    }
}

void backtrack(int pre_idx, int depth, vector<pair<int, int>> result){
    if (depth == 3) {
        combi_wall.push_back(result);
        return;
    }
    for (int i = pre_idx; i < blank.size(); i++){
        int idx = blank[i].first * MAX + blank[i].second;
        if (!blank_visited[idx]){
            blank_visited[idx] = true;
            result.push_back(blank[i]);
            backtrack(i, depth+1, result);
            blank_visited[idx] = false;
            result.pop_back();
        }
    }
}

void bfs(int x, int y, bool visited[MAX][MAX]){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        visited[cur.first][cur.second] = true;
        for (int i = 0; i < 4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (lab[nx][ny] == 1) continue;
            if (lab[nx][ny] == 0 && !visited[nx][ny]){
                lab[nx][ny] = 2;
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int safeSection(){
    int cnt = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (lab[i][j] == 0) cnt ++;
        }
    }
    return cnt;
}

void solution() {
    int result = -9999;
    for (const auto& combi : combi_wall) {
        int copy_lab[MAX][MAX] = {0, };
        copy(&lab[0][0], &lab[0][0]+(MAX*MAX), &copy_lab[0][0]);
        // 벽 세우기  
        for (const auto& wall_pos : combi) {
            lab[wall_pos.first][wall_pos.second] = 1;
        }
        // 바이러스 계산
        bool visit[MAX][MAX] = {false, };
        for (const auto& v: virus){
            if (!visit[v.first][v.second]) bfs(v.first, v.second, visit);
        }
        result = max(result, safeSection());
        copy(&copy_lab[0][0], &copy_lab[0][0]+(MAX*MAX), &lab[0][0]);
    }
    // 최대 값 출력
    cout << result << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    vector<pair<int, int>> temp;
    backtrack(0, 0, temp);
    solution();
    return 0;
}
