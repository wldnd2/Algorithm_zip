#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    // 신고자 idx 저장
    map<string, int> report_idx;
    for (int i = 0; i < id_list.size(); i++) {
        report_idx[id_list[i]] = i;
    }
    // 신고자, 신고된 사용자 분리
    map<string, set<string>> report_list;
    for (string event: report){
        stringstream ss(event);
        string reporter, reported;
        ss >> reporter >> reported;
        // 반대로 하면 갯수도 카운트 가능함
        report_list[reported].insert(reporter);
    }
    for(auto iter : report_list){
        string reported = iter.first;
        set<string> reporters = iter.second; 
        if (reporters.size() >= k){
            for(string reporter: reporters){
                answer[report_idx[reporter]] ++;
            } 
        }
    }
    return answer;
}