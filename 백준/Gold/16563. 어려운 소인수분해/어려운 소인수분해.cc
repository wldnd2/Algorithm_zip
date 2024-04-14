#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#define MAX 5000000
using namespace std;

int n;
vector<int> arr;
int erathostenes[MAX+1] = {-1, -1, 0, };

void input(){
    cin >> n;
    arr.resize(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
}

void makeErathos(int num){
    // 자기 자신으로 초기화
    for(int i=2; i<=num; i++) erathostenes[i] = i;
    int sqrtNum = sqrt(num);
    // 2부터 시작해서 i*i부터 시작해서 i의 배수들을 지워준다.
    for (int i=2; i<=sqrtNum; i++){
        //i*i부터 시작하는 이유는 i*i보다 작은 수는 이미 지워졌기 때문
        for (int j=i*i; j<=num; j+=i){
            // 지워지지 않은 수라면 지워준다.
            if(erathostenes[j] == j)
                erathostenes[j] = i;
        }
    }
}

void solve(int num){
    // 알고리즘 : erathostenes[num]를 출력하고 num을 erathostenes[num]으로 나눠준다.
    // erathostenes[num]는 num의 가장 작은 소인수이다.
    // 이를 반복하면 num이 1이 될 때까지 반복하면 된다.
    while (num > 1){
        cout << erathostenes[num] << ' ';
        num /= erathostenes[num];
    }
    cout << '\n';
}

int main(void){
    input();
    makeErathos(MAX);
    for (int i=0; i<n; i++){
        solve(arr[i]);
    }
}
