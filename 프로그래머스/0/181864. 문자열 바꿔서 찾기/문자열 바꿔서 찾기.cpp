#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    transform(myString.begin(), myString.end(), myString.begin(), [](char c){return 'A'==c ? 'B':'A';});
    return myString.find(pat) == string::npos ? 0 : 1;
}