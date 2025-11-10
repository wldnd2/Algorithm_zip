#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer(targets.size(), 0);
    vector<int> keyboard(26, 9999);
    for (int i = 0; i < keymap.size(); i++){
        for (int j = 0; j < keymap[i].size(); j++){
            if (keyboard[keymap[i][j]-'0'-17] > j+1) keyboard[keymap[i][j]-'0'-17] = j+1;
        }
    }
    for (int i = 0; i < targets.size(); i++){
        for (int j = 0; j < targets[i].size(); j++){
            if (keyboard[targets[i][j]-'0'-17] == 9999){
                answer[i] = -1;
                break;
            } 
            answer[i] += keyboard[targets[i][j]-'0'-17];
        }
    }
    return answer;
}