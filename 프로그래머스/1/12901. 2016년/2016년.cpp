#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int a, int b) {
    int answer = b;
    string day[7] = {"FRI","SAT", "SUN","MON","TUE","WED","THU"};
    int month[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 0; i < a-1; i++){
        answer += month[i];
    }
    return day[(answer-1)%7];
}