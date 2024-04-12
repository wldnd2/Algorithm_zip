#include <string>
#include <vector>

using namespace std;

string solution(vector<string> str_list, string ex) {
    string result = "";
    for (const string& s : str_list) {
        if (s.find(ex) == string::npos) {
            result += s;
        }
    }
    return result;
}
