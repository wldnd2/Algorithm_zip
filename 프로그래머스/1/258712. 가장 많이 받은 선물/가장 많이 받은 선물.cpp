#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    unordered_map<string, int> data;
    int id = 0;
    int n = friends.size();
    vector<int> answer(n, 0);
    vector<vector<int>> graph(n, vector<int>(n, 0));
    vector<int> idx;
    // 이름 별 인덱싱
    for (auto name: friends){
        data[name] = id++;
    }
    // 데이터 값 넣기
    for (auto line: gifts){
        stringstream ss(line);
        string giver; ss >> giver;
        string taker; ss >> taker;
        graph[data[giver]][data[taker]]++;
    }
    for (int i = 0; i < n; i++){
        int give = 0;
        int take = 0;
        for (int j = 0; j < n; j++){
            give += graph[i][j];
            take += graph[j][i];
        }
        idx.push_back(give-take);
    }
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            // give > take
            if (graph[i][j] > graph[j][i]) answer[i]++;
            else if (graph[i][j] < graph[j][i]) answer[j]++;
            else {
                if (idx[i] > idx[j]) answer[i]++;
                else if (idx[i] < idx[j]) answer[j]++;
            }
        }
    }
    return *max_element(answer.begin(), answer.end());
}