#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1e9;

struct Edge{
    int id;
    int dist;
};

struct Node{
    int id;
    int dist;
    bool operator>(const Node& other) const{
        return dist > other.dist;
    }
};

void solve(){
    int n, m;
    cin >> n;
    cin >> m;
    vector<vector<Edge>> graph(n);
    vector<int> res_dist(n, INF);
    vector<int> res_pre_node(n, -1);

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u-1].push_back({v-1, w});
    }
    int start_p, end_p;
    cin >> start_p >> end_p;

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({start_p-1, 0});
    while(!pq.empty()){
        int curr_id = pq.top().id;
        int curr_dist = pq.top().dist;
        pq.pop();
        // cout << curr_id << " " << curr_dist << " " << endl;
        if (curr_id == end_p-1) break;
        if (curr_dist > res_dist[curr_id]) continue;
        for (const auto& e: graph[curr_id]){
            int next_id = e.id;
            int next_dist = e.dist+curr_dist;
            if(res_dist[next_id] > next_dist){
                res_pre_node[next_id] = curr_id;
                res_dist[next_id] = next_dist;
                pq.push({next_id, next_dist});
            }
        }
    }

    int idx = end_p-1;
    int cnt = 1;
    vector<int> path;
    while(idx != start_p-1){
        cnt ++;
        path.push_back(idx+1);
        idx = res_pre_node[idx];
    }
    path.push_back(start_p);
    reverse(path.begin(), path.end());

    cout << res_dist[end_p-1] << "\n";
    cout << cnt << "\n";
    for(const auto& item: path){
        cout << item << " ";
    }
    cout << "\n";
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}