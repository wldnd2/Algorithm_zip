#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i = 0; i < n; i++){
        int comb = arr1[i] | arr2[i];
        string s;
        for(int j = n-1; j >= 0; j--){
            int temp = (comb >> j) & 1;
            if(temp) s += "#";
            else s += " ";
        }
        answer.push_back(s);
    }
    
    return answer;
}