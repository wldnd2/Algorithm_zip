#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int INF = 1e9;
int n, m, start_p, end_p;

struct Edge{
    int dest;
    int weight;
};

struct Node{
    int id;
    int distance;
    bool operator>(const Node& other) const{
        return distance > other.distance;
    }
};

void solve(){
    cin >> n;
    cin >> m;
    vector<vector<Edge>> data(n);
    vector<int> result(n, INF);

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        data[u-1].push_back({v-1, w});
    }
    cin >> start_p >> end_p;

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({start_p-1, 0});
    result[start_p-1] = 0;
    while(!pq.empty()){
        Node temp = pq.top();
        pq.pop();
        /* ==== if문 2개가 시간 단축의 핵심!!! ==== */
        if(temp.id == end_p-1) break;
        if(result[temp.id] < temp.distance) continue;
        /* =================================== */
        for (const auto& e: data[temp.id]){
            if (result[e.dest] > (result[temp.id] + e.weight)){
                result[e.dest] = result[temp.id] + e.weight;
                pq.push({e.dest, result[e.dest]});
            }
        }
    }
    cout << result[end_p-1] << "\n";
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}