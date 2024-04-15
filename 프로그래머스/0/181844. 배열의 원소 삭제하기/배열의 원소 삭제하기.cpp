#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list) {
    vector<int> answer;
    for(auto item: arr) {
        auto f = find(delete_list.begin(), delete_list.end(), item);
        if (f == delete_list.end()) {
            answer.push_back(item);
        }
    }
    return answer;
}
