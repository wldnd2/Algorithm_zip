#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    while(n >= a){
        int q = n/a*b;
        int r = n%a;
        n = q+r;
        answer += q;
    }
    return answer;
}