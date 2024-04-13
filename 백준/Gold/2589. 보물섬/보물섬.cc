#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#define MAX 50
using namespace std;

struct node{
	int x,y,cnt;
};

int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
char graph[MAX][MAX];
bool visited[MAX][MAX];
int n, k;

void input(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(int j = 0; j < k; j++){
            graph[i][j] = s[j];
        }
    }
}

int bfs(int x, int y){
    queue<node> q;
    q.push({x, y, 0});     // q.push(make_pair(x, y)); 이렇게 써도 됨
    visited[x][y] = true;
    int max_value = -1;
    while(!q.empty()){
        node v = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int nx = dir[i][0] + v.x;
            int ny = dir[i][1] + v.y;
            bool check_x = 0<=nx && nx < n;
            bool check_y = 0<=ny && ny < k;
            bool check_c = graph[nx][ny] == 'L'; // Fix: Change "L" to 'L'
            if (check_x && check_y && !visited[nx][ny] && check_c) {
                q.push({nx, ny, v.cnt+1});
                visited[nx][ny] = true;
                max_value = max(max_value, v.cnt+1);
            }
        }
    }
    return max_value;
}

int main(void){
    int result = -1;
    input();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            if(graph[i][j] == 'L'){
                memset(visited, 0, sizeof(visited));
                result = max(result, bfs(i, j));
            }
        }
    }
    cout << result;
    return 0;
}
