#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    int s_l = s.size();
    vector<int> answer;
    vector<int> position(24, 0); // -97
    for (int i = 0; i < s_l; i++){
        //cout << i << " " << s[i] << " " << (int)s[i] << " " << (int)s[i]-97 << endl;
        if (position[(int)s[i]-97] > 0) answer.push_back(i-position[(int)s[i]-97]+1);
        else answer.push_back(-1);
        position[(int)s[i]-97] = i+1;   
        //cout << position[(int)s[i]-97] << endl;
    }
    return answer;
}