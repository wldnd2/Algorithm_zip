#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string solution(string my_string, int k) {
    string result = "";
    for (int i=0; i<k; i++) result+=my_string;
    return result;
}