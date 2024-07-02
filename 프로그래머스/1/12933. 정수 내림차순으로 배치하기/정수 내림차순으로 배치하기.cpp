#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    vector<int> num_list;
    while(n > 10){
        num_list.push_back(n%10);
        n /= 10;
    }
    num_list.push_back(n);
    sort(num_list.rbegin(), num_list.rend());
    long long answer = num_list[0];
    for(int i = 1; i < num_list.size(); i++){
        answer = answer * 10 + num_list[i];
    }
    return answer;
}