#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 10000;

struct Lecture {
    int id;
    int start_t;
    int end_t;
    int room_num;

    // 1. 시작 시간 기준 정렬을 위한 연산자 (std::sort용)
    bool operator<(const Lecture& other) const {
        if (this->start_t == other.start_t) {
            return this->end_t < other.end_t;
        }
        return this->start_t < other.start_t;
    }
};

// 2. 종료 시간 기준 비교를 위한 구조체 (std::priority_queue용)
struct CompareEnd {
    bool operator()(const Lecture& a, const Lecture& b) {
        // 우선순위 큐는 기본이 Max-Heap이므로, 
        // 가장 작은 end_t가 top에 오게 하려면 'greater(>)' 로직을 씁니다.
        return a.end_t > b.end_t;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<Lecture> lectures(n);
    
    for (int i = 0; i < n; i++) {
    cin >> lectures[i].id >> lectures[i].start_t >> lectures[i].end_t;
    }

    // [Step 1] 시작 시간 기준 오름차순 정렬
    sort(lectures.begin(), lectures.end());

    // [Step 2] 우선순위 큐 선언 (종료 시간이 가장 빠른 강의실이 위로 옴)
    priority_queue<Lecture, vector<Lecture>, CompareEnd> pq;
    vector<int> room(n+1, -1);
    int curr_room = 0;

    for(int i = 0; i < n; i++){
        if(pq.size() > 0 && pq.top().end_t <= lectures[i].start_t){
            room[lectures[i].id] = pq.top().room_num;
            lectures[i].room_num = pq.top().room_num;
            pq.pop();
            pq.push(lectures[i]);
        }
        else{
            curr_room++;
            room[lectures[i].id] = curr_room;
            lectures[i].room_num = curr_room;
            pq.push(lectures[i]);
        }
    }

    cout << curr_room << "\n";
    for(int i = 1; i <= n; i++){
        cout << room[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}