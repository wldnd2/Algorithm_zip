#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(long long n) {
    int sqrt_num = (int)sqrt(n);
    if (n == pow(sqrt_num,2)) return pow(sqrt_num+1,2);
    else return -1;
}