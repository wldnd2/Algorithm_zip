#include <string>
#include <vector>
#include <cmath>
#define MAX 1000000
using namespace std;

vector<bool> is_prime(MAX, true);

void eratosMake(int n){
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            // i의 배수를 모두 소수가 아닌 것으로 설정
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int solution(int n) {
    int cnt = 0;
    eratosMake(n);
    for (int i = 2; i <= n; i++)
        if (is_prime[i]) cnt++;
    return cnt;
}