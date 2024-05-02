#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
// #incldue <functional>

using namespace std;

int multi(vector<int> num_list){
    int result = 1;
    for(int num: num_list) result *= num;
    return result;
}

int solution(vector<int> num_list) {
    // return l.size() >= 11 ? accumulate(l.begin(), l.end(), 0) : accumulate(l.begin(), l.end(), 1, multiplies<int>());

    return num_list.size() > 10 ? accumulate(num_list.begin(), num_list.end(), 0): multi(num_list);
}