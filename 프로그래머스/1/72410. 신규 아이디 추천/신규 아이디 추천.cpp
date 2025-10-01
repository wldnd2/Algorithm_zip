#include <iostream>
#include <string>
#include <vector>
#include <regex> // 정규식 헤더
#include <cmath>
using namespace std;

string solution(string new_id) {
    string answer = "";
    // 1단계
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);

    // 2단계
    // regex pattern("[a-z]\\d\\-\\_\\."); -> 이런 순차적으로 나오는다는 의미
    // 아래와 같이 사용해야지 해당 문자열내에 이러한 문자를 제외하는 패턴으로 적용한다는 의미
    regex pattern("[^a-z\\d\\-_\\.]|");
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
    int i = 0;
    for (char c: new_id){
        if (i == 15) break;
        answer += c;
        i++;
    }
    // 7단계
    regex pattern5("\\.$");
    answer = regex_replace(answer, pattern5, "");

    // 8단계
    if (answer.size() <= 2){
        while(answer.size() != 3){
            answer += answer[answer.size()-1];
        }
    }
    return answer;
}