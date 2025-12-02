#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> hash;
    for (string name: completion){
        if (!hash.count(name)) hash.insert({name, 1});
        else hash[name]++;
    }
    for (string key: participant){
        if(!hash.count(key) || !hash[key]) return key;
        else hash[key]--;
    }
    return answer;
}