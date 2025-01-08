#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    vector<char> alpha;
    for (char c = 'a'; c <= 'z'; c++) {
        if (find(skip.begin(), skip.end(), c) == skip.end()) {
            alpha.push_back(c);
        }
    }

    for (char c : s) {
        auto it = find(alpha.begin(), alpha.end(), c);
        if (it != alpha.end()) {
            int pos = (it - alpha.begin() + index) % alpha.size();
            answer += alpha[pos];
        }
    }

    return answer;
}
