#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(int left, int right, int target, const vector<int>& lis){
    int mid;
    while(left<right){
        mid = (left+right)/2;
        if (lis[mid] < target){
            left = mid+1;
        }
        else right = mid;
    }
    return right;
}

int solution(){
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    vector<int> lis(n, 0);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int j = 0;
    lis[0] = arr[0];
    int i = 1;
    while(i<n){
        // 현재 가장 긴 증가수열 뒤에 붙일 수 있으면
        if(lis[j] < arr[i]){
            lis[j+1] = arr[i];
            j++;
        }
        else{
            int pos = binarySearch(0, j, arr[i], lis);
            lis[pos] = arr[i];
        }
        i++;
    }
    return j+1;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << solution() << "\n";
    return 0;
}