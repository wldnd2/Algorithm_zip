#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> check(201, 0);
    int num_len = numbers.size();
    vector<int> answer;
    for(int i = 0; i < num_len; i++){
        for(int j = i+1; j < num_len; j++){
            int temp =  numbers[i] + numbers[j];
            if(!check[temp]){
                answer.push_back(temp);
                check[temp]++;
            } 
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}