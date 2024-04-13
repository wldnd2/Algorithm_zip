#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

int bfs(int start, int target){
    queue<int> q;
    q.push(start);
    vector<int> visited(100000, 0); // Fix: Change the type of visited vector 
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if(v == target) break;
        if(0 <= v-1 && !visited[v-1]){
            q.push(v-1);
            visited[v-1] = visited[v]+1;
        }
        if(v+1 <= 100000 && !visited[v+1]){
            q.push(v+1);
            visited[v+1] = visited[v]+1;
        }
        if(v*2 <= 100000 && !visited[v*2]){
            q.push(v*2);
            visited[v*2] = visited[v]+1;
        }
    }
    return visited[target];
}

int main(void) {
    int n, k;
    cin >> n >> k;
    cout << bfs(n, k) << endl;
    return 0;
}