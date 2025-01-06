#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int result = 0;
    vector<int> check(n+1, 1);
    for (int i: reserve) check[i]++;
    for (int i: lost) check[i]--;
    for (int i = 1; i <= n; i++){
       if (check[i] > 1){
            check[i]--;
            if (!check[i-1]) check[i-1]++;
            else if (!check[i+1]) check[i+1]++;
       }
    }
    for (int i = 1; i <= n; i++) if (check[i]) result++;
    return result;
}