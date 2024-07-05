#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer(1, arr[0]);
    for(int i: arr){
        if(i != answer[answer.size()-1]) answer.push_back(i);
    }

    return answer;
}