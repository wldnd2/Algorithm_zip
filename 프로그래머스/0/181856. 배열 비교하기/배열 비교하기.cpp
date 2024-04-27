#include <string>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int solution(vector<int> arr1, vector<int> arr2) {
    int sz1 = arr1.size();
    int sz2 = arr2.size();
    if (sz1 == sz2){
        int sum1 = accumulate(arr1.begin(), arr1.end(),0);
        int sum2 = accumulate(arr2.begin(), arr2.end(),0);
        if (sum1 == sum2) return 0;
        return sum1 > sum2 ? 1 : -1;
    }
    return sz1 > sz2 ? 1 : -1;
}