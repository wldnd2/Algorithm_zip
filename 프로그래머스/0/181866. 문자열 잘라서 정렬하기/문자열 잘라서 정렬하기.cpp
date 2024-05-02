#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> solution(string myString) {
    vector<string> answer;
    string temp = "";
    for(char c: myString){
        if (c == 'x'){
            if (temp.size() > 0) answer.push_back(temp);
            temp = "";
        }
        else temp += c;
    }
    if (temp.size() > 0) answer.push_back(temp);
    sort(answer.begin(), answer.end());
    return answer;
}
