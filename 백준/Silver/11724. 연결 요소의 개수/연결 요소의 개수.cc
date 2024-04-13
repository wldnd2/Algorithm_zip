#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#define MAX 1001
using namespace std;

int n, m;
bool visited[MAX];
vector<vector<int>> adjacency_list(MAX);

void dfs(int start){
    visited[start] = true;
    for(int i = 0; i < adjacency_list[start].size(); i++){
        int next = adjacency_list[start][i];
        if(!visited[next]){
            dfs(next);
        }
    }
}


int main(void){
    int result = 0;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adjacency_list[a].push_back(b);
        adjacency_list[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i);
            result++;
        }
    }
    cout << result << '\n';
    return 0;
}
