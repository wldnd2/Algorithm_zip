#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    int s = signs.size();
    for(int i = 0; i < s; i++){
        if (signs[i]) answer += absolutes[i];
        else answer -= absolutes[i];
    }
    return answer;
}