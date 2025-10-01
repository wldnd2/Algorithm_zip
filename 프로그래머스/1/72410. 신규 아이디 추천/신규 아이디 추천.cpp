#include <iostream>
#include <string>
#include <vector>
#include <regex> // 정규식 헤더
#include <cmath>
using namespace std;

string solution(string new_id) {
    // 1단계
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);

    // 2단계
    // regex pattern("[a-z]\\d\\-\\_\\."); -> 이런 순차적으로 나오는다는 의미
    // 아래와 같이 사용해야지 해당 문자열내에 이러한 문자를 제외하는 패턴으로 적용한다는 의미
    regex pattern("[^a-z\\d\\-_\\.]");
    new_id = regex_replace(new_id, pattern, "");

    // 3단계
    regex pattern2("(\\.)\\1+");
    new_id = regex_replace(new_id, pattern2, ".");

    // 4단계
    // ^: 시작, $: 끝
    regex pattern3("^\\.|\\.$");
    new_id = regex_replace(new_id, pattern3, "");

    // 5단계
    if (!new_id.size()) new_id += "a";

    // 6단계
    regex pattern4("^\\.|\\.$");
    new_id = regex_replace(new_id, pattern4, "");

    // 7단계
    if (new_id.length() >= 16) {
        new_id = new_id.substr(0, 15);
        regex pattern_5("\\.$");
        new_id = regex_replace(new_id, pattern_5, "");
    }

    // 8단계
    if (new_id.length() <= 2) {
        while (new_id.length() < 3) {
            new_id += new_id.back(); // back()으로 마지막 문자에 쉽게 접근
        }
    }
    return new_id;
}