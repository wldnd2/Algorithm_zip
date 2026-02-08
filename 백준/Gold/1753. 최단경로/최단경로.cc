#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

void solve() {
    int v, e, k;
    cin >> v >> e >> k;

    vector<pair<int, int>> adj[20001]; 
    vector<int> result_dist(v + 1, INF);

    for (int i = 0; i < e; i++) {
        int u, v_dest, w;
        cin >> u >> v_dest >> w;
        adj[u].push_back({v_dest, w});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    result_dist[k] = 0;
    pq.push({0, k}); // {거리, 현재 노드}

    while (!pq.empty()) {
        int d = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if (result_dist[curr] < d) continue; // 이미 처리된 짧은 경로는 무시

        for (auto& edge : adj[curr]) {
            int next = edge.first;
            int next_d = d + edge.second;

            if (next_d < result_dist[next]) {
                result_dist[next] = next_d;
                pq.push({next_d, next});
            }
        }
    }

    for (int i = 1; i <= v; i++) {
        if (result_dist[i] == INF) cout << "INF\n";
        else cout << result_dist[i] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}