#include <string>
#include <cctype>
#include <algorithm>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    transform(myString.begin(), myString.end(), myString.begin(), [](unsigned char c){ return tolower(c); });
    transform(pat.begin(), pat.end(), pat.begin(), [](unsigned char c){ return tolower(c); });
    return myString.find(pat) != string::npos ? 1 : 0;
}