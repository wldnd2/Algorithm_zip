// https://www.acmicpc.net/problem/2096 내려가기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> data(3, 0);
    vector<int> dp_max(3, 0);
    vector<int> dp_min(3, 0);

    for (int i = 0; i < n; i++) {
        cin >> data[0] >> data[1] >> data[2];

        if (i == 0) {
            for (int j = 0; j < 3; j++) {
                dp_max[j] = data[j];
                dp_min[j] = data[j];
            }
        } else {
            int prev_max0 = dp_max[0], prev_max1 = dp_max[1], prev_max2 = dp_max[2];
            int prev_min0 = dp_min[0], prev_min1 = dp_min[1], prev_min2 = dp_min[2];

            dp_max[0] = data[0] + max(prev_max0, prev_max1);
            dp_max[1] = data[1] + max(prev_max0, max(prev_max1, prev_max2));
            dp_max[2] = data[2] + max(prev_max1, prev_max2);

            dp_min[0] = data[0] + min(prev_min0, prev_min1);
            dp_min[1] = data[1] + min(prev_min0, min(prev_min1, prev_min2));
            dp_min[2] = data[2] + min(prev_min1, prev_min2);
        }
    }

    cout << *max_element(dp_max.begin(), dp_max.end()) << " "
         << *min_element(dp_min.begin(), dp_min.end());
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}