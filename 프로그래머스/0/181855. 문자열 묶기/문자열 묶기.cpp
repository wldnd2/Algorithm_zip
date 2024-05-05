#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<string> strArr) {
    vector<int> cnt(100000, 0);
    for (int i = 0; i < strArr.size(); i++) cnt[strArr[i].size()]++;
    int answer = *max_element(cnt.begin(), cnt.end());
    return answer;
}