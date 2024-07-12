#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int x) {
    long num = x;
    int cnt = 0;
    while (cnt < 500){
        cout << " " << num;
        if (num == 1) return cnt;
        if (num%2) num = (num*3)+1;
        else num /= 2;
        cnt ++;
    }
    return -1;
}