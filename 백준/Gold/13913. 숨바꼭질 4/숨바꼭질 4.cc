#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>
#include <string>
#include <algorithm>

// const 상수 정의
const int MAX = 100001;

using namespace std;

struct Node {
    int v;
    int sec;
};

// 방문 여부를 저장하는 배열이자 경로를 저장하는 배열
vector<int> visited(MAX, -1);
vector<int> path;
deque<Node> q;

int bfs(int start, int target) {
    q.push_back({start, 0});
    visited[start] = start;
    while (!q.empty()) {
        Node current = q.front();
        q.pop_front();
        if (current.v == target) {
            while(current.v != start) {
                path.push_back(current.v);
                current.v = visited[current.v];
            }
            path.push_back(start);
            return current.sec;
        }
        for (int nv : {current.v - 1, current.v + 1, current.v * 2}) {
            if (0 <= nv && nv < MAX && visited[nv] < 0) {
                visited[nv] = current.v;
                q.push_back({nv, current.sec+1});
            }
        }
    }

    return -1;  // 경로를 찾지 못한 경우 -1 반환
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << bfs(n, k) << endl;
    for (int i = path.size()-1; i >= 0; i--) {
        cout << path[i] << " ";
    }
}
