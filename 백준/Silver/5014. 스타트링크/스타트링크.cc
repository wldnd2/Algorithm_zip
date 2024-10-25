#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int f, s, g, u, d;
vector<int> visited;

void init(){
    cin >> f >> s >> g >> u >> d;
    visited.assign(f + 1, 0);
}

int solve(){
    if (s == g) return 0; // 시작 층과 목표 층이 같다면 바로 0 반환
    if (u == 0 && d == 0) return -1; // 엘리베이터가 움직이지 않는 경우

    queue<int> q;
    q.push(s);
    visited[s] = 1;

    while (!q.empty()){
        int ns = q.front();
        q.pop();
        
        for (auto i : {u, -d}){
            int next = ns + i;
            if (next >= 1 && next <= f && !visited[next]){
                q.push(next);
                visited[next] = visited[ns] + 1;
                
                if (next == g) return visited[next] - 1; // 목표 층에 도달 시 버튼 횟수 반환
            }
        }
    }
    return -1; // 엘리베이터로 도달 불가능한 경우
}

int main(){
    init();
    int result = solve();
    if (result == -1) cout << "use the stairs" << endl;
    else cout << result << endl;
    return 0;
}
