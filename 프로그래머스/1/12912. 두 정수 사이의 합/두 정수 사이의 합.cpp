#include <string>
#include <vector>
#include <iostream>
#define swap(a, b) {int tmp=a; a=b; b=tmp;}

using namespace std;

long long solution(int a, int b) {
    if (a == b) return a;
    if (a > b) swap(a,b);
    long long answer = 0;
    for (int i = a; i <= b; i++){
        answer += i;
    }
    return answer;
}