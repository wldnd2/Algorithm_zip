#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int last_idx = *max_element(priorities.begin(), priorities.end());
    vector<int> idx(10, 0);
    queue<pair<int, int>> q;
    for (int i = 0; i < priorities.size(); i ++){
        idx[priorities[i]]++;
        q.push({priorities[i], i});
    }
    int turn = 0;
    while(!q.empty()){      
        pair<int, int> item = q.front(); q.pop();
        if (last_idx > item.first) {
            q.push(item);
        }
        else {
            idx[last_idx]--; turn ++;
            if (item.second == location && last_idx == item.first) return turn;
            while(!idx[last_idx]){
                last_idx --;
            }
        }
    }
    return 0;
}