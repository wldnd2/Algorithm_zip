#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 100;
const vector<pair<int,int>> dir = {{1,0}, {0,1}, {-1,0}, {0, -1}};

int n, last_num = -999;
int graph[MAX][MAX];
bool visited[MAX][MAX];

void print2DArray(bool arr[][MAX]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void init(){
    cin >> n;
    memset(graph, 0, sizeof(graph));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> graph[i][j];
            last_num = max(last_num, graph[i][j]);
        }
    }
}

int bfs(int x, int y, int level){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    while(!q.empty()){
        int vx = q.front().first;
        int vy = q.front().second;
        q.pop();
        for(pair<int,int> p : dir){
            int nx = vx + p.first;
            int ny = vy + p.second;
            if(0<=nx && nx<n && 0<=ny && ny<n && graph[nx][ny] > level && !visited[nx][ny]){
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // start
    init();
    // cout << endl;
    int result = 1;
    for (int level = 1; level <= last_num; level++){
        memset(visited, false, sizeof(visited));
        int temp = 0;
        // cout << "level: " << level << endl;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (!visited[i][j] && graph[i][j] > level){
                    temp += bfs(i, j, level);
                }
            }
        }
        result = max(result, temp);
        // print2DArray(visited);
        // cout << "temp: " << temp << endl << endl;
    }
    cout << result << "\n";
}
