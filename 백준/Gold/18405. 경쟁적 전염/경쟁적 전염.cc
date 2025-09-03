#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <queue>
#define MAX 200
using namespace std;

struct State{
    int sec;
    int virus_num;
    int vx;
    int vy;

    bool operator<(const State& other) const {
        if (sec != other.sec) return sec > other.sec;
        return virus_num > other.virus_num;
    }
};

int n, k, s, x, y;
int graph[MAX][MAX] = {0, };
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
priority_queue<State> state_q;

void init(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> graph[i][j];
            if (graph[i][j]) {
                state_q.push({0, graph[i][j], i, j}); 
            }
        }
    }
    cin >> s >> x >> y;
    x -= 1; y -= 1;
}

int solve(){
    while(!state_q.empty()){
        State prev = state_q.top();
        if (prev.sec == s) return graph[x][y];
        state_q.pop();
        for(int i = 0; i < 4; i++){
            int nx = prev.vx + dx[i];
            int ny = prev.vy + dy[i];
            if (nx < 0 || n <= nx || ny < 0 || n <= ny) continue;
            if (!graph[nx][ny]){
                graph[nx][ny] = prev.virus_num;
                state_q.push({prev.sec+1, graph[nx][ny], nx, ny});
            }
        }

        // cout << "\n";
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         cout << graph[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
    }
    return graph[x][y];
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    cout << solve();
    return 0;
}