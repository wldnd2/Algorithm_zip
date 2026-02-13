#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 1e9;

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
    // 입력
    int n, v, e;
    vector<int> company(2, 0);
    vector<int> house_list;
    vector<vector<Edge>> graph;
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    cin >> n >> v >> e;
    cin >> company[0] >> company[1];
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        house_list.push_back(temp);
    }

    graph.assign(v+1, vector<Edge>());

    for (int i = 0; i < e; i++){
        int a, b, l;
        cin >> a >> b >> l;
        graph[a].push_back({b, l});
        graph[b].push_back({a, l});
    }

    // 문제 해결
    long long acc = 0;
    for (const auto& start_point: company){
        vector<int> result(v+1, MAX);
        pq.push({start_point, 0});
        result[start_point] = 0;

        while(!pq.empty()){
            int curr_id = pq.top().id;
            int curr_dist = pq.top().dist;
            pq.pop();

            if (result[curr_id] < curr_dist) continue;

            for (const Edge& item: graph[curr_id]){
                int next_id = item.id;
                int next_dist = item.dist + curr_dist;
                if (result[next_id] > next_dist){
                    result[next_id] = next_dist;
                    pq.push({next_id, next_dist});
                }
            }
        }

        for(const auto& house: house_list){
            if (result[house] == MAX) acc += (-1);
            else acc += result[house];
        }
    }
    cout << acc << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}