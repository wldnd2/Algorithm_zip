#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> stack;
    for(int i = 0;  i<ingredient.size(); i++){
        stack.push_back(ingredient[i]);
        int last_idx = stack.size();
        if (stack[last_idx-4] == 1 && stack[last_idx-3] == 2 && 
            stack[last_idx-2] == 3 && stack[last_idx-1] == 1){
            stack.pop_back();
            stack.pop_back();
            stack.pop_back();
            stack.pop_back();
            answer++;
        }
    }
    return answer;
}