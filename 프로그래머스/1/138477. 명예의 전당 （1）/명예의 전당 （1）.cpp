#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> posting;
    unsigned int len = score.size();
    for(int i = 0; i < len; i++){
        posting.push_back(score[i]);
        sort(posting.begin(), posting.end(), [](int a, int b){return a > b;});
        if (posting.size() > k) {
            answer.push_back(posting[k-1]);
            posting.pop_back();
        }
        else{
            answer.push_back(posting[posting.size()-1]);
        }
    } 
    return answer;
}