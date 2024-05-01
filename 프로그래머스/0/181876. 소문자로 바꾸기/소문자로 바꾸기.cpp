#include <string>
#include <algorithm>
#include <cctype>
#include <vector>

using namespace std;

string solution(string myString) {
    transform(myString.begin(), myString.end(), myString.begin(), ::tolower);
    return myString;
}