#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;

    int line;
    if (n % w) line = n / w + 1;
    else line = n / w;

    int startline = (num - 1) / w;
    int pos = (num - 1) % w;

    vector<vector<int>> data(line, vector<int>(w, 1));

    // 마지막 줄 빈칸 처리
    if (n % w != 0) {
        int remain = n % w;
        if ((line - 1) % 2 == 0) {
            // 마지막 줄이 정방향인 경우: 뒤쪽이 빈칸
            for (int j = remain; j < w; j++) {
                data[line - 1][j] = 0;
            }
        } else {
            // 마지막 줄이 역방향인 경우: 앞쪽이 빈칸
            for (int j = 0; j < w - remain; j++) {
                data[line - 1][j] = 0;
            }
        }
    }

    // 현재 num이 있는 세로줄의 실제 열 인덱스
    int target_col;
    if (startline % 2 == 0) target_col = pos;
    else target_col = w - 1 - pos;

    for (int i = startline; i < line; i++) {
        if (data[i][target_col] == 1) answer++;
    }

    return answer;
}