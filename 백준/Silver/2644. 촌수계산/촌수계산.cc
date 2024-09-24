#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int start, target;
vector<vector<int>> graph;

void init(){
  cin >> n;
  graph.resize(n+1);
  cin >> start >> target;
  int edge;
  cin >> edge;
  for(int i=0; i<edge; i++){
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
}

int bfs(){
  vector<bool> visited(n+1, false);
  queue<pair<int, int>> q;
  q.push({start, 0});
  visited[start] = true;
  while (!q.empty()){
    int cur = q.front().first;
    int dist = q.front().second;
    q.pop();
    if (cur == target) return dist;
    for(auto next : graph[cur]){
      if (!visited[next]){
        visited[next] = true;
        q.push({next, dist+1});
      }
    }
  }
  return -1;
}

int main(){
  init();
  cout << bfs() << '\n';
  return 0;
}