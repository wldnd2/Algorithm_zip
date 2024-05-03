#include <string>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int solution(string number) {
    int temp = 0;
    for(char i: number) temp += i-'0';
    return temp%9;
}