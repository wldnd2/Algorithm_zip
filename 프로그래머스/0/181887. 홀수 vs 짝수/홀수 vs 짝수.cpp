#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int even, odd;
    even = odd = 0;
    for(int i = 0; i < num_list.size(); i++){
        if((i+1)%2) odd += num_list[i];
        else even += num_list[i];
    }
    return even > odd ? even : odd;
}