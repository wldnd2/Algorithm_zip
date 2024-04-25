#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    string answer = "";
    for(char alpha: myString){
        if(alpha == 'a' || alpha == 'A') answer += toupper(alpha);
        else answer += tolower(alpha);
    }
    return answer;
}