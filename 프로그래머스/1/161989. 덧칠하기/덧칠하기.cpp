#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    vector<bool> wall(n, true);
    for (auto sec: section){
        wall[sec-1] = false;
    }
    int start_point = 0;
    int end_point = n-1;
    while(start_point <= end_point){
        if (!wall[start_point]){
            answer++;
            for (int i = 0; i < m; i++){
                wall[start_point] = true; 
                start_point++;
                if (start_point > end_point) break;
            }
        }
        else {
            start_point++;
        }
    }
    return answer;
}