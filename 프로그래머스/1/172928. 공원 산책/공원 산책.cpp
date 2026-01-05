#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <sstream>

using namespace std;

void dfs(int x, int y, int cmd_idx, vector<bool> visited, vector<string> park, vector<string> routes){

}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer (2, 0); // [x,y]
    for(int i = 0; i < park.size(); i++){
        for(int j = 0; j < park[i].size(); j++){
            if (park[i][j] == 'S'){
                answer[0] = i;
                answer[1] = j;
            }
        }
    }
    
    int h = park.size();
    int w = park[0].size();
    for(int i = 0; i < routes.size(); i++){
        string dir, moves;
        stringstream ss(routes[i]);
        ss >> dir >> moves;
        int n = stoi(moves);
        int x = answer[0], y = answer[1];
        cout << x << " " << y << endl;
        cout << dir << " " << moves << endl;
        for (int j = 0; j < n; j++){
            // 동서남북 이동
            if (dir == "N") x -= 1;
            else if (dir == "S") x += 1;
            else if (dir == "W") y -= 1;
            else y += 1;
            // 예외 상황 체크 및 복구
            if ((x < 0 || x >= h || y < 0 || y >= w) || (park[x][y] == 'X')) {
                x = answer[0];
                y = answer[1];
                break;
            };
        }
        answer[0] = x;
        answer[1] = y;
    }
    return answer;
}