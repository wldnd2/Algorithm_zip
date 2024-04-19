#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, maxValue = -999;
vector<int> visited;
vector<vector<int>> adj;
vector<int> result;

void input(){
    cin >> n >> m;
    adj.resize(n+1);
    visited.resize(n+1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }
}

int bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start]++;
    while(! q.empty()){
        int cur = q.front(); q.pop();
        for(int i = 0; i < adj[cur].size(); i++){
            int next = adj[cur][i];
            if(!visited[next]){
                visited[next]++;
                visited[start]++;
                q.push(next);
            }
        }
    }
    return visited[start];
}

void printVector(vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
    cout.tie(0);
    input();
    for(int i = 1; i <= n; i++){
        memset(&visited[0], 0, sizeof(visited[0]) * visited.size());
        int temp = bfs(i);
        if (temp > maxValue){
            maxValue = temp;
            result.clear();
            result.push_back(i);
        } else if (temp == maxValue){
            result.push_back(i);
        }
    }
    printVector(result);
}
