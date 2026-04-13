#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Connect{
    int a;
    int b;
};

int solution(){
    int n;
    cin >> n;

    vector<Connect> node;
    node.reserve(n);

    for (int i = 0; i < n; i++){
        Connect temp;
        cin >> temp.a >> temp.b;
        node.push_back(temp);
    }

    sort(node.begin(), node.end(), [](const Connect& x, const Connect& y){
        return x.a < y.a;
    });

    // 이제 부터 LIS 알고리즘 적용 올라가는 것만 체크하면 될듯
    // https://chanhuiseok.github.io/posts/algo-49/
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            if (node[i].b > node[j].b){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }

    return n-*max_element(dp.begin(), dp.end());
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << solution() << "\n";
    return 0;
}