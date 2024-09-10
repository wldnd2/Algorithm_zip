#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<int> food) {
    string answer = "0";
    for(int i = food.size()-1; i > 0; i--){
        string temp = "";
        for(int j = food[i]/2; j > 0; j--){
            answer += to_string(i);
            temp += to_string(i);    
        }
        answer = temp + answer;
        cout << answer << endl;
    }
    return answer.size() > 2 ? answer : "";
}