#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(int x) {
    int acc = 0, temp = x;
    while(x>10){
        acc += x%10;
        x /= 10;
    }
    acc += x;
    return temp%acc == 0;
}