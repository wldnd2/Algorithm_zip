#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> intervals) {
    vector<int> result;
    
    // insert(insert_position, start, end);
    result.insert(result.end(), arr.begin() + intervals[0][0], arr.begin() + intervals[0][1] + 1);
    result.insert(result.end(), arr.begin() + intervals[1][0], arr.begin() + intervals[1][1] + 1);
    
    return result;
}