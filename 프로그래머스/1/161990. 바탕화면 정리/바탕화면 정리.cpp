#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    int lux = 999;int luy = 999;
    int rdx = 0;int rdy = 0;
    for(int i  = 0; i < wallpaper.size(); i++) {
        for (int j = 0; j < wallpaper[i].size(); j++){
            if (wallpaper[i][j] == '#'){
                cout << i << " " << j << endl;
                lux = min(i, lux);
                luy = min(j, luy);
                rdx = max(i+1, rdx);
                rdy = max(j+1, rdy);
            }
        }
    }
    vector<int> answer = {lux, luy, rdx, rdy};
    return answer;
}