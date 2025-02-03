#include <vector>
#include <set>
#include <iostream>
using namespace std;

int solution(vector<int> nums){
    int answer = 0;
    int len = nums.size();
    set<int> s(nums.begin(), nums.end());
    answer = min(len / 2, (int)s.size());
    return answer;
}