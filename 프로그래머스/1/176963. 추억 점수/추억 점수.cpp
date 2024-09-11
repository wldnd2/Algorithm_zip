#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> scoreMap;
    for (int i = 0; i < name.size(); i++){
        scoreMap.insert({name[i], yearning[i]});
    }
    for (auto page: photo){
        int temp = 0;
        for (auto n: page){
            if (scoreMap.find(n) != scoreMap.end()){
                temp += scoreMap[n];
            }
        }
        answer.push_back(temp);
    }
    return answer;
}