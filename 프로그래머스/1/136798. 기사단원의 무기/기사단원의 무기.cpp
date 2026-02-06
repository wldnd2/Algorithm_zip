#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int num_cnt(int num){
    int cnt = 0;
    for (int i = 1; i <= (int)sqrt(num); i++){
        if (num % i == 0) {
            cnt += 1;
            if (i != num/i) cnt += 1;
        }
    }
    return cnt;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    for (int i = 1; i <= number; i++){
        int temp = num_cnt(i);
        if (temp > limit) answer += power;
        else answer += temp;
    }
    return answer;
}