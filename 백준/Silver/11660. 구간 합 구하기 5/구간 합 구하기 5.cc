// https://www.acmicpc.net/problem/11660
// 구간 합 구하기 5

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 1025
using namespace std;

struct Points{
    int x1;
    int y1;
    int x2;
    int y2;
};

int n, m;
int graph[MAX][MAX] = {0, };
int dp[MAX][MAX] ={0, };
vector<Points> p;

void init(){
    // 기존 입력
    cin >> n >> m;
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < n+1; j++){
            cin >> graph[i][j];
        }
    }
    int px1, py1, px2, py2;
    for (int i = 0; i < m; i++){
        cin >> px1 >> py1 >> px2 >> py2;
        p.push_back({px1, py1, px2, py2});
    }

    // DP 테이블 생성
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < n+1; j++){
            dp[i][j] = graph[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }
}

int solve(Points grid){
    int result = dp[grid.x2][grid.y2] + dp[grid.x1-1][grid.y1-1] - dp[grid.x1-1][grid.y2] - dp[grid.x2][grid.y1-1];
    return result;
}

int main(void){
    init();
    for (int i = 0; i < m; i++){
        cout << solve(p[i]) << "\n";
    }
    return 0;
}