#include <string>
#include <vector>
#include <regex>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    // 오늘 시간 계산
    smatch today_match;
    regex today_pattern("(\\d{4}).(\\d{2}).(\\d{2})");
    int today_y, today_m, today_d;
    if(regex_match(today, today_match, today_pattern)){
        today_y = stoi(today_match[1]);
        today_m = stoi(today_match[2]);
        today_d = stoi(today_match[3]);
    }
    
    // hash map 생성
    smatch match;
    unordered_map<string, pair<int, int>> table;
    regex termsPattern("(\[A-Z])\\s+(\\d{1,3})");
    for(const auto &term: terms){
        if(regex_search(term, match, termsPattern)){
            table.insert({match[1].str(), {stoi(match[2])/12, stoi(match[2])%12}});
        }
    }
    
    // 여부 확인
    regex pattern("(\\d{4}).(\\d{2}).(\\d{2})\\s+(\[A-Z])");
    for(int i = 0; i < privacies.size(); i++){
        if(regex_search(privacies[i], match, pattern)){
            int year = stoi(match[1]);
            int month = stoi(match[2]);
            int day = stoi(match[3]);
            string t = match[4].str();
            year += table[t].first;
            month += table[t].second;
            if (month > 12){
                year ++;
                month -= 12;
            }
            // 오늘과 비교
            // cout << today_y << " " << today_m << " " << today_d << "\n";
            // cout << year << " " << month << " " << day << "\n";
            if (today_y > year) {
                answer.push_back(i+1);
                continue;
            }
            if (today_y == year && today_m > month) {
                answer.push_back(i+1);
                continue;
            }
            if (today_y == year && today_m == month && today_d >= day) {
                answer.push_back(i+1);
                continue;
            }
        }
    }
    return answer;
}