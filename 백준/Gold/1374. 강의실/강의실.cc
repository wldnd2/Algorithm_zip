#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <queue>
using namespace std;

int n;
priority_queue<int> pq;
vector<pair<int, int>> schedule;

void init(){
    cin >> n;
    for (int i = 0; i < n; i++){
        int id, s, e;
        cin >> id >> s >> e;
        schedule.push_back({s, e});
    }
    sort(schedule.begin(), schedule.end());
}

void solve(){
    pq.push(-schedule[0].second);
    for (int i = 1; i < n; i++){
        if (schedule[i].first >= -pq.top()) pq.pop();
        pq.push(-schedule[i].second);
    }
    cout << pq.size();
}

int main(void){
    init();
    solve();
}