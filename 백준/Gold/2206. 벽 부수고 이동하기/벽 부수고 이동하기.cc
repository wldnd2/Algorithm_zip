#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <memory>
#include <cmath>
using namespace std;

#define MAX 1000

struct State{
    int x;
    int y;
    int chance;
};

int n, m;
int graph[MAX][MAX];
int visited[2][MAX][MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void init(){
    cin >> n >> m;
    string temp;
    for (int i = 0; i < n; i++){
        cin >> temp;
        for (int j = 0; j < m; j++){
            graph[i][j] = temp[j] - '0';
        }
    }
}

int solve(){
    queue<State> q;
    q.push({0,0,0}); // x, y, 0 or 1 broken State
    visited[0][0][0] = 1;
    while(!q.empty()){
        State curr =  q.front();
        if (curr.x == n-1 && curr.y == m-1) return visited[curr.chance][curr.x][curr.y];
        q.pop();
        for (int i = 0; i < 4; i++){
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];
            if (nx < 0 || n <= nx || ny < 0 || m <= ny) continue;
            if (!graph[nx][ny] && !visited[curr.chance][nx][ny]){
                q.push({nx, ny, curr.chance});
                visited[curr.chance][nx][ny] = visited[curr.chance][curr.x][curr.y] + 1;
            }
            // else if: 다음 칸 (nx, ny)가 벽(1)일 때
            else if (graph[nx][ny] && // 1. 다음 칸이 벽이고,
                     curr.chance == 0 &&   // 2. (조건1) 아직 벽을 부술 기회가 남아있고,
                     !visited[1][nx][ny])  // 3. (조건2) '벽을 부순 상태'로 그 칸에 방문한 적이 없다면
            {
                // '벽을 부순 상태'로 방문했다고 기록하고 큐에 넣습니다.
                visited[1][nx][ny] = visited[0][curr.x][curr.y] + 1;
                q.push({nx, ny, 1}); // chance는 이제 1 (기회 사용)
            }
        }
    }
    return -1;
}

int main(void){
    init();
    cout << solve();
}