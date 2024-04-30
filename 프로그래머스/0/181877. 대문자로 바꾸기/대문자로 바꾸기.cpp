#include <string>
#include <algorithm>
#include <cctype>
#include <vector>

using namespace std;

string solution(string myString) {
    transform(myString.begin(), myString.end(), myString.begin(), ::toupper);
    // transform(myString.begin(), myString.end(), myString.begin(), [](char c){return toupper(c);});
    return myString;
}