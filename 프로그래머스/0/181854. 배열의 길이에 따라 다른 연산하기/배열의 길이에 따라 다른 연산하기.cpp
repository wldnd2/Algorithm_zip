#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int n) {
    int len = arr.size();
    int check = len % 2 ? 0 : 1;
    for(int i = check; i < len; i+=2){
        arr[i] += n;
    }
    return arr;
}