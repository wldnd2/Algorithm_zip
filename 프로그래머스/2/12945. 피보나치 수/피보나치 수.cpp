#include <string>
#include <vector>
#define MAX 100000
using namespace std;

int solution(int n) {
    vector<int> answer(MAX, 0);
    answer[1] = 1;
    for (int i  = 2; i <= n; i++){
        answer[i] = (answer[i-1] + answer[i-2]) % 1234567;
    }
    return answer[n];
}