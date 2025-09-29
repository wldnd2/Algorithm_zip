// https://www.acmicpc.net/problem/15661
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#define MAX 20
using namespace std;

int n, result = 9999999;
int scores[MAX][MAX] = {0, };
int visited[MAX] = {0, };

void init(){
    cin >> n;
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> scores[i][j];
        }
    }
}

void solve(int pre){
    int start = 0;
    int link = 0;
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (!visited[i] && !visited[j]) start += scores[i][j];
            else if (visited[i] && visited[j]) link += scores[i][j];
        }
    }
    result = min(result, abs(start-link));
    for (int k = pre; k < n; k++){
        if (!visited[k]){
            visited[k] = 1;
            solve(k);
            visited[k] = 0;
        }
    }
    return;
}

int main(void){
    init();
    solve(0);
    cout << result;
    return 0;
}