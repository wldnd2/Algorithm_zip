#include <string>
#include <cctype>
#include <algorithm>
#include <vector>

using namespace std;

string solution(string my_string, string alp) {
    transform(my_string.begin(), my_string.end(), my_string.begin(), [alp](char c) {
        return (alp.find(c) != string::npos) ? toupper(c) : c;
    });
    return my_string;
}