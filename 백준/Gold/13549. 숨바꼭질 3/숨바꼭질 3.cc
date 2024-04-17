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

bool visited[MAX] = {false};
deque<Node> q;

int bfs(int start, int target) {
    q.push_back({start, 0});
    visited[start] = true;
    while (!q.empty()) {
        // 데이터형을 정확히 명시해주어야 함
        Node current = q.front();
        q.pop_front();
        if (current.v == target) {
            return current.sec;
        }
        for (int nv : {current.v - 1, current.v + 1, current.v * 2}) {
            if (0 <= nv && nv < MAX && !visited[nv]) {
                visited[nv] = true;
                // +1과 -1과 *2를 모두 똑같이 BFS로 탐색하게 된다면, +1로 찾은 칸은 *2로 갈 수 
                // 있었음에도 불구하고, 이미 방문 처리가 되어 있기에 *2로 찾을 수 없게 된다. 이를 
                // 해결하기 위해 *2를 더 먼저 처리하여야 한다. 
                if (nv == current.v*2) q.push_front({nv, current.sec});
                else q.push_back({nv, current.sec+1});
            }
        }
    }

    return -1;  // 경로를 찾지 못한 경우 -1 반환
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << bfs(n, k) << endl;
}
