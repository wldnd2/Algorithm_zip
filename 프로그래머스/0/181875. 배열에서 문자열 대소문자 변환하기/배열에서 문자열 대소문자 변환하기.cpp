#include <string>
#include <cctype>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr) {
    int len = strArr.size();
    for(int i = 0; i < len; i++){
        transform(strArr[i].begin(), strArr[i].end(), strArr[i].begin(), [i](char c){
            return i%2? toupper(c) : tolower(c);
        });
    }
    return strArr;
}